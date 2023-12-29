#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <unordered_map>
#include <iostream>
#include <vector>
#include <SFML/System/Vector2.hpp>
using namespace std;
using namespace sf;

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

    const int getValueFromColor(ButinPieceType color);

    void printBoard(const std::vector<std::vector<std::vector<std::string>>>& board);
}

#endif