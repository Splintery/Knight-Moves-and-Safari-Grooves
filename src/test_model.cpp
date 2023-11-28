#include <limits>
#include "model/ButinConfig.hpp"
#include "model/Butin.hpp"

void printMoves(const vector<Vector2i>& moves) {
    for (const auto& move : moves) {
        cout << "(" << move.x << ", " << move.y << ")" << endl;
    }
}

int main(void){
    Game *butin = new Butin();
    vector<vector<vector<string>>> tmp = butin->getBoardState();
    vector<string> names;
    names.push_back("lucas");
    names.push_back("yann");
    vector<Vector2i> deleted_pieces;
    deleted_pieces.push_back(Vector2i {1,2});
    deleted_pieces.push_back(Vector2i {1,2});
    deleted_pieces.push_back(Vector2i {3,2});
    deleted_pieces.push_back(Vector2i {2,5});
    deleted_pieces.push_back(Vector2i {5,7});
    ButinConfig t = ButinConfig(names, deleted_pieces);
    // game has no possible moves when the board is not initiliazed with removes pieces
    cout << butin->isGameDone() << endl;
    butin->initializeGame(t);
    cout << butin->isGameDone() << endl;
    butin->makeMove(Vector2i {1, 0}, Vector2i {1, 2});
    UtilityFunctions::printBoard(butin->getBoardState());

    Vector2i from;

    while (1) {
        cout << "Enter the x and y coordinates of a piece to get its valid moves: ";
        cin >> from.x >> from.y;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cerr << "Error" << endl;
            continue;
        }

        // Get the valid moves and print them
        const vector<Vector2i> moves = butin->validMoves(from);
        cout << "Valid moves for piece at (" << from.x << ", " << from.y << "):" << endl;
        printMoves(moves);

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    return 0;
}