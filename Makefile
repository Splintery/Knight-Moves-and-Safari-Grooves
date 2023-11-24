GCC=g++ --std=c++11 -Wall
SFML_FLAGS=-lsfml-graphics -lsfml-window -lsfml-system
VIEW_CPP=src/view/InputManager.hpp src/view/StateMachine.hpp src/view/ResourceManager.hpp src/view/State.hpp

all: test clean

InputManager.o: src/view/InputManager.cpp src/view/InputManager.hpp
	$(GCC) -c src/view/InputManager.cpp $(SFML_FLAGS)

StateMachine.o: src/view/StateMachine.cpp src/view/StateMachine.hpp src/view/State.hpp
	$(GCC) -c src/view/StateMachine.cpp $(SFML_FLAGS)

ResourceManager.o: src/view/ResourceManager.cpp src/view/ResourceManager.hpp
	$(GCC) -c src/view/ResourceManager.cpp $(SFML_FLAGS)

MenuState.o: src/view/MenuState.cpp src/view/MenuState.hpp src/controller/Controller.hpp src/view/StateMachine.hpp src/view/State.hpp src/view/InputManager.hpp src/view/ResourceManager.hpp src/settings/SETTINGS.hpp
	$(GCC) -c src/view/MenuState.cpp $(SFML_FLAGS)

PlayerState.o: src/view/PlayerState.cpp src/view/PlayerState.hpp $(VIEW_CPP) src/controller/Controller.hpp src/settings/SETTINGS.hpp
	$(GCC) -c src/view/PlayerState.cpp $(SFML_FLAGS)

Controller.o: src/controller/Controller.cpp src/controller/Controller.hpp $(VIEW_CPP) src/view/MenuState.hpp src/view/PlayerState.hpp src/settings/SETTINGS.hpp
	$(GCC) -c src/controller/Controller.cpp $(SFML_FLAGS)

Butin.o: src/model/Butin.cpp src/model/Butin.hpp src/model/Game.hpp src/model/Player.hpp src/model/Board.hpp src/model/Piece.hpp src/model/ButinBoard.hpp
	$(GCC) -c src/model/Butin.cpp

ButinBoard.o: src/model/ButinBoard.cpp src/model/ButinBoard.hpp src/model/ButinPiece.hpp src/model/Piece.hpp src/utilities/Utilities.hpp src/model/Board.hpp
	$(GCC) -c src/model/ButinBoard.cpp

ButinPiece.o: src/model/ButinPiece.cpp src/model/ButinPiece.hpp src/model/Piece.hpp
	$(GCC) -c src/model/ButinPiece.cpp

Player.o: src/model/Player.cpp src/model/Player.hpp
	$(GCC) -c src/model/Player.cpp

test: src/main.cpp Controller.o MenuState.o PlayerState.o StateMachine.o InputManager.o ResourceManager.o Player.o ButinPiece.o ButinBoard.o Butin.o src/settings/SETTINGS.hpp
	$(GCC) src/main.cpp Controller.o MenuState.o PlayerState.o StateMachine.o InputManager.o ResourceManager.o Butin.o Player.o ButinPiece.o ButinBoard.o -o Tesssttt $(SFML_FLAGS)

clean:
	$(info Cleaning the scene...)
	rm *.o