#ifndef UTILITIES_HPP
#define UTILITIES_HPP

#include <unordered_map>
using namespace std;

enum ButinPieceType {
    Red,
    Yellow,
    Black,
    EmptyButin
};

enum SafariPieceType {
    Elephant,
    Rhinoceros,
    Lion,
    Fence,
    EmptySafari
};

enum GounkiPieceType {
    BlackSquare,
    BlackCircle,
    WhiteSquare,
    WhiteCircle,
    EmptyGounki
};

unordered_map<ButinPieceType, string> butinSpriteMap = {
    {Red, ""},
    {Yellow, ""},
    {Black, ""},
    {EmptyButin, ""}
};

unordered_map<SafariPieceType, string> safariSpriteMap = {
    {Elephant, ""},
    {Rhinoceros, ""},
    {Lion, ""},
    {Fence, ""},
    {EmptySafari, ""}
};

unordered_map<GounkiPieceType, string> gounkiSpriteMap = {
    {BlackSquare, ""},
    {BlackCircle, ""},
    {WhiteSquare, ""},
    {WhiteCircle, ""},
    {EmptyGounki, ""}
};

#endif
