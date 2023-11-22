#include "Utilities.hpp"

const string UtilityFunctions::getButinPieceString(ButinPieceType type) {
    switch (type) {
        case ButinPieceType::Red: return "../resources/RedButinSprite.png";
        case ButinPieceType::Yellow: return "../resources/YellowButinSprite.png";
        case ButinPieceType::Black: return "../resources/BlackButinSprite.png";
        case ButinPieceType::EmptyButin: return "../resources/EmptyButinSprite.png";
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