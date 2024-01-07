#ifndef SAFARISTATE_HPP
#define SAFARISTATE_HPP

#include "../GameState.hpp"

class SafariState : public GameState {
public:
    SafariState(Controller *controller);
    virtual ~SafariState();
    SafariState(const SafariState&) = delete;
    SafariState& operator=(const SafariState&) = delete;

	void init();
	void handleInput();
	void update();
	void draw();
private:
    void incrementPlayer();
    Sprite *horizontalFenceSprite;
    Sprite *verticalFenceSprite;
    Vector2i getTileWithinBoard(Vector2f mousePos, ActionKey action);
    void positionPieceWithinBoard(Sprite *piece, Vector2i pos);
    void positionFenceWithinBoard(Sprite *fence, Vector2i pos);
    void drawPieces();
    bool moveAnimal;
    Vector2i *onTile = nullptr;
    bool placeFence;
    int fencePlaced;
    void boardFactory();
    Texture& backBoardFactory();
    Sprite endTurnButton;
    bool canEndTurn;
    void endTurnButtonEffect();

    SafariConfig config;
    void addCrocodile(Vector2i v);
    void addElephant(Vector2i v);
    void addLion(Vector2i v);
    void addFence(Vector2i v);
    Text initInstructions;

    float boardScale;
};


#endif
