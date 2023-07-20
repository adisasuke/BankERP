# Compiler and flags
CXX := g++
CXXFLAGS := -Wall -Wextra -std=c++11

# Directories
SRC_DIR := src
BIN_DIR := bin

# Source files and corresponding object files
# SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
SRC_FILES := src/main.cpp src/Bst_Tree.cpp src/Bst_Node.cpp
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%.o, $(SRC_FILES))

# The main target (executable)
TARGET := $(BIN_DIR)/main

all: $(TARGET)

# Rule to compile the source files into object files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Rule to link the object files and create the final executable
$(TARGET): $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Run program
run: $(TARGET)
	./$(TARGET)

# Clean rule to remove the generated object files and the final executable
clean:
	rm -f $(OBJ_FILES) $(TARGET)
