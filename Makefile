# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Iinclude

# C++ Language Version
LVERSION := -std=c++23

# Target executable
TARGET = CircuitSimulator

# Put object files here
BUILD_DIR := ./build

# Source code here
SRC_DIR := ./src

# Source files
SRCS = Resistor.cpp Circuit.cpp CircuitSimulator.cpp

# Object files
# Same name as source files, but with .o extension and in build directory
OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

# Link object files into target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile .cpp files into .o files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(LVERSION) -c $< -o $@

# Remove target executable and all object files
clean:
	rm $(TARGET) $(OBJS)
