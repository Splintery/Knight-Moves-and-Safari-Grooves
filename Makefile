GCC=g++ --std=c++11 -Wall
SFML_FLAGS=-lsfml-graphics -lsfml-window -lsfml-system

all: test clean

InputManager.o: src/view/InputManager.cpp src/view/InputManager.hpp
	$(GCC) -c src/view/InputManager.cpp $(SFML_FLAGS)

StateMachine.o: src/view/StateMachine.cpp src/view/StateMachine.hpp src/view/State.hpp
	$(GCC) -c src/view/StateMachine.cpp $(SFML_FLAGS)

MenuState.o: src/view/MenuState.cpp src/view/MenuState.hpp src/controller/Controller.hpp src/view/StateMachine.hpp src/view/State.hpp src/view/InputManager.hpp src/settings/SETTINGS.hpp
	$(GCC) -c src/view/MenuState.cpp $(SFML_FLAGS)

Controller.o: src/controller/Controller.cpp src/controller/Controller.hpp src/view/StateMachine.hpp src/view/State.hpp src/view/InputManager.hpp src/view/MenuState.hpp src/settings/SETTINGS.hpp
	$(GCC) -c src/controller/Controller.cpp

Butin.o: src/model/Butin.cpp src/model/Butin.hpp src/model/Game.hpp src/model/Player.hpp src/model/Board.hpp src/model/Tile.hpp src/model/Piece.hpp src/model/ButinBoard.hpp
	$(GCC) -c src/model/Butin.cpp

ButinBoard.o: src/model/ButinBoard.cpp src/model/ButinBoard.hpp src/model/Board.hpp src/model/Tile.hpp src/model/Piece.hpp
	$(GCC) -c src/model/ButinBoard.cpp

Tile.o: src/model/Tile.cpp src/model/Tile.hpp src/model/Piece.hpp
	$(GCC) -c src/model/Tile.cpp

ButinPiece.o: src/model/ButinPiece.cpp src/model/ButinPiece.hpp src/model/Piece.hpp
	$(GCC) -c src/model/ButinPiece.cpp

Player.o: src/model/Player.cpp src/model/Player.hpp
	$(GCC) -c src/model/Player.cpp

test: src/main.cpp Controller.o MenuState.o StateMachine.o InputManager.o Player.o ButinPiece.o Tile.o ButinBoard.o Butin.o src/settings/SETTINGS.hpp
	$(GCC) src/main.cpp Controller.o MenuState.o StateMachine.o InputManager.o -o Tesssttt $(SFML_FLAGS)

clean:
	$(info Cleaning the scene...)
	rm *.o