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

PlayerState.o: src/view/PlayerState.cpp src/view/PlayerState.hpp $(VIEW_CPP) src/controller/Controller.hpp src/settings/SETTINGS.hpp src/view/ButinState.hpp
	$(GCC) -c src/view/PlayerState.cpp $(SFML_FLAGS)

GameState.o: src/view/GameState.cpp src/view/GameState.hpp $(VIEW_CPP) src/controller/Controller.hpp src/settings/SETTINGS.hpp
	$(GCC) -c src/view/GameState.cpp $(SFML_FLAGS)

ButinState.o: src/view/ButinState.cpp src/view/ButinState.hpp $(VIEW_CPP) src/view/GameState.hpp src/controller/Controller.hpp src/settings/SETTINGS.hpp src/model/ButinConfig.hpp
	$(GCC) -c src/view/ButinState.cpp $(SFML_FLAGS)

Controller.o: src/controller/Controller.cpp src/controller/Controller.hpp $(VIEW_CPP) src/view/MenuState.hpp src/view/PlayerState.hpp src/settings/SETTINGS.hpp
	$(GCC) -c src/controller/Controller.cpp $(SFML_FLAGS)

Butin.o: src/model/Butin.cpp src/model/Butin.hpp src/model/Game.hpp src/model/Player.hpp src/model/Board.hpp src/model/Piece.hpp src/model/ButinBoard.hpp
	$(GCC) -c src/model/Butin.cpp

ButinBoard.o: src/model/ButinBoard.cpp src/model/ButinBoard.hpp src/model/Board.hpp src/model/Piece.hpp
	$(GCC) -c src/model/ButinBoard.cpp

ButinPiece.o: src/model/ButinPiece.cpp src/model/ButinPiece.hpp src/model/Piece.hpp
	$(GCC) -c src/model/ButinPiece.cpp

ButinConfig.o: src/model/ButinConfig.cpp src/model/ButinConfig.hpp src/model/GameConfig.hpp
	$(GCC) -c src/model/ButinConfig.cpp

Player.o: src/model/Player.cpp src/model/Player.hpp
	$(GCC) -c src/model/Player.cpp

test: src/main.cpp Controller.o MenuState.o PlayerState.o GameState.o ButinState.o StateMachine.o InputManager.o ResourceManager.o Player.o ButinPiece.o ButinBoard.o Butin.o ButinConfig.o Utilities.o src/settings/SETTINGS.hpp
	$(GCC) src/main.cpp Controller.o MenuState.o PlayerState.o GameState.o ButinState.o StateMachine.o InputManager.o ResourceManager.o Butin.o Player.o ButinPiece.o ButinBoard.o ButinConfig.o Utilities.o -o Tesssttt.exe $(SFML_FLAGS)

clean:
	$(info Cleaning the scene...)
	rm *.o