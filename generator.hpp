#pragma once
// #define TEST_UTILITIES
#include <string>

namespace gen {
int int_generator(int min, int  max);
std::string s_generator();
std::string from_vector_generator(const std::vector<std::string> &v);
}