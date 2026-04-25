#pragma once

#include <string>
#include <utility>
#include <vector>

namespace hughesc {

// Reads two strings from disk (first non-empty line, second non-empty line).
std::pair<std::string, std::string> readTwoStrings(const std::string& path);

// Reads an integer count N, then N strings (one per line, after skipping blank lines).
std::vector<std::string> readMultiStrings(const std::string& path);

}  // namespace hughesc
