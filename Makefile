CXX = g++
CXXFLAGS = -Wall -Wextra -g

BUILD = ./build
OBJ_DIR := $(BUILD)/obj
TEST_DIR := $(BUILD)/tests
BIN_DIR := $(BUILD)/bin
TEST_BIN_DIR := $(TEST_DIR)/bin

INCLUDE := -Iinclude
SRC := $(wildcard src/*.cpp)
TEST_SRC := $(wildcard tests/*.cpp)
OBJS := $(SRC:%.cpp=$(OBJ_DIR)/%.o)
TESTS := $(TEST_SRC:%.cpp=$(TEST_DIR)/%.o)

TEST_MAIN := test

# @D here means the directory part of the filename of the target with the trailing slash removed.
# Example. If used for a file with path 'src/file.cpp' it's value would be 'src'
# $@ --> the name of the target
# $< --> the first prerequisite
$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(TEST_DIR)/%.o: %.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $@ -c $<

$(TEST_BIN_DIR)/$(TEST_MAIN): $(TESTS)
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -o $(TEST_BIN_DIR)/$(TEST_MAIN) $(TESTS)

tests: $(TEST_BIN_DIR)/$(TEST_MAIN)

clean:
	@echo "Cleaning..."
	@rm -rf build

.PHONY: clean