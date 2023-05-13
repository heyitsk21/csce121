#ifndef ICA_H
#define ICA_H

#include <vector>
#include <cstdint>

unsigned factorial_trace(unsigned n, size_t depth=0);
size_t binary_search_trace(const std::vector<int>& v, const int& key, size_t begin = 0, size_t end = -1, size_t depth=0);
unsigned fibonacci_trace(int n, size_t depth=0);
void hanoi(unsigned n=3, char src='A', char dest='C', char aux='B');

#endif  // ICA_H