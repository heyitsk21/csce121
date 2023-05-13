/*

target tasks for today:
    * recursion
        + recursive functions in math
            - base case
            - recursive step
        + recursive functions in code
            - base case
            - recursive step

    * get ica starter code from https://github.tamu.edu/pcr/csce-12x-spring22

    * take the recursion ICA quiz: https://docs.google.com/forms/d/e/1FAIpQLSclNtbApezxq3ZszqdJCaxOvM96VYr_334AAeycPP4x_6G-cA/viewform?usp=sf_link

    * use the remaining time to practice your recursion skills by working on the ICA functions (practice tracing recursive functions)

supplementary content
    recursion overview [11:08] (Prof. Moore)
    https://www.youtube.com/watch?v=sLASkoBEUEg

    tracing recursive functions [15:30] (Prof. Ritchey)
    https://www.youtube.com/watch?v=SstKcPew-ro

    recursive binary search [7:26] (Yulin Zhang)
    https://www.youtube.com/watch?v=RMfCAMWPq0M

    recursion example: exponentiation, slow and fast [16:34] (Prof. Ritchey)
    https://www.youtube.com/watch?v=faFv9GHbz2o

    visualizing recursion tool
    https://visualgo.net/en/recursion
*/

#include <iostream>
#include <random>

#ifndef debug
#define debug(x) cout << "[DEBUG] (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ") " << #x << " := " << (x) << endl;
#endif

#define here cout << __FUNCTION__ << ":" << __LINE__ << endl;\

using std::cout, std::endl, std::cin;

/*
MATH
----
n! (factorial)

base case: n = 0
0! = 1

recursive step: n > 0
n! = n * (n-1)!
*/

// CODE
// ----
unsigned factorial(unsigned n) {
    //debug(n)
    // base case
    if (n == 0) return 1;
    // recursive step
    return n * factorial(n - 1);
}

/*
MATH
----
fibonacci

base case: n = 0, 1
f_0 = 0
f_1 = 1

recursive step: n > 1
f_n = f_{n-1} + f_{n-2}
*/

// CODE
// ----
unsigned fibonacci(unsigned n) {
    //debug(n)
    // base case
    if (n < 2) return n;
    // recursive step
    return fibonacci(n-1) + fibonacci(n-2);
}

/*
COMPUTING
---------
binary search
input: list L - a list of integers sorted in ascending order to search
       integer key - the value to find in the list
       non-negative integer begin - the inclusive left boundary of the search region
       non-negative integer end - the exclusive right boundary of the search region
output: the index of key in L, or -1 if key not in L

base case: begin >= end
key not in L => return -1

recursive step: begin < end
let middle value be the value in the middle of the search range (i.e. halfway between begin and end)
if key < middle value => return result of search on left half of list
else if key > middle value => return result of search on right half of list
else return middle index
*/

// CODE
// ----
#include <vector>
size_t binary_search(const std::vector<int>& L, const int& key, size_t begin, size_t end) {
    //debug(key)
    //debug(begin)
    //debug(end)
    // base case
    if (begin >= end) return -1;
    // recursive step
    size_t middle_index = (begin + end) / 2;
    if (key < L.at(middle_index)) return binary_search(L, key, begin, middle_index);
    else if (key > L.at(middle_index)) return binary_search(L, key, middle_index+1, end);
    else return middle_index;
}

/*
COMPUTING
---------
mergesort
input: list L - a list of integers to sort
       non-negative integer begin - the inclusive left boundary of the sort region
       non-negative integer end - the exclusive right boundary of the sort region
output: L sorted in ascending order

base case: length of sort region is <= 1
an empty or singleton list is sorted

recursive step: length of sort region >= 2
mergesort left half of sort region
mergesort right half of sort region
merge sorted left and right halves
*/

// CODE
// ----
void merge(std::vector<int>&, size_t, size_t, size_t);

void mergesort(std::vector<int>& L, size_t begin, size_t end) {
    // base case
    if (end == 0 || begin >= end - 1) return;
    // recursive step
    size_t middle = (begin + end) / 2;
    mergesort(L, begin, middle);
    mergesort(L, middle, end);
    merge(L, begin, middle, end);
}


void merge(std::vector<int>& L, size_t begin, size_t middle, size_t end) {
    std::vector<int> M(end-begin);
    size_t i = begin, j = middle, k = 0;
    while (i < middle && j < end) M.at(k++) = L.at(i) <= L.at(j) ? L.at(i++) : L.at(j++);
    while (i < middle) M.at(k++) = L.at(i++);
    while (j < end) M.at(k++) = L.at(j++);
    k = begin;
    for (int& n : M) L.at(k++) = n;
}

std::vector<int> random_vector(size_t N, int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
    std::vector<int> v(N);
    for (size_t n = 0; n < N; ++n) v.at(n) = distrib(gen);
    return v;
}

std::ostream& operator<<(std::ostream& os, const std::vector<int>& v) {
    os << "[";
    bool comma = false;
    for (int n : v) {
        if (!comma) comma = true;
        else os << ", ";
        os << n;
    }
    os << "]";
    return os;
}

int main() {

    // expect 120
    debug(factorial(5))
    
    // expect 13
    debug(fibonacci(7))

    std::vector<int> v(1000);
    for (size_t n = 0; n < v.size(); n++) v.at(n) = (int)n;
    // expect 121
    debug(binary_search(v, 121, 0, v.size()))
    // expect -1 (UINT32_MAX)
    debug(binary_search(v, -1, 0, v.size()))

    v = random_vector(10,-10,10);
    debug(v)
    mergesort(v, 0, v.size());
    debug(v)
    
    return 0;
}