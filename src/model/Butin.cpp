#include "Butin.hpp"

Butin::Butin() {
    gameStarted = false;
    board = new ButinBoard();
//    cout << "Construction of " << *this;
}
bool Butin::hasGameStarted() const {
    return gameStarted;
}
bool Butin::isGameDone() const{
    if (board -> isGameDone()) {
        int totalPointsRemaining = ((ButinBoard *) board) -> getBoardTotalPoints();
        player_list[(currentPlayerIndex - 1) % player_list.size()] -> increaseScore(-totalPointsRemaining);
        return true;
    }
    return false;
}
string Butin::getWinner() const {
    int max = 0;
    int winnerIndex = 0;
    for (size_t i = 0; i < player_list.size(); i++) {
        if (player_list[i] -> getScore() > max) {
            max = player_list[i] -> getScore();
            winnerIndex = i;
        }
    }
    return player_list[winnerIndex] -> name;
}
void Butin::initPlayers(vector<std::string> playerNames) {
    for (const string& s : playerNames){
        player_list.push_back(new Player(s));
    }
    currentPlayer = player_list[0];
}
void Butin::initializeGame(const GameConfig &gc) {
    ButinConfig &bc = (ButinConfig &) gc;
    ((ButinBoard *) board)->initializeGame(bc.deleted_pieces);
    gameStarted = true;
}

void Butin::makeMove(const Vector2i &from, const Vector2i &to) {
    currentPlayer->increaseScore(((ButinBoard *) board)->getJumpedPieceType(from, to));
    board->makeMove(from, to, currentPlayerIndex);

    if (validMoves(to).empty()) {
        currentPlayerIndex = (currentPlayerIndex + 1) % (int) player_list.size();
        currentPlayer = player_list[currentPlayerIndex];
    }
}

const vector<Vector2i> Butin::validMoves(const Vector2i &from) const {
    return board->validMoves(from, currentPlayerIndex);
}

const string Butin::getCurrentPlayer() const {
    return currentPlayer->name;
}
vector<string> Butin::getPlayerScores() const {
    vector<string> res;
    for (Player *p : player_list) {
        res.push_back(to_string(p -> getScore()));
    }
    return res;
}
const int Butin::getCurrentPlayerIndex() const {
    return currentPlayerIndex;
}
vector<string> Butin::getPlayerNames() const {
    vector<string> res;
    for (Player *p : player_list) {
        res.push_back(p -> name);
    }
    return res;
}

const vector<vector<vector<string>>> Butin::getBoardState() const {
    return board->getBoardState();
}

const pair<int, int> Butin::getMinMaxPlayers() const {
    const pair<int, int> res(2, 2);
    return res;
}

Butin::~Butin() {
    cout << "Destruction of " << *this;
}

ostream &operator<<(ostream &o, const Butin &) {
    o << "Game: Butin" << endl;
    return o;
}

