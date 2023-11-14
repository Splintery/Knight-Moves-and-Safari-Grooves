# Compiler
CC= g++
# Compiler flags
CFLAGS= -Wall -std=c++11 -lsfml-graphics -lsfml-window -lsfml-system
# Combined compiler and flags
COMPILE= $(CC) $(CFLAGS)

# Generate list of source files for model, view and controller
MVC_SRC=$(wildcard src/*/*.cpp)
COMMON_SRC=$(wildcard src/*.cpp)

# Generate list of corresponding object files for client, server, and utilities
MODEL_OBJECTS=$(patsubst src/model/%.cpp, build/%.o, $(MVC_SRC))
VIEW_OBJECTS=$(patsubst src/view/%.cpp, build/%.o, $(MVC_SRC))
CONTROLLER_OBJECTS=$(patsubst src/controller/%.cpp, build/%.o, $(MVC_SRC))
COMMON_OBJECTS=$(patsubst src/%.cpp, build/%.o, $(COMMON_SRC))

# Rules for building model, view and controller object files with corresponding header files
build/%.o: src/model/%.cpp src/model/%.hpp
	mkdir -p build
	$(COMPILE) -c $< -o $@

build/%.o: src/view/%.cpp src/view/%.hpp
	mkdir -p build
	$(COMPILE) -c $< -o $@

build/%.o: src/controller/%.cpp src/controller/%.hpp
	mkdir -p build
	$(COMPILE) -c $< -o $@

build/%.o: src/%.cpp src/%.hpp
	mkdir -p build
	$(COMPILE) -c $< -o $@

# Rules for object files without corresponding header files
build/%.o: src/%.cpp
	mkdir -p build
	$(COMPILE) -c $< -o $@

# Build the server binary using the generated object files
build: $(MODEL_OBJECTS) $(VIEW_OBJECTS) $(CONTROLLER_OBJECTS) $(COMMON_OBJECTS)
	$(COMPILE) $^ -o build/main
	@printf "\033[32mYou can now run the executable in build/"

# Alias for the build target
all: clean build

# Remove build artifacts
clean :
	rm -rf build