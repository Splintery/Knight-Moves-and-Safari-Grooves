#include "ButinState.hpp"
#include "../model/Butin.hpp"

using namespace std;

ButinState::ButinState(Controller *controller): controller{controller}, currentPlayerIndex{0}, moveReady{false}, playerPlayed{false}, printWinner{false} {
	// do stuff in init rather then here
}
ButinState::~ButinState() {
    delete(pieceSprite);
    cout << "deleting butinGameState" << endl;
}

void ButinState::init() {
    Vector2f center = controller -> machine -> getCenter();

    winner.setFont(controller -> resource -> getFont("pixel"));
    winner.setFillColor(Color(9, 109, 8));
    winner.setCharacterSize(TITLE_SIZE * 3);
    winner.setRotation(10);

    pieceSprite = new Sprite();
    boardFactory();
    board.setTexture(rd.getTexture());
    board.setScale(0.75, 0.75);
    backBoard.setTexture(controller -> resource -> getTexture("backBoard"));
    backBoard.setScale(0.80, 0.80);

    background.setTexture(controller -> resource -> getTexture("background"));
    background.setPosition(0, 0);

    board.setPosition(
        center.x - board.getGlobalBounds().width / 2, center.y - board.getGlobalBounds().height / 2
    );
    backBoard.setPosition(
        center.x - backBoard.getGlobalBounds().width / 2, center.y - backBoard.getGlobalBounds().height / 2
    );
    initializePlayerDisplays();
    colorCurrentPlayer();
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
                                if (controller -> game -> hasGameStarted() && controller -> game -> isGameDone()) {
                                    winner.setString(controller -> game -> getWinner());
                                    printWinner = true;
                                }
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


void ButinState::drawPlayerDisplay() {
    for (Text t : playerNamesDisplay) {
        controller -> window -> draw(t);
    }
    for (Text t : playerScoresDisplay) {
        controller -> window -> draw(t);
    }
}
void ButinState::draw() {
	controller -> window -> clear();

    controller -> window -> draw(background);
    controller -> window -> draw(backBoard);
    controller -> window -> draw(board);

    if (printWinner) {
        controller -> window -> draw(winner);
    } else {
        if (controller -> game -> hasGameStarted()) {

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
    }
    drawPlayerDisplay();
	controller -> window -> display();
}

void ButinState::update() {
	pieces = controller -> game -> getBoardState();
    if (moveReady) {
        int oldPlayerIndex = currentPlayerIndex;
        moveReady = false;
        controller -> game -> makeMove(*fromTile, *toTile);
        currentPlayerIndex = controller -> game -> getCurrentPlayerIndex();
        movesPossible.clear();

        if (currentPlayerIndex != oldPlayerIndex) {
            delete(fromTile);
            delete(toTile);
            fromTile = nullptr;
            toTile = nullptr;
            colorCurrentPlayer();
            playerPlayed = false;
        } else {
            delete(fromTile);
            fromTile = new Vector2i(*toTile);
            delete(toTile);
            toTile = nullptr;
            movesPossible = controller -> game -> validMoves(*fromTile);
        }

        if (controller -> game -> hasGameStarted() && controller -> game -> isGameDone()) {
            winner.setString(controller -> game -> getWinner());
            winner.setPosition(controller -> machine -> getCenter().x - winner.getGlobalBounds().width / 2, controller -> machine -> getCenter().y - winner.getGlobalBounds().height / 2);

            printWinner = true;
        }
        vector<string> newScores = ((Butin *) controller -> game) -> getPlayerScores();
        for (size_t i = 0; i < playerScoresDisplay.size(); i++) {
            playerScoresDisplay[i].setString(newScores[i]);
        }
    }
}
void ButinState::boardFactory() {
    Sprite whiteTileSprite = Sprite();
    Texture whiteTile = Texture();
    if (DARK_MODE) {
        whiteTile.loadFromFile("./resources/board/BlackTile.png");
    } else {
        whiteTile.loadFromFile("./resources/board/WhiteTile.png");
    }
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
    auto it = find(piecesToRemove.begin(), piecesToRemove.end(),v);
    if (it != piecesToRemove.end()) {
        piecesToRemove.erase(it);
    } else {
        piecesToRemove.push_back(v);
    }
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
void ButinState::colorCurrentPlayer() {
    for (size_t i = 0; i < playerNamesDisplay.size(); i++) {
        playerNamesDisplay[i].setFillColor(Color::Black);
    }
    playerNamesDisplay[currentPlayerIndex].setFillColor(Color(172, 50, 50));
}

void ButinState::initializePlayerDisplays() {
    for (size_t i = 0; i < controller -> game -> getPlayerNames().size(); i++) {
        playerNamesDisplay.push_back(Text());
        playerNamesDisplay[i].setFont(controller -> resource -> getFont("pixel"));
        playerNamesDisplay[i].setCharacterSize(TEXT_SIZE);
        playerNamesDisplay[i].setFillColor(Color::Black);
        playerNamesDisplay[i].setString(controller -> game -> getPlayerNames()[i]);
        playerNamesDisplay[i].setPosition(
            TILE_SIZE * 2.5,
            board.getGlobalBounds().top + TILE_SIZE * i
        );

        playerScoresDisplay.push_back(Text());
        playerScoresDisplay[i].setFont(controller -> resource -> getFont("pixel"));
        playerScoresDisplay[i].setCharacterSize(TEXT_SIZE);
        playerScoresDisplay[i].setFillColor(Color::Black);
        playerScoresDisplay[i].setString(to_string(0));
        playerScoresDisplay[i].setPosition(
            TILE_SIZE * 3 + playerNamesDisplay[i].getGlobalBounds().width,
            board.getGlobalBounds().top + TILE_SIZE * i
        );
    }
}