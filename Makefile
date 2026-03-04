CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Iinclude -I/opt/homebrew/include -g
LDFLAGS = -L/opt/homebrew/lib -lgtest -lgtest_main -lgmock -pthread

SRC_DIR = src
OBJ_DIR = obj
INC_DIR = include

# For the main application
SRCS = src/Greeter.cpp src/main.cpp
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)
TARGET = app

# For tests
TEST_SRCS = src/CartTest.cc
TEST_OBJS = $(TEST_SRCS:$(SRC_DIR)/%.cc=$(OBJ_DIR)/%.o)
TEST_TARGET = run_tests

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(TEST_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cc | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

clean:
	rm -rf $(OBJ_DIR) $(TARGET) $(TEST_TARGET)

.PHONY: all clean test
