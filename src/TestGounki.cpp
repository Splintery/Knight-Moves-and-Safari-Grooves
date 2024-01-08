#include "model/gounki/GounkiPiece.hpp"
#include "model/gounki/GounkiBoard.hpp"
#include "model/gounki/Gounki.hpp"

int main() {
    Gounki* g = new Gounki();
    vector<string> s = {"luc", "yan"};
    g->initPlayers(s);
    g->initializeGame(GameConfig {});

    /*
    Vector2i testDeployement (4, 4);
    Vector2i land1Deployement (3, 5);
    Vector2i land2Deployement (2, 6);
    Vector2i land3Deployement (2, 7);
    Vector2i blockLastDep1 (2, 6);
    Vector2i blockLastDep2 (2, 7);
    g->makeMove(ActionKey::LeftClick, Vector2i {6, 0}, testDeployement);
    g->makeMove(ActionKey::LeftClick, Vector2i {6, 1}, testDeployement);
    g->makeMove(ActionKey::LeftClick, Vector2i {6, 2}, testDeployement);
    g->makeMove(ActionKey::LeftClick, Vector2i {6, 3}, blockLastDep1);
    g->makeMove(ActionKey::LeftClick, Vector2i {6, 4}, blockLastDep2);
    vector<Vector2i> tmp4 = g->validMoves(ActionKey::RightClick,  testDeployement);
    g->makeMove(ActionKey::RightClick, testDeployement, land1Deployement);
    vector<Vector2i> tmp6 = g->validMoves(ActionKey::RightClick,  land1Deployement);
    g->makeMove(ActionKey::RightClick, land1Deployement, land2Deployement);
    vector<Vector2i> tmp7 = g->validMoves(ActionKey::RightClick,  land2Deployement);
    g->makeMove(ActionKey::RightClick, land2Deployement, land3Deployement);
    vector<Vector2i> tmp8 = g->validMoves(ActionKey::RightClick,  land1Deployement);
     */
    /*
    Vector2i stack3 {1, 0};
    g->makeMove(ActionKey::LeftClick, Vector2i {0, 0}, stack3);
    g->makeMove(ActionKey::LeftClick, Vector2i {0, 2}, stack3);
    vector<Vector2i> tmp9 = g->validMoves(ActionKey::LeftClick,  stack3);
     */
    // deploy on own pieces scheme
    /*
    Vector2i stack1 {1, 1};
    Vector2i stack2 {2, 3};
    g->makeMove(ActionKey::LeftClick, Vector2i {0, 0}, stack1);
    g->makeMove(ActionKey::LeftClick, Vector2i {1, 0}, stack1);
    g->makeMove(ActionKey::LeftClick, Vector2i {0, 3}, stack2);
    g->makeMove(ActionKey::LeftClick, Vector2i {1, 3}, stack2);
    vector<Vector2i> tmp1 = g->validMoves(ActionKey::RightClick,  stack1);
    g->makeMove(ActionKey::RightClick, stack1, Vector2i {1, 2});
    vector<Vector2i> tmp2 = g->validMoves(ActionKey::RightClick,  Vector2i {1, 2});
    g->makeMove(ActionKey::RightClick, Vector2i {1, 2}, Vector2i {2, 3});
    vector<Vector2i> tmp3 = g->validMoves(ActionKey::RightClick,  Vector2i {2, 3});
    g->makeMove(ActionKey::RightClick, Vector2i {2, 3}, Vector2i {3, 4});
    Vector2i stack3 {7, 2};
    g->makeMove(ActionKey::LeftClick, Vector2i {7, 0}, stack3);
    g->makeMove(ActionKey::LeftClick, Vector2i {7, 1}, stack3);
    vector<Vector2i> tmp4 = g->validMoves(ActionKey::RightClick,  stack3);
    g->makeMove(ActionKey::RightClick, stack3, Vector2i {6, 3});
    vector<Vector2i> tmp5 = g->validMoves(ActionKey::RightClick,  Vector2i {6, 3});
    g->makeMove(ActionKey::RightClick, Vector2i {6, 3}, Vector2i {6, 4});
    vector<Vector2i> tmp6 = g->validMoves(ActionKey::RightClick,  Vector2i {6, 4});
    g->makeMove(ActionKey::RightClick, Vector2i {6, 4}, Vector2i {6, 5});
     */
    // rebounds first scheme
    /*
    Vector2i stack1 {2, 6};
    g->makeMove(ActionKey::LeftClick, Vector2i {6, 6}, stack1);
    g->makeMove(ActionKey::LeftClick, Vector2i {0, 6}, stack1);
    vector<Vector2i> tmp1 = g->validMoves(ActionKey::LeftClick,  stack1);
    Vector2i stack2 {6, 1};
    g->makeMove(ActionKey::LeftClick, Vector2i {5, 1}, stack2);
    g->makeMove(ActionKey::LeftClick, Vector2i {7, 1}, stack2);
    vector<Vector2i> tmp2 = g->validMoves(ActionKey::LeftClick,  stack2);
    Vector2i stack3 {6, 6};
    g->makeMove(ActionKey::LeftClick, Vector2i {5, 6}, stack3);
    g->makeMove(ActionKey::LeftClick, Vector2i {7, 6}, stack3);
    vector<Vector2i> tmp3 = g->validMoves(ActionKey::LeftClick,  stack3);
     */
    // deployments + rebound second scheme
    /*
    Vector2i stack1 {2, 2};
    g->makeMove(ActionKey::LeftClick, Vector2i {1, 0}, stack1);
    g->makeMove(ActionKey::LeftClick, Vector2i {3, 0}, stack1);
    g->makeMove(ActionKey::LeftClick, Vector2i {6, 1}, stack1);
    vector<Vector2i> tmp1 = g->validMoves(ActionKey::RightClick,  stack1);
    g->makeMove(ActionKey::RightClick, stack1, Vector2i {1, 2});
    vector<Vector2i> tmp2 = g->validMoves(ActionKey::RightClick, Vector2i {1, 2});
    g->makeMove(ActionKey::RightClick, Vector2i {1, 2}, Vector2i {0, 2});
    vector<Vector2i> tmp3 = g->validMoves(ActionKey::RightClick, Vector2i {0, 2});
    g->makeMove(ActionKey::RightClick, Vector2i {0, 2}, Vector2i {1, 2});
    Vector2i stack2 {6, 4};
    g->makeMove(ActionKey::LeftClick, Vector2i {0, 6}, stack2);
    g->makeMove(ActionKey::LeftClick, Vector2i {1, 6}, stack2);
    g->makeMove(ActionKey::LeftClick, Vector2i {6, 6}, stack2);
    vector<Vector2i> tmp4 = g->validMoves(ActionKey::RightClick,  stack2);
    g->makeMove(ActionKey::RightClick, stack2, Vector2i {7, 3});
    vector<Vector2i> tmp5 = g->validMoves(ActionKey::RightClick, Vector2i {7, 3});
    g->makeMove(ActionKey::RightClick, Vector2i {7, 3}, Vector2i {6, 2});
    vector<Vector2i> tmp6 = g->validMoves(ActionKey::RightClick, Vector2i {6, 2});
    g->makeMove(ActionKey::RightClick, Vector2i {6, 2}, Vector2i {6, 1});
    Vector2i stack3 {2, 5};
    g->makeMove(ActionKey::LeftClick, Vector2i {6, 0}, stack3);
    g->makeMove(ActionKey::LeftClick, Vector2i {7, 0}, stack3);
    g->makeMove(ActionKey::LeftClick, Vector2i {5, 0}, stack3);
    vector<Vector2i> tmp7 = g->validMoves(ActionKey::RightClick,  stack3);
    g->makeMove(ActionKey::RightClick, stack3, Vector2i {1, 6});
    vector<Vector2i> tmp8 = g->validMoves(ActionKey::RightClick, Vector2i {1, 6});
    g->makeMove(ActionKey::RightClick, Vector2i {1, 6}, Vector2i {0, 6});
    vector<Vector2i> tmp9 = g->validMoves(ActionKey::RightClick, Vector2i {0, 6});
    g->makeMove(ActionKey::RightClick, Vector2i {0, 6}, Vector2i {1, 6});
    Vector2i stack4 {6, 6};
    g->makeMove(ActionKey::LeftClick, Vector2i {7, 6}, stack4);
    g->makeMove(ActionKey::LeftClick, Vector2i {6, 7}, stack4);
    vector<Vector2i> tmpA = g->validMoves(ActionKey::RightClick,  stack4);
    g->makeMove(ActionKey::RightClick, stack4, Vector2i {7, 6});
    vector<Vector2i> tmpB = g->validMoves(ActionKey::RightClick, Vector2i {7, 6});
    g->makeMove(ActionKey::RightClick, Vector2i {7, 6}, Vector2i {6, 6});
    */
}