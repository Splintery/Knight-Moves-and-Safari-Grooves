#include "Utilities.hpp"

string UtilityFunctions::getButinPieceString(ButinPieceType type) {
    switch (type) {
        case ButinPieceType::Red: return "redPiece";
        case ButinPieceType::Yellow: return "yellowPiece";
        case ButinPieceType::Black: return "blackPiece";
        case ButinPieceType::EmptyButin: return "";
        default: return "";
    }
}

string UtilityFunctions::getSafariPieceString(SafariPieceType type) {
    switch (type) {
        case SafariPieceType::Crocodile: return "crocodilePiece";
        case SafariPieceType::Elephant: return "elephantPiece";
        case SafariPieceType::Lion: return "lionPiece";
        case SafariPieceType::Fence: return "fence";
        case SafariPieceType::EmptySafari: return "";
        default: return "";
    }
}

string UtilityFunctions::getGounkiPieceString(GounkiPieceType type) {
    switch (type) {
        case GounkiPieceType::BlackSquare: return "BlackSquare";
        case GounkiPieceType::BlackCircle: return "BlackCircle";
        case GounkiPieceType::WhiteSquare: return "WhiteSquare";
        case GounkiPieceType::WhiteCircle: return "WhiteCircle";
        case GounkiPieceType::EmptyGounki: return "EmptyGounki";
        default: return "";
    }
}

int UtilityFunctions::getValueFromColor(ButinPieceType color){
    switch (color) {
        case ButinPieceType::Black:
            return 3;
        case ButinPieceType::Red:
            return 2;
        case ButinPieceType::Yellow:
            return 1;
        case ButinPieceType::EmptyButin:
            return -1;
    }
    return 0;
}

SafariPieceType UtilityFunctions::getSafariPieceType(string type) {
    if (type == "crocodilePiece")   return SafariPieceType::Crocodile;
    if (type == "elephantPiece")    return SafariPieceType::Elephant;
    if (type == "lionPiece")    return SafariPieceType::Lion;
    if (type == "fence")    return SafariPieceType::Fence;
    return SafariPieceType::EmptySafari;
}

int UtilityFunctions::getPlayerFromAnimal(SafariPieceType animal) {
    return (int) animal;
}