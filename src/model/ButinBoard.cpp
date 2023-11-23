#include "ButinBoard.hpp"

vector<int> calculatePieceDistribution() {
        // default 8x8 ratio for the game Butin
        const int yellow_default_ratio = 34;
        const int red_default_ratio = 20;
        const int black_default_ratio = 10;
        double factor = (double)(BOARD_SIZE * BOARD_SIZE) / 64.0;

        int yellow_ratio = (int)(round(yellow_default_ratio * factor));
        int red_ratio = (int)(round(red_default_ratio * factor));
        int black_ratio = (int)(round(black_default_ratio * factor));
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
            board.at(i).at(j) = new ButinPiece(all_pieces[count++], Vector2i {i, j});
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
        ButinPiece* tmp = board.at(v.x).at(v.y);
        board.at(v.x).at(v.y) = nullptr;
        delete tmp;
    }
}

void ButinBoard::isValidMove(const Vector2i &from, const Vector2i &to) const {

}

const vector<vector<string>> ButinBoard::getBoardState() const {
    vector<vector<string>> boardState;
    // boardState.resize(BOARD_SIZE);
    // for (auto &row : boardState) {
    //     row.resize(BOARD_SIZE, "");
    // }
    // string s;

    // for (int i = 0; i < BOARD_SIZE; i++) {
    //     for (int j = 0; j < BOARD_SIZE; j++) {
    //         if (board[i][j] == nullptr) {
    //             s = UtilityFunctions::getButinPieceString(ButinPieceType::EmptyButin);
    //         }
    //         else {
    //             s = UtilityFunctions::getButinPieceString(board[i][j]->color);
    //         }
    //         boardState.at(i).at(j) = s;
    //     }
    // }
    return boardState;
}

ButinBoard::~ButinBoard() {
    cout << "Destruction of " << *this;
}

ostream &operator<<(ostream &o, const ButinBoard &) {
    o << "Board: Butin" << endl;
    return o;
}
