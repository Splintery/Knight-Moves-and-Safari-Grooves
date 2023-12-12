#include "SafariBoard.hpp"
#include "../settings/SETTINGS.hpp"

#include <cmath>

SafariBoard::SafariBoard() {
    // Making the Board a BUTIN_BOARD_SIZE x BUTIN_BOARD_SIZE of nullptr
    board.resize(BUTIN_BOARD_SIZE);
    for (vector<vector<Piece *>> &column : board) {
        column.resize(BUTIN_BOARD_SIZE);
    }
    for (size_t x = 0; x < board.size(); x++) {
        for (size_t y = 0; y < board[x].size(); y++) {
            board[x][y].push_back(new SafariPiece(SafariPieceType::EmptySafari, Vector2i(x, y)));
        }
    }

    cout << "Construction of " << *this << endl;
}
SafariBoard::~SafariBoard() {
    cout << "destruction of " << *this << endl;
}
bool SafariBoard::isGameDone() const {
    return false;
}
const vector<vector<vector<string>>> SafariBoard::getBoardState() const {
    // initialize a vector of BUTIN_BOARD_SIZE elements of vector<vector<string>> initalized at BUTIN_BOARD_SIZE
    vector<vector<vector<string>>> boardState(SAFARI_BOARD_SIZE, vector<vector<string>>(SAFARI_BOARD_SIZE));
    for (int i = 0; i < SAFARI_BOARD_SIZE; i++) {
        for (int j = 0; j < SAFARI_BOARD_SIZE; j++) {
            string s;
            if (board[i][j][0] == nullptr) {
                s = UtilityFunctions::getSafariPieceString(SafariPieceType::EmptySafari);
            }
            else {
                s = UtilityFunctions::getSafariPieceString(
                ((SafariPiece *) board[i][j][0]) -> animal
                );
            }
            boardState[i][j].push_back(s);
        }
    }
    return boardState;
}
void SafariBoard::makeMove(const Vector2i &from, const Vector2i &to, const int playerIndex) {

}
const vector<Vector2i> SafariBoard::validMoves(const Vector2i &from, const int playerIndex) const {
    cout << "tmp\n";
    vector<Vector2i> moves;
    SafariPiece* piece = (SafariPiece *)board[from.x][from.y][0];
    // Permet de vérifier que la case clické n'est pas vide
    if (piece == nullptr) {
        return moves;
    }
    cout << "yeah" << endl;
    // Permet de vérifier que la Piece selectionné est un animal et qu'elle appartient
    // au joueur dont c'est le tour
    switch (piece -> animal) {
        case SafariPieceType::Crocodile:
            if (playerIndex == 0) {
                return moves;
            }
            break;
        case SafariPieceType::Elephant:
            if (playerIndex == 1) {
                return moves;
            }
            break;
        case SafariPieceType::Lion:
            if (playerIndex == 2) {
                return moves;
            }
            break;
        default:
            return moves;
    }

    cout << "player checks out\n";
    vector<Vector2i> patterns = piece -> getMovementPatterns();
    bool noFence = true;
    for (const Vector2i &pattern : patterns) {
        Vector2i endPos = from + pattern;


        if (isWithinBounds(endPos)) {
            cout << "endPos is within Bounds" << endl;
            if (board[endPos.x][endPos.y][0] == nullptr) {
                // Multiplier will change the sign of x and y to be able to check
                // every Tile from "from" to "endPos" in a straight line
                int xMultiplier = (endPos.x < 0) ? -1:1;
                int yMultiplier = (endPos.y < 0) ? -1:1;
                int x = sqrt(pow(endPos.x - from.x, 2));
                int y = sqrt(pow(endPos.y - from.y, 2));
                // On déplace "from" d'une distance de 1 en direction de "endPos"
                // Et on s'arrête:
                //      soit lorsque l'on rencontre une Fence
                //      soit lorsque l'on est arrivé à endPos

                while (x > 0 && y > 0) {
                    if (((SafariPiece *) board[from.x + x * xMultiplier][from.y + y * yMultiplier][0]) -> animal == SafariPieceType::Fence) {
                        noFence = false;
                        break;
                    } else {
                        x--;
                        y--;
                    }
                }
                if (noFence) {
                    patterns.push_back(endPos);
                }
            }
        }
    }
    return moves;
}
bool SafariBoard::isWithinBounds(Vector2i pos) const {
    return (pos.x >= 0 && pos.x < SAFARI_BOARD_SIZE && pos.y >= 0 && pos.y < SAFARI_BOARD_SIZE);
}

void SafariBoard::initializeGame(const vector<Vector2i> crocodiles, const vector<Vector2i> elephants, const vector<Vector2i> lions, vector<Vector2i> fences) {

    // Making the Board a BUTIN_BOARD_SIZE x BUTIN_BOARD_SIZE of nullptr
    board.resize(BUTIN_BOARD_SIZE);
    for (vector<vector<Piece *>> &column : board) {
        column.resize(BUTIN_BOARD_SIZE);
    }

    for (Vector2i crocPos : crocodiles) {
        board[crocPos.x][crocPos.y].push_back(new SafariPiece(SafariPieceType::Crocodile, crocPos));
    }
    for (Vector2i elePos : elephants) {
        board[elePos.x][elePos.y].push_back(new SafariPiece(SafariPieceType::Elephant, elePos));
    }
    for (Vector2i lioPos : lions) {
        board[lioPos.x][lioPos.y].push_back(new SafariPiece(SafariPieceType::Lion, lioPos));
    }
    for (Vector2i fenPos : fences) {
        board[fenPos.x][fenPos.y].push_back(new SafariPiece(SafariPieceType::Fence, fenPos));
    }
}

ostream &operator<<(ostream &out, const SafariBoard &) {
    out << "Board: Safari" << endl;
    return out;
}