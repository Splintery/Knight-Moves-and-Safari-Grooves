#include "ButinBoard.hpp"

bool ButinBoard::isGameDone() const {
    for (const vector<ButinPiece*> &column: board) {
        for (const ButinPiece* bp : column) {
            if (!this->validMoves(bp->getPosition()).empty())
                return false;
        }
    }
    return true;
}

vector<int> calculatePieceDistribution() {
    // default 8x8 ratio for the game Butin
    const int yellow_default_ratio = 34;
    const int red_default_ratio = 20;
    const int black_default_ratio = 10;
    double factor = (double) (BOARD_SIZE * BOARD_SIZE) / 64.0;

    int yellow_ratio = (int) (round(yellow_default_ratio * factor));
    int red_ratio = (int) (round(red_default_ratio * factor));
    int black_ratio = (int) (round(black_default_ratio * factor));
    return {yellow_ratio, red_ratio, black_ratio};
}

void ButinBoard::generateDefaultBoard() {
    vector<int> pieces_ratio = calculatePieceDistribution();
    vector<ButinPieceType> all_pieces;

    all_pieces.insert(all_pieces.end(), pieces_ratio[0], ButinPieceType::Yellow);
    all_pieces.insert(all_pieces.end(), pieces_ratio[1], ButinPieceType::Red);
    all_pieces.insert(all_pieces.end(), pieces_ratio[2], ButinPieceType::Black);

    srand(time(nullptr));
    random_shuffle(all_pieces.begin(), all_pieces.end());

    board.resize(BOARD_SIZE);
    for (auto &row : board) {
        row.resize(BOARD_SIZE, nullptr);
    }

    int count = 0;
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = new ButinPiece(all_pieces[count++], Vector2i {i, j});
        }
    }
}

ButinBoard::ButinBoard() {
    cout << "Construction of " << *this;
    generateDefaultBoard();
}

// TODO jsp si c'est nécessaire de mettre nullptr dedans
void ButinBoard::initializeGame(vector<Vector2i> deleted_pieces) {
    for (Vector2i &v: deleted_pieces) {
        ButinPiece* tmp = board[v.x][v.y];
        board[v.x][v.y] = nullptr;
        if (tmp != nullptr)
            delete tmp;
    }
}

const vector<vector<vector<string>>> ButinBoard::getBoardState() const {
    // initialize a vector of BOARD_SIZE elements of vector<vector<string>> initalized at BOARD_SIZE
    vector<vector<vector<string>>> boardState(BOARD_SIZE, vector<vector<string>>(BOARD_SIZE));

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            string s;
            if (board[i][j] == nullptr) {
                s = UtilityFunctions::getButinPieceString(ButinPieceType::EmptyButin);
            }
            else {
                s = UtilityFunctions::getButinPieceString(board[i][j]->color);
            }
            boardState[i][j].push_back(s);
        }
    }
    return boardState;
}

void ButinBoard::makeMove(const Vector2i &from, const Vector2i &to) {
    board[to.x][to.y] = board[from.x][from.y];
    board[from.x][from.y]->movePiece(to);
    board[from.x][from.y] = nullptr;
}

bool ButinBoard::isWithinBounds(Vector2i pos) const {
    return (pos.x >= 0 && pos.x < BOARD_SIZE && pos.y >= 0 && pos.y < BOARD_SIZE);
}

const vector<Vector2i> ButinBoard::validMoves(const Vector2i &from) const {
    vector<Vector2i> moves;
    ButinPiece* piece = board[from.x][from.y];

    if (piece == nullptr || piece->color != ButinPieceType::Yellow)
        return moves;

    vector<Vector2i> patterns = piece->getMovementPatterns();
    for (const Vector2i &pattern : patterns) {
        // position of the jumped piece
        Vector2i midPos = from + (pattern / 2);
        Vector2i endPos = from + pattern;

        if (isWithinBounds(midPos) && isWithinBounds(endPos)) {
            // checks that the jumped piece is existing, and that the endposition is empty
            if (board[midPos.x][midPos.y] != nullptr && board[endPos.x][endPos.y] == nullptr)
                moves.push_back(endPos);
        }
    }
    return moves;
}

ButinBoard::~ButinBoard() {
    cout << "Destruction of " << *this;
}

ostream &operator<<(ostream &o, const ButinBoard &) {
    o << "Board: Butin" << endl;
    return o;
}

