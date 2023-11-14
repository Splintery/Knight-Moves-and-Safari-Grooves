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

test: src/main.cpp Controller.o MenuState.o StateMachine.o InputManager.o src/settings/SETTINGS.hpp
	$(GCC) src/main.cpp Controller.o MenuState.o StateMachine.o InputManager.o -o Tesssttt $(SFML_FLAGS)

clean:
	$(info Cleaning the scene...)
	rm *.o