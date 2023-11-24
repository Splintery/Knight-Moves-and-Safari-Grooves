#pragma once
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

#define TMP 99

class Utilities {

    const static string getButinPieceString(ButinPieceType type);

    const static string getSafariPieceString(SafariPieceType type);

    const static string getGounkiPieceString(GounkiPieceType type);

    void static printBoard(const std::vector<std::vector<std::vector<std::string>>>& board);
};

#endif
