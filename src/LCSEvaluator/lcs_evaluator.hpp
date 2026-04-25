#pragma once

#include <string>
#include <utility>
#include <vector>

namespace hughesc {

struct Part1Result {
    std::string x;
    std::string y;
    int lcs_length{};
    std::string lcs_subsequence;
};

// Full (m+1)*(n+1) table in a single flattened vector; traceback uses c only (no b array).
Part1Result evaluatePart1FullMatrix(const std::string& x, const std::string& y);

// LCS length using two rows of length (cols), where cols = y.size() + 1.
int lcsLengthTwoRow(const std::string& x, const std::string& y);

// Upper-triangle pairwise LCS lengths for i < j.
std::vector<std::vector<int>> pairwiseLcsLengths(const std::vector<std::string>& strings);

// Similarity label H/M/L/D per specification (strict floating-point; best tier wins).
char classifySimilarity(const std::string& a, const std::string& b, int lcs_length);

void printPart2SimilarityTable(const std::vector<std::string>& strings,
                               const std::vector<std::vector<int>>& lcs_table);

}  // namespace hughesc
