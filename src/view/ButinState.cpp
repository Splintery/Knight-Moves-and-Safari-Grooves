#include "ButinState.hpp"
#include "../model/ButinConfig.hpp"
#include "../model/Player.hpp"

using namespace std;

ButinState::ButinState(Controller *controller): controller{controller}, moveReady{false}, playerPlayed{false} {
	// do stuff in init rather then here
}
ButinState::~ButinState() {
    delete(pieceSprite);
    cout << "deleting butinGameState" << endl;
}

void ButinState::init() {

    pieceSprite = new Sprite();
    boardFactory();
    board.setTexture(rd.getTexture());
    board.setScale(0.75, 0.75);
    background.setTexture(controller -> resource -> getTexture("background"));
    background.setPosition(0, 0);
    currentPlayerDisplay.setFont(controller -> resource -> getFont("pixel"));
    currentPlayerDisplay.setCharacterSize(TEXT_SIZE);
    currentPlayerDisplay.setFillColor(Color::Black);
    currentPlayerDisplay.setString(controller -> game -> getCurrentPlayer());
    currentPlayerDisplay.setPosition(0, 0);
    currentPlayerScoreDisplay.setFont(controller -> resource -> getFont("pixel"));
    currentPlayerScoreDisplay.setCharacterSize(TEXT_SIZE);
    currentPlayerScoreDisplay.setFillColor(Color::Black);
    currentPlayerScoreDisplay.setString(controller -> game -> getCurrentPlayerScore());
    currentPlayerScoreDisplay.setPosition(100, 0);

    Vector2f center = controller -> machine -> getCenter();
    board.setPosition(
        center.x - board.getGlobalBounds().width / 2, center.y - board.getGlobalBounds().height / 2
    );
    redTileSprite.setTexture(controller -> resource -> getTexture("redTile"));
    redTileSprite.setScale(0.75, 0.75);
    blueTileSprite.setTexture(controller -> resource -> getTexture("blueTile"));
    blueTileSprite.setScale(0.75, 0.75);
}

void ButinState::handleInput() {
	Event event;

	while (controller -> window -> pollEvent(event)) {
        switch (event.type) {
            case Event::Closed:
                controller -> window -> close();
                break;
            case sf::Event::MouseButtonPressed:
                if (controller -> input -> isSpriteClicked(board, Mouse::Left, *controller -> window)) {
                    Vector2i tileClicked = controller -> input -> getTileWithinBoard(
                        board,
                        controller -> input -> getMousePosition(*controller -> window),
                        BUTIN_BOARD_SIZE
                    );
                    if (pieces[tileClicked.x][tileClicked.y][0] == "yellowPiece") {
                        if (controller -> game -> hasGameStarted()) {

                            if (fromTile == nullptr) {
                                fromTile = new Vector2i(tileClicked);
                                movesPossible = controller -> game -> validMoves(*fromTile);
                            } else {
                                if (!playerPlayed) {
                                    if (*fromTile == tileClicked) {
                                        delete(fromTile);
                                        fromTile = nullptr;
                                        movesPossible.clear();
                                    } else {
                                        delete(fromTile);
                                        fromTile = new Vector2i(tileClicked);
                                        movesPossible = controller -> game -> validMoves(*fromTile);
                                    }
                                }
                            }
                        } else {
                            addPieceToRemove(tileClicked);
                            if (piecesToRemove.size() >= controller -> game -> player_list.size()) {
                                controller -> game -> initializeGame(ButinConfig(piecesToRemove));
                            }
                        }
                    } else if (pieces[tileClicked.x][tileClicked.y][0] == "") {
                        if (toTile == nullptr && fromTile != nullptr) {
                            for (Vector2i v : movesPossible) {
                                if (tileClicked == v) {
                                    playerPlayed = true;
                                    toTile = new Vector2i(tileClicked);
                                    moveReady = true;
                                }
                            }
                        }
                    }
                }
                break;
            default:
                break;
        }
	}
}

