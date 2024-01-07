#include "GounkiState.hpp"
#include "../PauseState.hpp"


GounkiState::GounkiState(Controller *controller): GameState(controller, GOUNKI_BOARD_SIZE) {
    //Do stuuf in init
}
GounkiState::~GounkiState() {
    if (fromTile != nullptr) delete(fromTile);
    if (toTile != nullptr) delete(toTile);
    delete(pieceSprite);
    cout << "deleting gounkiGameState" << endl;
}

void GounkiState::init() {
    Vector2f center = controller -> machine -> getCenter();

    initWinner();

    pieceSprite = new Sprite();
    pieceSprite -> setScale(1.25, 1.25);

    boardFactory();
    board.setTexture(render.getTexture());
    board.setScale(0.75, 0.75);

    backBoard.setTexture(backBoardFactory());
    backBoard.setScale(0.75, 0.75);

    background.setTexture(controller -> resource -> getTexture("background"));

    background.setPosition(0, 0);

    board.setPosition(
        center.x - board.getGlobalBounds().width / 2, center.y - board.getGlobalBounds().height / 2
    );
    backBoard.setPosition(
        center.x - backBoard.getGlobalBounds().width / 2, center.y - backBoard.getGlobalBounds().height / 2
    );
    GameState::initializePlayerDisplay(TILE_SIZE);
    colorCurrentPlayer();
    redTileSprite.setTexture(controller -> resource -> getTexture("redTile"));
    redTileSprite.setScale(0.75, 0.75);
    blueTileSprite.setTexture(controller -> resource -> getTexture("blueTile"));
    blueTileSprite.setScale(0.75, 0.75);

}

void GounkiState::handleInput() {
    Event event;
    Vector2i tileClicked = GameState::getTileWithinBoard(controller -> input -> getMousePosition(*controller -> window));

	while (controller -> window -> pollEvent(event)) {
        switch (event.type) {
            case Event::Closed:
                controller -> window -> close();
                break;
            case Event::KeyPressed:
                if (Keyboard::isKeyPressed(Keyboard::Escape)) {
                    controller -> machine -> addState(new PauseState(controller, controller -> getWindowAsTexture()), false);
                }
                break;
            case Event::MouseButtonPressed:
                if (controller -> input -> isSpriteClicked(board, Mouse::Left, *controller -> window)) {
                    if (currentPlayerIndex == pieces[tileClicked.x][tileClicked.y][0])
                } else if (controller -> input -> isSpriteClicked(board, Mouse::Right, *controller -> window)) {

                }
                break;
            default:
                break;
        }
	}
}

void GounkiState::drawPieces() {
    for (int i = 0; i < (int) pieces.size(); i++) {
        for (int j = 0; j < (int) pieces[i].size(); j++) {
            for (int k = (int) pieces[i][j].size() - 1; k >= 0 ; k--) {
                if (pieces[i][j][0] != "") {
                    pieceSprite -> setTexture(controller -> resource -> getTexture(pieces[i][j][k]));
                    Vector2i v{i + 10 * k, j + 10 * k};
                    positionPieceWithinBoard(pieceSprite, v);
                    controller -> window -> draw(*pieceSprite);
                }
            }

        }
    }
}

void GounkiState::draw() {
	controller -> window -> clear();

    GameState::drawBase();

    if (printWinner) {
        controller -> window -> draw(winner);
    } else {
        if (controller -> game -> hasGameStarted()) {
            if (fromTile != nullptr) {
                GameState::drawMovesPossible();
                GameState::drawSelectedTile();
            }
        }
        // Draws all the pieces on their Tiles
        drawPieces();
    }
    GameState::drawPlayerDisplay();
	controller -> window -> display();
}

void GounkiState::update() {
	pieces = controller -> game -> getBoardState();
    if (moveReady) {
        int oldPlayerIndex = currentPlayerIndex;
        moveReady = false;
        controller -> game -> makeMove(ActionKey::LeftClick, *fromTile, *toTile);
        currentPlayerIndex = controller -> game -> getCurrentPlayerIndex();
        movesPossible.clear();

        if (currentPlayerIndex != oldPlayerIndex) {
            delete(fromTile);
            delete(toTile);
            fromTile = nullptr;
            toTile = nullptr;
            GameState::colorCurrentPlayer();
            playerPlayed = false;
        } else {
            delete(fromTile);
            fromTile = new Vector2i(*toTile);
            delete(toTile);
            toTile = nullptr;
            movesPossible = controller -> game -> validMoves(ActionKey::LeftClick, *fromTile);
        }

        if (controller -> game -> hasGameStarted() && controller -> game -> isGameDone()) {
            GameState::gameOver();
        }
        GameState::updateScoresDisplay();
    }
}


void GounkiState::boardFactory() {
    Sprite whiteTileSprite, blackTileSprite = Sprite();
    Texture whiteTile, blackTile = Texture();

    whiteTile.loadFromFile("./resources/board/WhiteTile.png");
    blackTile.loadFromFile("./resources/board/BlackTile.png");
    whiteTileSprite.setTexture(whiteTile);
    blackTileSprite.setTexture(blackTile);


    render.create(120 * BUTIN_BOARD_SIZE, 120 * BUTIN_BOARD_SIZE);
    render.clear();
    for (int i = 0; i < BUTIN_BOARD_SIZE; i++) {
        for (int j = 0; j < BUTIN_BOARD_SIZE; j++) {
            if ((j + i) % 2 == 0) {
                whiteTileSprite.setPosition(i * 120, j * 120);
                render.draw(whiteTileSprite);
            } else {
                blackTileSprite.setPosition(i * 120, j * 120);
                render.draw(blackTileSprite);
            }
        }
    }
    render.display();
}