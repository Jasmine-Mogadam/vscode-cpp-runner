CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude -I/opt/homebrew/include -g
LDFLAGS = -L/opt/homebrew/lib -lgtest -lgtest_main -pthread

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

# Regular source files (excluding tests)
SRCS = $(filter-out %_test.cc, $(wildcard $(SRC_DIR)/*.cpp $(SRC_DIR)/*.cc))
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
OBJS := $(OBJS:$(SRC_DIR)/%.cc=$(OBJ_DIR)/%.o)

# Test source files
TEST_SRCS = $(wildcard $(SRC_DIR)/*_test.cc)
TEST_OBJS = $(TEST_SRCS:$(SRC_DIR)/%.cc=$(OBJ_DIR)/%.o)
TEST_TARGET = run_tests

TARGET = app

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule for .cpp files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Rule for .cc files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Test target
test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

clean:
	rm -rf $(OBJ_DIR) $(TARGET) $(TEST_TARGET)

.PHONY: all clean test
