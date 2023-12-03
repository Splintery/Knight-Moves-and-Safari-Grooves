#include "ButinState.hpp"
#include "../model/ButinConfig.hpp"

using namespace std;

ButinState::ButinState(Controller *controller): controller{controller} {
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
    currentPlayer.setFont(controller -> resource -> getFont("pixel"));
    currentPlayer.setCharacterSize(TEXT_SIZE);
    currentPlayer.setFillColor(Color::Black);
    currentPlayer.setPosition(0, 0);

    Vector2f center = controller -> machine -> getCenter();
    board.setPosition(
        center.x - board.getGlobalBounds().width / 2, center.y - board.getGlobalBounds().height / 2
    );

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
                            cout << "game started !!!!" << endl;
                        } else {
                            addPieceToRemove(tileClicked);
                            if (piecesToRemove.size() >= controller -> game -> player_list.size()) {
                                controller -> game -> initializeGame(ButinConfig(piecesToRemove));
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

    if (controller -> game -> hasGameStarted()) {
        controller -> window -> draw(currentPlayer);
    }

	controller -> window -> display();
}

void ButinState::update() {
    currentPlayer.setString(controller -> game -> getCurrentPlayer());
	pieces = controller -> game -> getBoardState();
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

void ButinState::buildPieces(vector<vector<vector<string>>> sprites) {
}
void ButinState::addPieceToRemove(sf::Vector2i v) {
    for (Vector2i vct : piecesToRemove) {
        if (vct == v) return;
    }
    piecesToRemove.push_back(v);
}