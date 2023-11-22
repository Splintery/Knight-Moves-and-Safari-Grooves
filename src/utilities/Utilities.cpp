#include "Utilities.hpp"

const string UtilityFunctions::getButinPieceString(ButinPieceType type) {
    switch (type) {
        case ButinPieceType::Red: return "";
        case ButinPieceType::Yellow: return "";
        case ButinPieceType::Black: return "";
        case ButinPieceType::EmptyButin: return "";
        default: return "";
    }
}

const string UtilityFunctions::getSafariPieceString(SafariPieceType type) {

    switch (type) {
        case SafariPieceType::Elephant: return "";
        case SafariPieceType::Rhinoceros: return "";
        case SafariPieceType::Lion: return "";
        case SafariPieceType::Fence: return "";
        case SafariPieceType::EmptySafari: return "";
        default: return "";
    }
}

const string UtilityFunctions::getGounkiPieceString(GounkiPieceType type) {
    switch (type) {
        case GounkiPieceType::BlackSquare: return "";
        case GounkiPieceType::BlackCircle: return "";
        case GounkiPieceType::WhiteSquare: return "";
        case GounkiPieceType::WhiteCircle: return "";
        case GounkiPieceType::EmptyGounki: return "";
        default: return "";
    }
}