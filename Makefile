GCC=g++ --std=c++11 -Wall
SFML_FLAGS=-lsfml-graphics -lsfml-window -lsfml-system
VIEW_CPP=src/view/InputManager.hpp src/view/StateMachine.hpp src/view/ResourceManager.hpp src/view/State.hpp

all: test clean

Utilities.o: src/utilities/Utilities.cpp src/utilities/Utilities.hpp
	$(GCC) -c src/utilities/Utilities.cpp

InputManager.o: src/view/InputManager.cpp src/view/InputManager.hpp
	$(GCC) -c src/view/InputManager.cpp $(SFML_FLAGS)

StateMachine.o: src/view/StateMachine.cpp src/view/StateMachine.hpp src/view/State.hpp
	$(GCC) -c src/view/StateMachine.cpp $(SFML_FLAGS)

ResourceManager.o: src/view/ResourceManager.cpp src/view/ResourceManager.hpp
	$(GCC) -c src/view/ResourceManager.cpp $(SFML_FLAGS)

MenuState.o: src/view/MenuState.cpp src/view/MenuState.hpp $(VIEW_CPP) src/controller/Controller.hpp src/settings/SETTINGS.hpp src/view/PlayerState.hpp
	$(GCC) -c src/view/MenuState.cpp $(SFML_FLAGS)

PlayerState.o: src/view/PlayerState.cpp src/view/PlayerState.hpp $(VIEW_CPP) src/controller/Controller.hpp src/settings/SETTINGS.hpp src/view/butin/ButinState.hpp
	$(GCC) -c src/view/PlayerState.cpp $(SFML_FLAGS)

GameState.o: src/view/GameState.cpp src/view/GameState.hpp $(VIEW_CPP) src/controller/Controller.hpp src/settings/SETTINGS.hpp
	$(GCC) -c src/view/GameState.cpp $(SFML_FLAGS)

ButinState.o: src/view/butin/ButinState.cpp src/view/butin/ButinState.hpp $(VIEW_CPP) src/view/GameState.hpp src/controller/Controller.hpp src/settings/SETTINGS.hpp src/model/butin/ButinConfig.hpp
	$(GCC) -c src/view/butin/ButinState.cpp $(SFML_FLAGS)

SafariState.o: src/view/safari/SafariState.cpp src/view/safari/SafariState.hpp $(VIEW_CPP) src/view/GameState.hpp src/controller/Controller.hpp src/settings/SETTINGS.hpp src/model/safari/SafariConfig.hpp
	$(GCC) -c src/view/safari/SafariState.cpp $(SFML_FLAGS)

Controller.o: src/controller/Controller.cpp src/controller/Controller.hpp $(VIEW_CPP) src/view/MenuState.hpp src/view/PlayerState.hpp src/settings/SETTINGS.hpp
	$(GCC) -c src/controller/Controller.cpp $(SFML_FLAGS)

Butin.o: src/model/butin/Butin.cpp src/model/butin/Butin.hpp src/model/Game.hpp src/model/Player.hpp src/model/Board.hpp src/model/Piece.hpp src/model/butin/ButinBoard.hpp
	$(GCC) -c src/model/butin/Butin.cpp

ButinBoard.o: src/model/butin/ButinBoard.cpp src/model/butin/ButinBoard.hpp src/model/Board.hpp src/model/Piece.hpp
	$(GCC) -c src/model/butin/ButinBoard.cpp

ButinPiece.o: src/model/butin/ButinPiece.cpp src/model/butin/ButinPiece.hpp src/model/Piece.hpp
	$(GCC) -c src/model/butin/ButinPiece.cpp

ButinConfig.o: src/model/butin/ButinConfig.cpp src/model/butin/ButinConfig.hpp src/model/GameConfig.hpp
	$(GCC) -c src/model/butin/ButinConfig.cpp

Player.o: src/model/Player.cpp src/model/Player.hpp
	$(GCC) -c src/model/Player.cpp

Safari.o: src/model/safari/Safari.cpp src/model/safari/Safari.hpp src/model/Game.hpp src/model/Player.hpp src/model/Board.hpp src/model/Piece.hpp src/model/safari/SafariBoard.hpp
	$(GCC) -c src/model/safari/Safari.cpp

SafariBoard.o: src/model/safari/SafariBoard.hpp src/model/safari/SafariBoard.cpp src/model/Board.hpp src/model/Piece.hpp
	$(GCC) -c src/model/safari/SafariBoard.cpp

SafariPiece.o: src/model/safari/SafariPiece.hpp src/model/safari/SafariPiece.cpp src/model/Piece.hpp
	$(GCC) -c src/model/safari/SafariPiece.cpp

SafariConfig.o: src/model/safari/SafariConfig.cpp src/model/safari/SafariConfig.hpp src/model/GameConfig.hpp
	$(GCC) -c src/model/safari/SafariConfig.cpp

testSaf: src/model/safari/TestSafari.cpp SafariPiece.o SafariBoard.o Utilities.o
	$(GCC) src/model/safari/TestSafari.cpp SafariPiece.o SafariBoard.o Utilities.o -o TestSaf.exe $(SFML_FLAGS)

test: src/main.cpp SafariPiece.o SafariBoard.o SafariConfig.o Safari.o Controller.o MenuState.o PlayerState.o GameState.o ButinState.o SafariState.o StateMachine.o InputManager.o ResourceManager.o Player.o ButinPiece.o ButinBoard.o ButinConfig.o Butin.o Utilities.o src/settings/SETTINGS.hpp
	$(GCC) src/main.cpp SafariPiece.o SafariBoard.o SafariConfig.o Safari.o Controller.o MenuState.o PlayerState.o GameState.o ButinState.o SafariState.o StateMachine.o InputManager.o ResourceManager.o Player.o ButinPiece.o ButinBoard.o ButinConfig.o Butin.o Utilities.o -o Tesssttt.exe $(SFML_FLAGS)

clean:
	$(info Cleaning the scene...)
	rm *.o