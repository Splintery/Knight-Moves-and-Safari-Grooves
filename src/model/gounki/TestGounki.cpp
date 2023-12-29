#include "GounkiPiece.hpp"
#include "GounkiBoard.hpp"

int main() {
    GounkiBoard *gb = new GounkiBoard();

    Vector2i pos (5, 2);
    gb->makeMove(ActionKey::LeftClick,0, Vector2i {1, 0}, pos);
    gb->makeMove(ActionKey::LeftClick,0, Vector2i {1, 1}, pos);
    gb->makeMove(ActionKey::LeftClick,0, Vector2i {1, 2}, pos);
    gb->makeMove(ActionKey::LeftClick,0, Vector2i {6, 1}, Vector2i {5, 1});
    vector<Vector2i> tmp = gb->validMoves(ActionKey::LeftClick, 0, pos);
    gb->makeMove(ActionKey::LeftClick,0, Vector2i {1, 3}, Vector2i {5, 3});
    gb->makeMove(ActionKey::LeftClick,0, Vector2i {1, 4}, Vector2i {5, 3});
    vector<Vector2i> tmp2 = gb->validMoves(ActionKey::LeftClick, 0, Vector2i {5, 3});
    Vector2i circlesRebound (6, 1);
    gb->makeMove(ActionKey::LeftClick,0, Vector2i {0, 0}, circlesRebound);
    gb->makeMove(ActionKey::LeftClick,0, Vector2i {0, 2}, circlesRebound);
    gb->makeMove(ActionKey::LeftClick,0, Vector2i {0, 4}, circlesRebound);
    vector<Vector2i> tmp3 = gb->validMoves(ActionKey::LeftClick, 0, circlesRebound);
    /*
    Vector2i testDeployement (4, 6);
    Vector2i land1Deployement (3, 7);
    Vector2i land2Deployement (2, 6);
    Vector2i land3Deployement (1, 6);
    gb->makeMove(ActionKey::LeftClick,0, Vector2i {6, 0}, testDeployement);
    gb->makeMove(ActionKey::LeftClick,0, Vector2i {6, 1}, testDeployement);
    gb->makeMove(ActionKey::LeftClick,0, Vector2i {6, 2}, testDeployement);
    vector<Vector2i> tmp4 = gb->validMoves(ActionKey::RightClick, 0, testDeployement);
    gb->makeMove(ActionKey::RightClick,0, testDeployement, land1Deployement);
    vector<Vector2i> tmp6 = gb->validMoves(ActionKey::RightClick, 0, land1Deployement);
    gb->makeMove(ActionKey::RightClick,0, land1Deployement, land2Deployement);
    vector<Vector2i> tmp7 = gb->validMoves(ActionKey::RightClick, 0, land2Deployement);
    gb->makeMove(ActionKey::RightClick,0, land2Deployement, land3Deployement);
    vector<Vector2i> tmp8 = gb->validMoves(ActionKey::RightClick, 0, land1Deployement);
     */
}