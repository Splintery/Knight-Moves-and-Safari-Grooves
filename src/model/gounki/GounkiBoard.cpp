#include "GounkiBoard.hpp"

GounkiBoard::GounkiBoard() {
    board.resize(GOUNKI_BOARD_SIZE);
    for (vector<vector<Piece *>> &column : board) {
        column.resize(GOUNKI_BOARD_SIZE);
    }
    generateDefaultBoard();
    cout << "Construction of " << *this;
}

void GounkiBoard::generateDefaultBoard() {
    for (int i = 0; i < GOUNKI_BOARD_SIZE; ++i) {
        board[0][i].push_back(new GounkiPiece(
                i % 2 == 0 ? GounkiPieceType::BlackCircle : GounkiPieceType::BlackSquare,
                Vector2i{0, i}));
        board[1][i].push_back(new GounkiPiece(
                i % 2 == 0 ? GounkiPieceType::BlackSquare : GounkiPieceType::BlackCircle,
                Vector2i{1, i}));
        board[GOUNKI_BOARD_SIZE - 2][i].push_back(new GounkiPiece(
                i % 2 == 0 ? GounkiPieceType::WhiteCircle : GounkiPieceType::WhiteSquare,
                Vector2i{GOUNKI_BOARD_SIZE - 1, i}));
        board[GOUNKI_BOARD_SIZE - 1][i].push_back(new GounkiPiece(
                i % 2 == 0 ? GounkiPieceType::WhiteSquare : GounkiPieceType::WhiteCircle,
                Vector2i{GOUNKI_BOARD_SIZE - 2, i}));
    }
}

bool GounkiBoard::isGameDone() const {
    return gameDone;
}

void GounkiBoard::initializeGame(const GameConfig &) {}

vector<vector<vector<string>>> GounkiBoard::getBoardState() const {
    vector<vector<vector<string>>> boardState(GOUNKI_BOARD_SIZE, vector<vector<string>>(GOUNKI_BOARD_SIZE));
    for (int i = 0; i < GOUNKI_BOARD_SIZE; i++) {
        for (int j = 0; j < GOUNKI_BOARD_SIZE; j++) {
            string s;
            if (board[i][j].size() == 0) {
                s = UtilityFunctions::getGounkiPieceString(GounkiPieceType::EmptyGounki);
            }
            else {
                for (Piece* p : board[i][j]) {
                    s = UtilityFunctions::getGounkiPieceString(((GounkiPiece*) p)->type);
                }
            }
            boardState[i][j].push_back(s);
        }
    }
    return boardState;
}

bool GounkiBoard::isLandedCaseEnnemy(const Vector2i& from, const Vector2i& to) const{
    const vector<Piece*>& currentCase = board[from.x][from.y];
    const vector<Piece*>& nextCase = board[to.x][to.y];
    if (nextCase.empty())
        return false;

    GounkiPiece* currentPiece = (GounkiPiece*)currentCase[0];
    GounkiPiece* nextPiece = (GounkiPiece*)nextCase[0];
    switch (currentPiece->type) {
        case GounkiPieceType::BlackCircle:
        case GounkiPieceType::BlackSquare:
            return (nextPiece->type == GounkiPieceType::WhiteSquare
            || nextPiece->type == GounkiPieceType::WhiteCircle);
        case GounkiPieceType::WhiteCircle:
        case GounkiPieceType::WhiteSquare:
             return (nextPiece->type == GounkiPieceType::BlackSquare
             || nextPiece->type == GounkiPieceType::BlackCircle);
        default:
            return false;
    }
}

GounkiPieceType GounkiBoard::determinePieceType(const Vector2i& from, const Vector2i& to) const {
    Vector2i diff = to - from;

    // iterate through each piece type and its movement patterns
    for (const pair<const GounkiPieceType, vector<Vector2i>>& pair : GounkiPiece::gounkiMovements) {
        const vector<Vector2i>& movementPattern = pair.second;

        if (find(movementPattern.begin(), movementPattern.end(), diff)
        != movementPattern.end()) {
            return pair.first;
        }
    }

    return GounkiPieceType::EmptyGounki;
}

