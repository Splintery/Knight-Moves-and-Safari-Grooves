#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <unordered_map>
#include <iostream>
#include <vector>
using namespace std;

enum class ButinPieceType {
    Red,
    Yellow,
    Black,
    EmptyButin
};

// Crocodile => Player 0
// Elephant => Player 1
// Lion => Player 2
enum class SafariPieceType {
    Crocodile,
    Elephant,
    Lion,
    Fence,
    EmptySafari
};

enum class GounkiPieceType {
    BlackSquare,
    BlackCircle,
    WhiteSquare,
    WhiteCircle,
    EmptyGounki
};

enum class ActionKey {
    LeftClick,
    RightClick
};

namespace UtilityFunctions {

    const string getButinPieceString(ButinPieceType type);

    const string getSafariPieceString(SafariPieceType type);

    const string getGounkiPieceString(GounkiPieceType type);

    void printBoard(const std::vector<std::vector<std::vector<std::string>>>& board);
}

#endif