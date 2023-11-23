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

enum class SafariPieceType {
    Elephant,
    Rhinoceros,
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

namespace UtilityFunctions {

    const string getButinPieceString(ButinPieceType type);

    const string getSafariPieceString(SafariPieceType type);

    const string getGounkiPieceString(GounkiPieceType type);

    void printBoard(const std::vector<std::vector<std::vector<std::string>>>& board);
}

#endif
