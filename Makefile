CXX=g++
CXXFLAGS=-std=c++11 -Wall -Wextra -pedantic -O2 -g

SRC_DIR=src
BIN_DIR=bin

PROGRAM=$(BIN_DIR)/program

SRCS=$(wildcard $(SRC_DIR)/*.cpp)
OBJS=$(patsubst $(SRC_DIR)/%.cpp,$(BIN_DIR)/%.o,$(SRCS))

.PHONY: all clean run

all: $(PROGRAM)

$(PROGRAM): $(OBJS)
	$(CXX) $(CXXFLAGS) -I./include -o $@ $^ -lgmpxx -lgmp -lpng

$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -I./include -o $@ -c $<

clean:
	rm -f $(BIN_DIR)/*
	rm -r $(BIN_DIR)
	mkdir $(BIN_DIR)
	touch $(BIN_DIR)/.gitkeep

run: $(PROGRAM)
	$(PROGRAM) $(ARGS)
