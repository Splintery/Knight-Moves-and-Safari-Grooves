#include "SafariPiece.hpp"
#include "SafariBoard.hpp"


int main() {
    SafariPiece *sp = new SafariPiece(SafariPieceType::Lion, Vector2i(0, 0));

    vector<Vector2i> cro;
    vector<Vector2i> ele;
    vector<Vector2i> lio;
    lio.push_back(sp -> getPosition());
    vector<Vector2i> fen;

    SafariBoard *sb = new SafariBoard();

    cout << sb -> board.size() << endl;
    vector<Piece *> vp;
    vp.push_back(sp);
    sb -> board[0][0] = vp;
    sb -> board[0][0][0] -> movePiece(sp -> getPosition());

    cout << "Moves Possible :" << endl;

    for (Vector2i v : sb -> validMoves(sp -> getPosition(), 2)) {
        cout << "\t[" << v.x << ", " << v.y << "]" << endl;
    }
    return EXIT_SUCCESS;
}