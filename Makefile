# Project name and version
PROJECT = scheduler
VERSION = 0.0.1

# Define the build, source and include directories
BUILD_DIR = build
SRC_DIR = src
INC_DIR = include

# Target binary
TARGET = $(BUILD_DIR)/$(PROJECT)

# List of C++ source files
SOURCES = $(wildcard $(SRC_DIR)/*.cpp)

# List header files
HEADERS = $(wildcard $(INC_DIR)/*.hpp)

# Locate object files
OBJECTS = $(SOURCES:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)

# Includes and Libs
INCS = -I$(INC_DIR)/
LIBS =

# Warnings and Macros
WARNINGS = -Wall -Wpedantic -Wextra -Wno-deprecated-declarations
MACROS   =

# Define variables for compiler and flags
CXX = c++
CXXFLAGS = -std=c++20 $(INCS) $(MACROS) $(WARNINGS)
LDFLAGS  = -lstdc++ $(LIBS)

all: options $(TARGET) $(COMPILE_COMMANDS)

options:
	@echo "Build options:"
	@echo "CXX      = $(CXX)"
	@echo "CXXFLAGS = $(CXXFLAGS)"
	@echo "LDFLAGS  = $(LDFLAGS)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@mkdir -p build
	@echo "Compiling $@"
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Done."

$(TARGET): $(OBJECTS)
	@mkdir -p build
	@echo "Linking $@"
	$(CXX) $(LDFLAGS) $^ -o $@
	@echo "Finished!"

run: $(TARGET)
	./$(TARGET)

clean:
	@rm -f $(TARGET) $(OBJECTS)

.PHONY: all options $(BUILD_DIR)/%.o $(TARGET) run
