# Force -O3 for heavy pairwise LCS workloads (e.g. 20×20 upper triangle).
CXX      := g++
CXXFLAGS := -std=c++17 -O3 -Wall -Wextra -pedantic -I src

SRC := src/main.cpp \
       src/FileHandler/file_handler.cpp \
       src/LCSEvaluator/lcs_evaluator.cpp

OBJ := $(SRC:.cpp=.o)
BIN := hughesc

.PHONY: all clean run-part1 run-part2

all: $(BIN)

$(BIN): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

src/main.o: src/main.cpp src/FileHandler/file_handler.hpp src/LCSEvaluator/lcs_evaluator.hpp
src/FileHandler/file_handler.o: src/FileHandler/file_handler.cpp src/FileHandler/file_handler.hpp
src/LCSEvaluator/lcs_evaluator.o: src/LCSEvaluator/lcs_evaluator.cpp src/LCSEvaluator/lcs_evaluator.hpp

clean:
	rm -f $(OBJ) $(BIN)

run-part1: $(BIN)
	./$(BIN) part1 twoStrings.txt

run-part2: $(BIN)
	./$(BIN) part2 multiStrings.txt
