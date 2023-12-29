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

const vector<vector<vector<string>>> GounkiBoard::getBoardState() const {
    vector<vector<vector<string>>> boardState(GOUNKI_BOARD_SIZE, vector<vector<string>>(GOUNKI_BOARD_SIZE));
    for (int i = 0; i < GOUNKI_BOARD_SIZE; i++) {
        for (int j = 0; j < GOUNKI_BOARD_SIZE; j++) {
            string s;
            if (board[i][j].size() == 0) {
                s = UtilityFunctions::getGounkiPieceString(GounkiPieceType::EmptyGounki);
            }
            else {
                s = UtilityFunctions::getGounkiPieceString(((GounkiPiece*) board[i][j][0])->type);
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
    for (const pair<GounkiPieceType, vector<Vector2i>>& pair : GounkiPiece::gounkiMovements) {
        const vector<Vector2i>& movementPattern = pair.second;

        if (find(movementPattern.begin(), movementPattern.end(), diff) != movementPattern.end()) {
            return pair.first;
        }
    }

    return GounkiPieceType::EmptyGounki;
}

void GounkiBoard::makeMove(ActionKey action, int playerIndex, const Vector2i &from, const Vector2i &to) {
    vector<Piece *>& currentCase = board[from.x][from.y];
    vector<Piece *>& nextCase = board[to.x][to.y];

    switch (action) {
        case ActionKey::LeftClick:
            lastDeploymentPiece = nullptr;
            // TODO incrémenter points si pièce mangée
            if (isLandedCaseEnnemy(from, to)) {
                for (int i = nextCase.size() - 1; i >= 0; --i) {
                    if (!nextCase.empty() &&
                        (GounkiPiece *) nextCase.at(i) != nullptr)
                        delete ((GounkiPiece *) nextCase.at(i));
                }
                nextCase.clear();
            }

            for (int i = currentCase.size() - 1; i >= 0; --i) {
                nextCase.push_back(currentCase.at(i));
                currentCase.at(i)->movePiece(to);
            }
            currentCase.clear();
            break;
        case ActionKey::RightClick:
            GounkiPieceType movingPieceType = determinePieceType(from, to);
            vector<Piece *>::iterator it = find_if(currentCase.begin(), currentCase.end(),[this, movingPieceType](Piece *piece) {
                return ((GounkiPiece *) piece)->type == movingPieceType && piece != lastDeploymentPiece;
            });
            if (it == currentCase.end())
                lastDeploymentPiece = nullptr;
            GounkiPiece* newDeploymentPiece = (GounkiPiece*) *it;
            // this case handles the first step of a deployment
            if (lastDeploymentPiece == nullptr) {
                for (int i = currentCase.size() - 1; i >= 0; --i) {
                    nextCase.push_back(currentCase.at(i));
                    currentCase.at(i)->movePiece(to);
                }
                currentCase.clear();
            }
            else {
                // move pieces that are not equal to lastDeploymentPiece
                currentCase.erase(
                        remove_if(currentCase.begin(), currentCase.end(),[this, &nextCase, to](Piece *piece) {
                            if (piece != lastDeploymentPiece) {
                                nextCase.push_back(piece);
                                piece->movePiece(to);
                                return true;
                            }
                            return false;
                        }), currentCase.end());
            }
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

const vector<pair<Vector2i, Vector2i>>
GounkiBoard::validMovesPattern(ActionKey action, const Vector2i &from) const {
    vector<pair<Vector2i, Vector2i>> moves;
    map<GounkiPieceType, int> stackCount;
    const vector<Piece *> &pieces = (board[from.x][from.y]);
    vector<vector<Vector2i>::const_iterator> blockingPatterns;

    if (pieces.empty())
        return moves;

    for (Piece *piece : pieces) {
        // we don't generate moves for pieces that are already deployed
        if (piece != lastDeploymentPiece)
            stackCount[((GounkiPiece *) (piece))->type]++;
    }
    for (const pair<GounkiPieceType, int> &pairs: stackCount) {
        vector<Vector2i> stackPieceMoves = GounkiPiece::gounkiMovements.at(pairs.first);
        for (int i = 1; i <= pairs.second; i++) {
            for (vector<Vector2i>::const_iterator it = stackPieceMoves.begin(); it != stackPieceMoves.end(); it++) {
                Vector2i finalPos = from + (*it * i);
                // when the calculated position is a winning case
                // we stop generating values in this direction
                if (finalPos.x == GOUNKI_BOARD_SIZE &&
                    isWithinBoundsX(finalPos.y)
                    || finalPos.x == -1 && isWithinBoundsX(finalPos.y)) {
                    moves.push_back(make_pair(finalPos, *it));
                    blockingPatterns.push_back(it);
                }
                else {
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
                    // we can't stack more than 3 pieces on the same case
                    // or else the case can be taken if it's not a deployment
                    bool isCaseEnnemy = isLandedCaseEnnemy(from, finalPos);
                    if ((!isCaseEnnemy && board[finalPos.x][finalPos.y].size() < 3)
                        || isCaseEnnemy && action == ActionKey::LeftClick) {
                        pair<Vector2i, Vector2i> pair = make_pair(finalPos,
                                                                  *it);
                        if (find(moves.begin(), moves.end(), pair) ==
                            moves.end())
                            moves.push_back(pair);
                    }
                    // if the move calculated position contains a piece on the board
                    // we stop generating in this direction
                    // we don't add blocking patterns if this is the maximum attainable case
                    if (i != pairs.second &&
                        !board[finalPos.x][finalPos.y].empty()) {
                        blockingPatterns.push_back(it);
                    }
                }
            }
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

// Returns the distance of a movement between the original pos and the calculated pos
int distance(const Vector2i& from, const Vector2i& to) {
    return max(abs(from.x - to.x), abs(from.y - to.y));
}

void GounkiBoard::movesWithinDistance(const Vector2i& from, vector<pair<Vector2i, Vector2i>>& movesWithPattern) const {
    vector<pair<Vector2i, Vector2i>>::iterator newEnd = remove_if(
        movesWithPattern.begin(),
        movesWithPattern.end(),
        [&from](const pair<Vector2i, Vector2i> &p) {
            return distance(from, p.first) > 1;
        }
    );
    movesWithPattern.erase(newEnd, movesWithPattern.end());
}

void GounkiBoard::extractMoves(vector<Vector2i>& moves, const vector<pair<Vector2i, Vector2i>>& movesWithPattern) const {
    moves.clear();
    moves.resize(movesWithPattern.size());

    transform(movesWithPattern.begin(), movesWithPattern.end(), moves.begin(), extractFirstElement);
}

const vector<Vector2i>
GounkiBoard::validMoves(ActionKey action, int playerIndex, const Vector2i& from) const {
    vector<Vector2i> moves;
    vector<pair<Vector2i, Vector2i>> movesWithPattern = validMovesPattern(action, from);
    switch (action) {
        // handles the calculation of a piece's move
        case ActionKey::LeftClick:
            extractMoves(moves, movesWithPattern);
            return moves;
        // handles the calculation of a piece's deployment
        case ActionKey::RightClick:
            // deployment is impossible if there's less than 2 pieces on the case
            if (board[from.x][from.y].size() < 2)
                return moves;

            // removes all positions that are more than 1 case away from original position
            movesWithinDistance(from, movesWithPattern);

            // if we're continuing a deployment
            // we need to follow the last selected piece's pattern (circle or square)
            // else we let the player chose between every movement possible
            extractMoves(moves, movesWithPattern);
            if (lastDeploymentDirection.x == 0 && lastDeploymentDirection.y == 0)
                return moves;
            // TODO vérifier que le land case est pas plein
            // searchs if a move of the same piece type as the last move is possible
            vector<pair<Vector2i, Vector2i>>::iterator it = find_if(movesWithPattern.begin(), movesWithPattern.end(),[this](const pair<Vector2i, Vector2i> &move) {
                return move.second == lastDeploymentDirection;
            });

            // if no moves in the same direction are still possible, we return every remaining move
            if (it == movesWithPattern.end())
                return moves;
            vector<Vector2i> patterns;

            // else we return the only moves possible that matches the last direction
            vector<pair<Vector2i, Vector2i>>::iterator newEnd = remove_if(movesWithPattern.begin(), movesWithPattern.end(),[this](const pair<Vector2i, Vector2i> &move) {
                return move.second != lastDeploymentDirection;
            });
            movesWithPattern.erase(newEnd, movesWithPattern.end());
            extractMoves(moves, movesWithPattern);
            return moves;
    }
    return moves;
}

size_t GounkiBoard::currentDeploymentSize() {
    return currentDeployment.size();
}

GounkiBoard::~GounkiBoard() {
    cout << "Destruction of " << *this << endl;
}

ostream &operator<<(ostream &out, const GounkiBoard &gb) {
    out << "Board: Gounki" << endl;
    return out;
}





