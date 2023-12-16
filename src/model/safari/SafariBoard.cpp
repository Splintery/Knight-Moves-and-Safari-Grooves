#include "SafariBoard.hpp"
#include "../../settings/SETTINGS.hpp"

#include <cmath>
#include <memory>

// TODO ne pas créer d'objet vide et juste stocker un nullptr
SafariBoard::SafariBoard(): tilesToCapture{8} {
    // Making the Board a SAFARI_BOARD_SIZE x SAFARI_BOARD_SIZE of EmptySafari
    board.resize(SAFARI_BOARD_SIZE);
    for (vector<vector<Piece *>> &column : board) {
        column.resize(SAFARI_BOARD_SIZE);
    }
    for (int x = 0; x < (int) board.size(); x++) {
        for (int y = 0; y < (int) board[x].size(); y++) {
            board[x][y].push_back(new SafariPiece(SafariPieceType::EmptySafari, Vector2i(x, y)));
        }
    }
    cout << "Construction of " << *this << endl;
}

bool SafariBoard::isCaptured(const SafariPiece *piece) const {
    unique_ptr<vector<vector<bool>>> mark(new vector<vector<bool>>(SAFARI_BOARD_SIZE));

    for (auto &v : *mark) {
        for (int j = 0; j < SAFARI_BOARD_SIZE; j++) {
            v.push_back(false);
        }
    }
    return getAccessibleTiles(piece -> getPosition(), piece -> getMovementPatterns(), mark.get()) > tilesToCapture;
}
int SafariBoard::getAccessibleTiles(const Vector2i &from, const vector<Vector2i> &patterns, vector<vector<bool>> *mark) const {
    (*mark)[from.x][from.y] = true;
    int res = 1;
    vector<Vector2i> moves = getPositionFromPatterns(from, patterns);
    for (Vector2i pos : moves) {
        if (!(*mark)[pos.x][pos.y]) {
            res += getAccessibleTiles(pos, patterns, mark);
            return res;
        }
    }
    return res;
}
vector<Vector2i> SafariBoard::getPositionFromPatterns(const Vector2i &from, const vector<Vector2i> &patterns) const {
    vector<Vector2i> moves;
    bool noFence;
    for (const Vector2i &pattern : patterns) {
        Vector2i endPos = from + pattern;
        noFence = true;

        if (isWithinBounds(endPos)) {
            if (((SafariPiece *)board[endPos.x][endPos.y][0]) -> animal == SafariPieceType::EmptySafari) {
                // Multiplier will change the sign of x and y to be able to check
                // every Tile from "from" to "endPos" in a straight line
                int xMultiplier = (endPos.x < from.x) ? -1:1;
                int yMultiplier = (endPos.y < from.y) ? -1:1;
                int x = (int) sqrt(pow(endPos.x - from.x, 2)) - 1;
                int y = (int) sqrt(pow(endPos.y - from.y, 2)) - 1;
                // On déplace "from" d'une distance de 1 en direction de "endPos"
                // Et on s'arrête:
                //      soit lorsque l'on rencontre une Fence
                //      soit lorsque l'on est arrivé à endPos

                while (x > 0) {
                    if (((SafariPiece *) board[from.x + x * xMultiplier][from.y][0]) -> animal == SafariPieceType::Fence) {
                        noFence = false;
                    }
                    x -= 2;
                }
                while (y > 0) {
                    if (((SafariPiece *) board[from.x][from.y + y * yMultiplier][0]) -> animal == SafariPieceType::Fence) {
                        noFence = false;
                    }
                    y -= 2;
                }
                if (noFence) {
                    moves.push_back(endPos);
                }
            }
        }
    }
    return moves;
}
bool SafariBoard::isGameDone() const {
    int crocodileCaptured = 0;
    int elephantCaptured = 0;
    int lionCaptured = 0;
    for (const vector<vector<Piece *>> &column : board) {
        for (const vector<Piece *> &line : column) {
            for (Piece *p : line) {
                SafariPiece *sp = ((SafariPiece *) p);
                if (sp -> animal != SafariPieceType::EmptySafari && sp -> animal != SafariPieceType::Fence) {
                    if (isCaptured(sp)) {
                        switch (sp -> animal) {
                            case SafariPieceType::Crocodile:
                                crocodileCaptured++;
                                break;
                            case SafariPieceType::Elephant:
                                elephantCaptured++;
                                break;
                            case SafariPieceType::Lion:
                                lionCaptured++;
                                break;
                            default:
                                break;
                        }
                    }
                }
            }
        }
    }
    // For this game, it is considered to be finished if there is only one species of animal not captured on the board
    // Or it is a tie if all the animals got captured
    return (crocodileCaptured == ANIMALS_PER_PLAYER && elephantCaptured == ANIMALS_PER_PLAYER && lionCaptured < ANIMALS_PER_PLAYER)
        || (crocodileCaptured == ANIMALS_PER_PLAYER && elephantCaptured < ANIMALS_PER_PLAYER && lionCaptured == ANIMALS_PER_PLAYER)
        || (crocodileCaptured < ANIMALS_PER_PLAYER && elephantCaptured == ANIMALS_PER_PLAYER && lionCaptured == ANIMALS_PER_PLAYER)
        || (crocodileCaptured == ANIMALS_PER_PLAYER && elephantCaptured == ANIMALS_PER_PLAYER && lionCaptured == ANIMALS_PER_PLAYER);
}
void SafariBoard::initializeGame(const GameConfig& gc) {
    auto& sc = (SafariConfig&) gc;

    for (Vector2i crocPos : sc.crocodiles) {
        board[crocPos.x][crocPos.y].push_back(new SafariPiece(SafariPieceType::Crocodile, crocPos));
    }
    for (Vector2i elePos : sc.elephants) {
        board[elePos.x][elePos.y].push_back(new SafariPiece(SafariPieceType::Elephant, elePos));
    }
    for (Vector2i lioPos : sc.lions) {
        board[lioPos.x][lioPos.y].push_back(new SafariPiece(SafariPieceType::Lion, lioPos));
    }
    for (Vector2i fenPos : sc.fences) {
        board[fenPos.x][fenPos.y].push_back(new SafariPiece(SafariPieceType::Fence, fenPos));
    }
}
const vector<vector<vector<string>>> SafariBoard::getBoardState() const {
    // initialize a vector of SAFARI_BOARD_SIZE elements of vector<vector<string>> initalized at SAFARI_BOARD_SIZE
    vector<vector<vector<string>>> boardState(SAFARI_BOARD_SIZE, vector<vector<string>>(SAFARI_BOARD_SIZE));
    for (int i = 0; i < SAFARI_BOARD_SIZE; i++) {
        for (int j = 0; j < SAFARI_BOARD_SIZE; j++) {
            boardState[i][j].push_back(
                UtilityFunctions::getSafariPieceString(((SafariPiece *) board[i][j][0]) -> animal)
            );
        }
    }
    return boardState;
}
// In order to place a fence only "from" is necessary hence why we have a default value for "to"
// it makes it cleaner in the View of Safari
void SafariBoard::makeMove(ActionKey action, const int playerIndex, const Vector2i &from, const Vector2i &to = Vector2i(0, 0)) {
    SafariPiece *fromPiece;
    SafariPiece *toPiece;
    SafariPiece *newFence;
    switch (action) {
        // Left-click = move animal
        case ActionKey::LeftClick:
            fromPiece = (SafariPiece *) board[from.x][from.y][0];
            toPiece = (SafariPiece *) board[to.x][to.y][0];
            board[to.x][to.y][0] = fromPiece;
            board[from.x][from.y][0] = toPiece;
            break;
        // Right-click = place Fence
        case ActionKey::RightClick:
            newFence = new SafariPiece(SafariPieceType::Fence, Vector2i(from.x, from.y));
            delete(board[from.x][from.y][0]);
            board[from.x][from.y][0] = newFence;
            break;
        default:
            break;
    }
}
const vector<Vector2i> SafariBoard::validMoves(const Vector2i &from, const int playerIndex) const {
    vector<Vector2i> moves;
    auto* piece = (SafariPiece *)board[from.x][from.y][0];
    // Permet de vérifier que la case clické n'est pas vide
    if (piece == nullptr) {
        return moves;
    }
    // Permet de vérifier que la Piece selectionné est un animal et qu'elle appartient
    // au joueur dont c'est le tour
    switch (piece -> animal) {
        case SafariPieceType::Crocodile:
            if (playerIndex != 0) {
                return moves;
            }
            break;
        case SafariPieceType::Elephant:
            if (playerIndex != 1) {
                return moves;
            }
            break;
        case SafariPieceType::Lion:
            if (playerIndex != 2) {
                return moves;
            }
            break;
        default:
            return moves;
    }

    moves = getPositionFromPatterns(from, piece -> getMovementPatterns());
    return moves;

}
bool SafariBoard::isWithinBounds(Vector2i pos) const {
    return (pos.x >= 0 && pos.x < SAFARI_BOARD_SIZE && pos.y >= 0 && pos.y < SAFARI_BOARD_SIZE);
}

SafariBoard::~SafariBoard() {
    cout << "destruction of " << *this << endl;
}

ostream &operator<<(ostream &out, const SafariBoard &) {
    out << "Board: Safari" << endl;
    return out;
}