void GounkiBoard::makeMove(ActionKey action, int playerIndex, const Vector2i &from, const Vector2i &to) {
    vector<Piece *>& currentCase = board[from.x][from.y];
    vector<Piece *>& nextCase = board[to.x][to.y];

    if (isWinningPosition(to)) {
        gameDone = true;
        winningPlayer = playerIndex;
    }
    switch (action) {
        case ActionKey::LeftClick:
            lastDeploymentPiece = nullptr;
            // if the move eats enemy pieces we delete each piece on the case
            if (isLandedCaseEnnemy(from, to)) {
                for (int i = nextCase.size() - 1; i >= 0; --i) {
                    if (!nextCase.empty() && (GounkiPiece *) nextCase.at(i) != nullptr)
                        delete ((GounkiPiece *) nextCase.at(i));
                }
                nextCase.clear();
            }

            // each piece from the original case are moved to the new case
            for (int i = currentCase.size() - 1; i >= 0; --i) {
                nextCase.push_back(currentCase.at(i));
                currentCase.at(i)->movePiece(to);
            }
            currentCase.clear();
            break;
        case ActionKey::RightClick:
            GounkiPieceType movingPieceType = determinePieceType(from, to);
            // we search for a piece with the same type has the last deployment piece
            vector<Piece *>::iterator it = find_if(currentCase.begin(), currentCase.end(),[this, movingPieceType](Piece *piece) {
                return ((GounkiPiece *) piece)->type == movingPieceType && piece != lastDeploymentPiece;
            });
            GounkiPiece* newDeploymentPiece = (GounkiPiece*) *it;
            // this case handles the first step of a deployment
            if (lastDeploymentPiece == nullptr) {
                for (int i = currentCase.size() - 1; i >= 0; --i) {
                    nextCase.push_back(currentCase.at(i));
                    currentDeployment.push_back((GounkiPiece*) currentCase.at(i));
                    currentCase.at(i)->movePiece(to);
                }
                currentCase.clear();
            }
            else {
                // move pieces that are not equal to lastDeploymentPiece
                for (GounkiPiece* gp : currentDeployment) {
                    if (gp != lastDeploymentPiece) {
                        nextCase.push_back(gp);
                        currentCase.erase(find(currentCase.begin(), currentCase.end(), gp));
                        gp->movePiece(to);
                    }
                }
            }
            currentDeployment.erase(find(currentDeployment.begin(), currentDeployment.end(), newDeploymentPiece));
            lastDeploymentPiece = newDeploymentPiece;
            lastDeploymentDirection = to - from;
    }
}

bool isWithinBoundsX(int x) {
    return (x >= 0 && x < GOUNKI_BOARD_SIZE);
}

bool GounkiBoard::isWithinBounds(Vector2i pos) const {
    return (isWithinBoundsX(pos.x) && isWithinBoundsX(pos.y));
}

Vector2i GounkiBoard::handleRebounds(vector<Vector2i>::const_iterator it, Vector2i finalPos) const {
    Vector2i newDir = *it;
    if (!isWithinBounds(finalPos)) {
        if (!isWithinBoundsX(finalPos.x))
            newDir.x = -newDir.x;
        if (!isWithinBoundsX(finalPos.y))
            newDir.y = -newDir.y;
        int j = 0;
        while (!isWithinBounds(finalPos)) {
            finalPos -= *it;
            j++;
        }
        while (j != 0) {
            finalPos += newDir;
            j--;
        }
    }
    return finalPos;
}

map<GounkiPieceType, int> GounkiBoard::calculatePieceDistribution(ActionKey action, const Vector2i &from) const {
    map<GounkiPieceType, int> stackCount;
    const vector<Piece *>& pieces = board[from.x][from.y];

    for (Piece* piece : pieces) {
        if (action == ActionKey::LeftClick) {
            stackCount[((GounkiPiece *) (piece))->type]++;
        }
        // we only generate moves for pieces that are currently deploying
        // this prevents generating moves for pieces stacking during deployment
        else if (action == ActionKey::RightClick) {
            if (currentDeployment.size() == 0
            || find(currentDeployment.begin(), currentDeployment.end(), piece) != currentDeployment.end()) {
                stackCount[((GounkiPiece *) (piece))->type]++;
            }
        }
    }
    return stackCount;
}

bool GounkiBoard::isWinningPosition(const Vector2i& position) const {
    return (position.x == GOUNKI_BOARD_SIZE || position.x == -1) && isWithinBoundsX(position.y);
}

bool GounkiBoard::isNextCaseTakeable(ActionKey action, const Vector2i &from, const Vector2i &to) const {
    // we can't stack more than 3 pieces on the same case
    // or else the case can be taken if it's not a deployment
    bool isCaseEnnemy = isLandedCaseEnnemy(from, to);
    size_t currentCaseSize = board[from.x][from.y].size();
    size_t nextCaseSize = board[to.x][to.y].size();
    bool isEnnemyCaseFull = (!isCaseEnnemy &&
            ((action == ActionKey::LeftClick && (currentCaseSize + nextCaseSize) <= 3)
            || (action == ActionKey::RightClick && nextCaseSize <= 3)));
    bool isNextCaseTakeable = isCaseEnnemy && action == ActionKey::LeftClick;
    return isEnnemyCaseFull || isNextCaseTakeable;
}

int setMaximumRange(ActionKey action, int defaultRange) {
    // we don't generate positions of distance more than 1 case away for deployments
    if (action == ActionKey::RightClick) {
        return 1;
    }
    return defaultRange;
}

