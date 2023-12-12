#include "SafariPiece.hpp"
#include "SafariBoard.hpp"


int main() {
    SafariPiece *sp = new SafariPiece(SafariPieceType::Lion, Vector2i(7, 7));
//    for (Vector2i v : sp -> getMovementPatterns()) {
//        cout << "[" << v.x << ", " << v.y << "]" << endl;
//    }
    vector<Vector2i> cro;
    vector<Vector2i> ele;
    vector<Vector2i> lio;
    lio.push_back(sp -> getPosition());
    vector<Vector2i> fen;

    SafariBoard *sb = new SafariBoard();
    sb -> initializeGame(
         cro, ele, lio, fen
    );
    cout << sb -> board.size() << endl;
    sb -> board[7][7][0] -> movePiece(sp -> getPosition());

    cout << "Moves Possible :" << endl;


    for (Vector2i v : sb -> validMoves(sp -> getPosition(), 3)) {
        cout << "\t[" << v.x << ", " << v.y << "]" << endl;
    }
    return EXIT_SUCCESS;
}