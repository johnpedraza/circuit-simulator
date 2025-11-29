# Compiler
CXX = g++

# wxWidgets config
WX_CONFIG   := /usr/bin/wx-config
WX_CXXFLAGS := $(shell $(WX_CONFIG) --cxxflags)
WX_LIBS     := $(shell $(WX_CONFIG) --libs)

# Compiler flags
CXXFLAGS = -Wall -Iinclude $(WX_CXXFLAGS)

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
	$(CXX) $(CXXFLAGS) $(LVERSION) -o $(TARGET) $(OBJS) $(WX_LIBS)

# Compile .cpp files into .o files
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $(LVERSION) -c $< -o $@

# Remove target executable and all object files
clean:
	rm $(TARGET) $(OBJS)
