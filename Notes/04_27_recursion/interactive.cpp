#include <iostream>
#include <random>
#include <algorithm>
#include "ica.h"

#ifndef debug
#define debug(x) cout << "[DEBUG] (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ") " << #x << " := " << (x) << endl;
#endif

#define here cout << __FUNCTION__ << ":" << __LINE__ << endl;\

using std::cout, std::endl, std::cin;

void print_menu() {
    cout << "(1) factorial" << endl;
    cout << "(2) binary search" << endl;
    cout << "(3) fibonacci" << endl;
    cout << "(4) towers of hanoi" << endl;
    cout << "(5) quit" << endl;
}

unsigned get_choice() {
    print_menu();
    cout << "choice> ";
    unsigned n;
    cin >> n;
    return n;
}

std::vector<int> sorted_random_vector(size_t N, int min=0, int max=INT32_MAX) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
    std::vector<int> v(N);
    for (size_t n = 0; n < N; ++n) v.at(n) = distrib(gen);
    std::sort(v.begin(), v.end());
    return v;
}

void interactive_mode() {
    const unsigned FACTORIAL = 1;
    const unsigned BINARY_SEARCH = 2;
    const unsigned FIBONACCI = 3;
    const unsigned TOWERS_OF_HANOI = 4;
    const unsigned QUIT = 5;
    while (true) {
        unsigned choice = get_choice();
        unsigned n;
        int key;
        std::vector<int> v;
        switch (choice) {
            case FACTORIAL:
            cout << "n? ";
            cin >> n;
            factorial_trace(n);
            break;
            
            case BINARY_SEARCH:
            size_t index;
            cout << "n? ";
            cin >> n;
            cout << "index? ";
            cin >> index;
            v = sorted_random_vector(n);
            key = v.at(index);
            binary_search_trace(v, key);
            break;
            
            case FIBONACCI:
            cout << "n? ";
            cin >> n;
            fibonacci_trace(n);
            break;
            
            case TOWERS_OF_HANOI:
            cout << "n? ";
            cin >> n;
            hanoi(n);
            break;
            
            default:
            case QUIT:
            cout << "goodbye" << endl;
            return;
        }
    }
}

int main() {
    interactive_mode();
}