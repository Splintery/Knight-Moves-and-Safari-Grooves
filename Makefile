GCC=g++ --std=c++11 -Wall
SFML_FLAGS=-lsfml-graphics -lsfml-window -lsfml-system

all: test

test: src/main.cpp
	$(GCC) src/main.cpp -o Tesssttt $(SFML_FLAGS)

clean:
	echo "cleaning..."