void ButinState::draw() {
	controller -> window -> clear();

    controller -> window -> draw(background);
    controller -> window -> draw(board);

    if (controller -> game -> hasGameStarted()) {
        controller -> window -> draw(currentPlayerDisplay);
        controller -> window -> draw(currentPlayerScoreDisplay);

        if (fromTile != nullptr) {
            positionBlueTile(*fromTile);
            controller -> window -> draw(blueTileSprite);
            for (Vector2i v : movesPossible) {
                positionRedTile(v);
                controller -> window -> draw(redTileSprite);
            }
        }
    } else {
        // Highlights the Tiles that will be removed by the players
        for (Vector2i v : piecesToRemove) {
            positionRedTile(v);
            controller -> window -> draw(redTileSprite);
        }
    }

    // Draws all the pieces on their Tiles
    for (int i = 0; i < (int) pieces.size(); i++) {
        for (int j = 0; j < (int) pieces.size(); j++) {
            if (pieces[i][j][0] != "") {
                pieceSprite -> setTexture(controller -> resource -> getTexture(pieces[i][j][0]));
                pieceSprite -> setScale(1.25, 1.25);
                Vector2i v{i, j};
                controller -> input -> positionPieceWithinBoard(pieceSprite, board, v, BUTIN_BOARD_SIZE);
                controller -> window -> draw(*pieceSprite);
            }
        }
    }


	controller -> window -> display();
}

void ButinState::update() {
	pieces = controller -> game -> getBoardState();
    if (moveReady) {
        moveReady = false;
        controller -> game -> makeMove(*fromTile, *toTile);
        currentPlayerScoreDisplay.setString(controller -> game -> getCurrentPlayerScore());
        movesPossible.clear();

        string name = controller -> game -> getCurrentPlayer();
        if (name != currentPlayerDisplay.getString()) {
            delete(fromTile);
            delete(toTile);
            fromTile = nullptr;
            toTile = nullptr;
            currentPlayerDisplay.setString(name);
            playerPlayed = false;
        } else {
            delete(fromTile);
            fromTile = new Vector2i(*toTile);
            delete(toTile);
            toTile = nullptr;
            movesPossible = controller -> game -> validMoves(*fromTile);
        }
    }
}
void ButinState::boardFactory() {
    Sprite whiteTileSprite = Sprite();
    Texture whiteTile = Texture();
    whiteTile.loadFromFile("./resources/board/WhiteTile.png");
    whiteTileSprite.setTexture(whiteTile);


    rd.create(120 * BUTIN_BOARD_SIZE, 120 * BUTIN_BOARD_SIZE);
    rd.clear();
    for (int i = 0; i < BUTIN_BOARD_SIZE; i++) {
        for (int j = 0; j < BUTIN_BOARD_SIZE; j++) {
            whiteTileSprite.setPosition(i * 120, j * 120);
            rd.draw(whiteTileSprite);
        }
    }
    rd.display();
}

void ButinState::addPieceToRemove(sf::Vector2i v) {
    for (Vector2i vct : piecesToRemove) {
        if (vct == v) return;
    }
    piecesToRemove.push_back(v);
}
void ButinState::positionRedTile(Vector2i v) {
    redTileSprite.setPosition(
        board.getGlobalBounds().left + v.x * board.getGlobalBounds().width / BUTIN_BOARD_SIZE,
        board.getGlobalBounds().top + v.y * board.getGlobalBounds().height / BUTIN_BOARD_SIZE
    );
}
void ButinState::positionBlueTile(sf::Vector2i v) {
    blueTileSprite.setPosition(
        board.getGlobalBounds().left + v.x * board.getGlobalBounds().width / BUTIN_BOARD_SIZE,
        board.getGlobalBounds().top + v.y * board.getGlobalBounds().height / BUTIN_BOARD_SIZE
    );
}