vector<pair<Vector2i, Vector2i>>
GounkiBoard::validMovesPattern(ActionKey action, const Vector2i &from) const {
    vector<pair<Vector2i, Vector2i>> moves;
    if (board[from.x][from.y].empty())
        return moves;

    int range;
    vector<vector<Vector2i>::const_iterator> blockingPatterns;
    // this maps holds each piece type and it's number of occurences of the original case
    map<GounkiPieceType, int> stackCount = calculatePieceDistribution(action, from);
    for (const pair<const GounkiPieceType, int>& pairs: stackCount) {
        vector<Vector2i> stackPieceMoves = GounkiPiece::gounkiMovements.at(pairs.first);
        range = setMaximumRange(action, pairs.second);
        for (int i = 1; i <= range; i++) {
            for (vector<Vector2i>::const_iterator it = stackPieceMoves.begin(); it != stackPieceMoves.end(); it++) {
                Vector2i finalPos = from + (*it * i);
                // when the calculated position is a winning case
                // we stop generating values in this direction
                if (isWinningPosition(finalPos)) {
                    moves.emplace_back(make_pair(finalPos, *it));
                    blockingPatterns.push_back(it);
                }
                else {
                    finalPos = handleRebounds(it, finalPos);
                    if (isNextCaseTakeable(action, from, finalPos)) {
                        moves.emplace_back(make_pair(finalPos,*it));
                    }
                    // if the move calculated position contains a piece on the board
                    // we stop generating in this direction
                    // we don't add blocking patterns if this is the maximum attainable case
                    // TODO Maybe pairs.second et pas range si un truc marche pas mdr
                    if (i != range && !board[finalPos.x][finalPos.y].empty()) {
                        blockingPatterns.push_back(it);
                    }
                }
            }
            // removes the blocking patterns to not generate them at the next iteration
            for (vector<Vector2i>::const_iterator it: blockingPatterns) {
                stackPieceMoves.erase(it);
            }
            blockingPatterns.clear();
        }
    }
    return moves;
}

auto extractFirstElement = [](const pair<Vector2i, Vector2i>& pair) {
    return pair.first;
};

void extractMoves(vector<Vector2i>& moves, const vector<pair<Vector2i, Vector2i>>& movesWithPattern) {
    moves.clear();
    moves.resize(movesWithPattern.size());

    transform(movesWithPattern.begin(), movesWithPattern.end(), moves.begin(), extractFirstElement);
}

void filterUniqueFirst(vector<pair<Vector2i, Vector2i>>& movesWithPattern) {
    sort(movesWithPattern.begin(), movesWithPattern.end(),
         [](const pair<Vector2i, Vector2i> &a, const pair<Vector2i, Vector2i> &b) {
        return a.first.x < b.first.x || (a.first.x == b.first.x && a.first.y < b.first.y);
    });

    movesWithPattern.erase(
            unique(movesWithPattern.begin(), movesWithPattern.end(),[](const pair<Vector2i, Vector2i> &a, const pair<Vector2i, Vector2i> &b) {
                return a.first.x == b.first.x && a.first.y == b.first.y;
            }),movesWithPattern.end()
            );
}

vector<Vector2i> GounkiBoard::validMoves(ActionKey action, int playerIndex, const Vector2i& from) const {
    vector<Vector2i> moves;
    vector<pair<Vector2i, Vector2i>> movesWithPattern = validMovesPattern(action, from);
    switch (action) {
        // handles the calculation of a piece's move
        case ActionKey::LeftClick:
            filterUniqueFirst(movesWithPattern);
            extractMoves(moves, movesWithPattern);
            return moves;
        // handles the calculation of a piece's deployment
        case ActionKey::RightClick:
            // deployment is impossible if there's less than 2 pieces on the case
            if (board[from.x][from.y].size() < 2)
                return moves;

            // we search for every calculated moves that correspond to the last deployment's pattern
            vector<pair<Vector2i, Vector2i>>::iterator newEnd = remove_if(movesWithPattern.begin(), movesWithPattern.end(),[this](const pair<Vector2i, Vector2i> &move) {
                return move.second != lastDeploymentDirection;
            });
            // if no moves correspond to the last deployment direction
            // we return the list of all the moves possible
            // this handles the case of a first deployment and
            // the case were no more pieces of the same type needed are available
            if (newEnd != movesWithPattern.begin())
                movesWithPattern.erase(newEnd, movesWithPattern.end());
            filterUniqueFirst(movesWithPattern);
            extractMoves(moves, movesWithPattern);
            return moves;
    }
    return moves;
}

void GounkiBoard::clearDeploymentStatus() {
    lastDeploymentDirection = Vector2i {0, 0};
    lastDeploymentPiece = nullptr;
    currentDeployment.clear();
}

size_t GounkiBoard::currentDeploymentSize() const {
    return currentDeployment.size();
}

int GounkiBoard::getWinnerIndex() const {
    return winningPlayer;
}

int GounkiBoard::getCaseSize(const Vector2i &pos) const {
    return board[pos.x][pos.y].size();
}

GounkiBoard::~GounkiBoard() {
    // todo supprimer chaque pièce
    cout << "Destruction of " << *this << endl;
}

ostream &operator<<(ostream &out, const GounkiBoard &) {
    out << "Board: Gounki" << endl;
    return out;
}