#include "Utilities.hpp"

const string UtilityFunctions::getButinPieceString(ButinPieceType type) {
    switch (type) {
        case ButinPieceType::Red: return "redPiece";
        case ButinPieceType::Yellow: return "yellowPiece";
        case ButinPieceType::Black: return "blackPiece";
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

void UtilityFunctions::printBoard(const std::vector<std::vector<std::vector<std::string>>> &board) {
    if (board.empty()) return; // Handle empty board

    // Find the maximum length in each row
    std::vector<size_t> rowWidths;
    for (const auto& col : board) {
        rowWidths.push_back(0); // Initialize widths for each column
        for (const auto& cell : col) {
            if (!cell.empty()) {
                // Extract filename from path
                std::string filename = cell.front().substr(cell.front().rfind('/') + 1);
                // Simplify string from path to filename
                rowWidths.back() = std::max(rowWidths.back(), filename.length());
            }
        }
    }

    // Print the board
    for (size_t j = 0; j < board[0].size(); ++j) { // Loop over rows
        std::string separator = "+";
        for (size_t i = 0; i < board.size(); ++i) { // Loop over columns
            std::cout << "|";
            if (!board[i][j].empty()) {
                std::string filename = board[i][j].front().substr(board[i][j].front().rfind('/') + 1);
                std::cout << " " << filename;
                std::cout << std::string(rowWidths[i] - filename.length(), ' '); // Adjust spacing
            } else {
                std::cout << std::string(rowWidths[i] + 1, ' '); // Adjust for empty cell
            }
            separator += std::string(rowWidths[i] + 2, '-') + "+";
        }
        std::cout << "|\n" << separator << "\n";
    }
}
