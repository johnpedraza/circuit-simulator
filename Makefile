# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -Iinclude -I/usr/local/include

# C++ Language Version
LVERSION := -std=c++23

# Target executable
TARGET = Simulator

# Put object files here
BUILD_DIR := ./build

# Source code here
SRC_DIR := ./src

# Source files
SRCS = Resistor.cpp Circuit.cpp Simulator.cpp

# Object files
# Same name as source files, but with .o extension and in build directory
OBJS = $(SRCS:%.cpp=$(BUILD_DIR)/%.o)

# Link object files into target executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $(LVERSION) -o $(TARGET) $(OBJS)

# Compile .cpp files into .o files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(LVERSION) -c $< -o $@

# WebAssembly
wasm:
	emcc $(CXXFLAGS) $(LVERSION) -o build_wasm/circuit.js src/* --embed-file netlist.txt -s NO_EXIT_RUNTIME=1 -s EXPORTED_RUNTIME_METHODS=ccall,cwrap
	# cp build_wasm/* ../johnpedraza.org/

# Remove target executable and all object files
clean:
	rm $(TARGET) $(OBJS)
