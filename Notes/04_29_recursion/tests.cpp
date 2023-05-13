#include <iostream>
#include <sstream>
#include <random>
#include <algorithm>
#include "ica.h"
#include "tests.h"

#ifndef debug
#define debug(x) cout << "[DEBUG] (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ") " << #x << " := " << (x) << endl;
#endif

using std::cout, std::endl;

namespace {
    bool test_passed = true;
}

#define test_case(return_type,function,input,expected_out,expected_ret) {\
    std::ostringstream sout;\
    return_type actual_return;\
    {\
        redirect_cout r(sout);\
        actual_return = function(input);\
    }\
    std::string actual_stdout = sout.str();\
    std::string expected_stdout = expected_out;\
    return_type expected_return = expected_ret;\
    expect_eq(actual_return, expected_return);\
    expect_eq(actual_stdout, expected_stdout);\
}

#define test_case2(return_type,function,size,index,expected_out) {\
    std::ostringstream sout;\
    return_type actual_return;\
    {\
        redirect_cout r(sout);\
        std::vector<int> L = sorted_random_vector(size);\
        int key = L.at(index);\
        actual_return = function(L, key);\
    }\
    std::string actual_stdout = sout.str();\
    std::string expected_stdout = expected_out;\
    return_type expected_return = index;\
    expect_eq(actual_return, expected_return);\
    expect_eq(actual_stdout, expected_stdout);\
}

bool test_factorial() {
    test_case(
        unsigned,
        factorial_trace,
        5,
        "5!\n 4!\n  3!\n   2!\n    1!\n    = 1\n   = 2\n  = 6\n = 24\n= 120\n",
        120
    )

    test_case(
        unsigned,
        factorial_trace,
        10,
        "10!\n 9!\n  8!\n   7!\n    6!\n     5!\n      4!\n       3!\n        2!\n         1!\n         = 1\n        = 2\n       = 6\n      = 24\n     = 120\n    = 720\n   = 5040\n  = 40320\n = 362880\n= 3628800\n",
        3628800
    )

    END_TEST;
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

bool test_binary_search() {
    test_case2(
        size_t,
        binary_search_trace,
        10,
        9,
        "search in [0:10)\n search in [6:10)\n  search in [9:10)\n  found at index 9\n"
    )

    test_case2(
        size_t,
        binary_search_trace,
        100,
        1,
        "search in [0:100)\n search in [0:50)\n  search in [0:25)\n   search in [0:12)\n    search in [0:6)\n     search in [0:3)\n     found at index 1\n"
    )

    test_case2(
        size_t,
        binary_search_trace,
        1000,
        320,
        "search in [0:1000)\n search in [0:500)\n  search in [251:500)\n   search in [251:375)\n    search in [314:375)\n     search in [314:344)\n      search in [314:329)\n       search in [314:321)\n        search in [318:321)\n         search in [320:321)\n         found at index 320\n"
    )

    {
        std::ostringstream sout;
        size_t actual_return;
        {
            redirect_cout r(sout);
            std::vector<int> L = sorted_random_vector(1000);
            int key = -121;
            actual_return = binary_search_trace(L, key);
        }
        std::string actual_stdout = sout.str();
        std::string expected_stdout = "search in [0:1000)\n search in [0:500)\n  search in [0:250)\n   search in [0:125)\n    search in [0:62)\n     search in [0:31)\n      search in [0:15)\n       search in [0:7)\n        search in [0:3)\n         search in [0:1)\n          search in [0:0)\n          not found\n";
        size_t expected_return = -1;
        expect_eq(actual_return, expected_return);
        expect_eq(actual_stdout, expected_stdout);
    }

    END_TEST;
}

bool test_fibonacci() {
    test_case(
        unsigned,
        fibonacci_trace,
        5,
        "        f(1)\n    f(3)\n            f(0)\n        f(2)\n            f(1)\nf(5)\n            f(0)\n        f(2)\n            f(1)\n    f(4)\n            f(1)\n        f(3)\n                f(0)\n            f(2)\n                f(1)\n",
        5
    )

    test_case(
        unsigned,
        fibonacci_trace,
        12,
        "                        f(0)\n                    f(2)\n                        f(1)\n                f(4)\n                        f(1)\n                    f(3)\n                            f(0)\n                        f(2)\n                            f(1)\n            f(6)\n                        f(1)\n                    f(3)\n                            f(0)\n                        f(2)\n                            f(1)\n                f(5)\n                            f(0)\n                        f(2)\n                            f(1)\n                    f(4)\n                            f(1)\n                        f(3)\n                                f(0)\n                            f(2)\n                                f(1)\n        f(8)\n                        f(1)\n                    f(3)\n                            f(0)\n                        f(2)\n                            f(1)\n                f(5)\n                            f(0)\n                        f(2)\n                            f(1)\n                    f(4)\n                            f(1)\n                        f(3)\n                                f(0)\n                            f(2)\n                                f(1)\n            f(7)\n                            f(0)\n                        f(2)\n                            f(1)\n                    f(4)\n                            f(1)\n                        f(3)\n                                f(0)\n                            f(2)\n                                f(1)\n                f(6)\n                            f(1)\n                        f(3)\n                                f(0)\n                            f(2)\n                                f(1)\n                    f(5)\n                                f(0)\n                            f(2)\n                                f(1)\n                        f(4)\n                                f(1)\n                            f(3)\n                                    f(0)\n                                f(2)\n                                    f(1)\n    f(10)\n                        f(1)\n                    f(3)\n                            f(0)\n                        f(2)\n                            f(1)\n                f(5)\n                            f(0)\n                        f(2)\n                            f(1)\n                    f(4)\n                            f(1)\n                        f(3)\n                                f(0)\n                            f(2)\n                                f(1)\n            f(7)\n                            f(0)\n                        f(2)\n                            f(1)\n                    f(4)\n                            f(1)\n                        f(3)\n                                f(0)\n                            f(2)\n                                f(1)\n                f(6)\n                            f(1)\n                        f(3)\n                                f(0)\n                            f(2)\n                                f(1)\n                    f(5)\n                                f(0)\n                            f(2)\n                                f(1)\n                        f(4)\n                                f(1)\n                            f(3)\n                                    f(0)\n                                f(2)\n                                    f(1)\n        f(9)\n                            f(0)\n                        f(2)\n                            f(1)\n                    f(4)\n                            f(1)\n                        f(3)\n                                f(0)\n                            f(2)\n                                f(1)\n                f(6)\n                            f(1)\n                        f(3)\n                                f(0)\n                            f(2)\n                                f(1)\n                    f(5)\n                                f(0)\n                            f(2)\n                                f(1)\n                        f(4)\n                                f(1)\n                            f(3)\n                                    f(0)\n                                f(2)\n                                    f(1)\n            f(8)\n                            f(1)\n                        f(3)\n                                f(0)\n                            f(2)\n                                f(1)\n                    f(5)\n                                f(0)\n                            f(2)\n                                f(1)\n                        f(4)\n                                f(1)\n                            f(3)\n                                    f(0)\n                                f(2)\n                                    f(1)\n                f(7)\n                                f(0)\n                            f(2)\n                                f(1)\n                        f(4)\n                                f(1)\n                            f(3)\n                                    f(0)\n                                f(2)\n                                    f(1)\n                    f(6)\n                                f(1)\n                            f(3)\n                                    f(0)\n                                f(2)\n                                    f(1)\n                        f(5)\n                                    f(0)\n                                f(2)\n                                    f(1)\n                            f(4)\n                                    f(1)\n                                f(3)\n                                        f(0)\n                                    f(2)\n                                        f(1)\nf(12)\n                        f(1)\n                    f(3)\n                            f(0)\n                        f(2)\n                            f(1)\n                f(5)\n                            f(0)\n                        f(2)\n                            f(1)\n                    f(4)\n                            f(1)\n                        f(3)\n                                f(0)\n                            f(2)\n                                f(1)\n            f(7)\n                            f(0)\n                        f(2)\n                            f(1)\n                    f(4)\n                            f(1)\n                        f(3)\n                                f(0)\n                            f(2)\n                                f(1)\n                f(6)\n                            f(1)\n                        f(3)\n                                f(0)\n                            f(2)\n                                f(1)\n                    f(5)\n                                f(0)\n                            f(2)\n                                f(1)\n                        f(4)\n                                f(1)\n                            f(3)\n                                    f(0)\n                                f(2)\n                                    f(1)\n        f(9)\n                            f(0)\n                        f(2)\n                            f(1)\n                    f(4)\n                            f(1)\n                        f(3)\n                                f(0)\n                            f(2)\n                                f(1)\n                f(6)\n                            f(1)\n                        f(3)\n                                f(0)\n                            f(2)\n                                f(1)\n                    f(5)\n                                f(0)\n                            f(2)\n                                f(1)\n                        f(4)\n                                f(1)\n                            f(3)\n                                    f(0)\n                                f(2)\n                                    f(1)\n            f(8)\n                            f(1)\n                        f(3)\n                                f(0)\n                            f(2)\n                                f(1)\n                    f(5)\n                                f(0)\n                            f(2)\n                                f(1)\n                        f(4)\n                                f(1)\n                            f(3)\n                                    f(0)\n                                f(2)\n                                    f(1)\n                f(7)\n                                f(0)\n                            f(2)\n                                f(1)\n                        f(4)\n                                f(1)\n                            f(3)\n                                    f(0)\n                                f(2)\n                                    f(1)\n                    f(6)\n                                f(1)\n                            f(3)\n                                    f(0)\n                                f(2)\n                                    f(1)\n                        f(5)\n                                    f(0)\n                                f(2)\n                                    f(1)\n                            f(4)\n                                    f(1)\n                                f(3)\n                                        f(0)\n                                    f(2)\n                                        f(1)\n    f(11)\n                            f(0)\n                        f(2)\n                            f(1)\n                    f(4)\n                            f(1)\n                        f(3)\n                                f(0)\n                            f(2)\n                                f(1)\n                f(6)\n                            f(1)\n                        f(3)\n                                f(0)\n                            f(2)\n                                f(1)\n                    f(5)\n                                f(0)\n                            f(2)\n                                f(1)\n                        f(4)\n                                f(1)\n                            f(3)\n                                    f(0)\n                                f(2)\n                                    f(1)\n            f(8)\n                            f(1)\n                        f(3)\n                                f(0)\n                            f(2)\n                                f(1)\n                    f(5)\n                                f(0)\n                            f(2)\n                                f(1)\n                        f(4)\n                                f(1)\n                            f(3)\n                                    f(0)\n                                f(2)\n                                    f(1)\n                f(7)\n                                f(0)\n                            f(2)\n                                f(1)\n                        f(4)\n                                f(1)\n                            f(3)\n                                    f(0)\n                                f(2)\n                                    f(1)\n                    f(6)\n                                f(1)\n                            f(3)\n                                    f(0)\n                                f(2)\n                                    f(1)\n                        f(5)\n                                    f(0)\n                                f(2)\n                                    f(1)\n                            f(4)\n                                    f(1)\n                                f(3)\n                                        f(0)\n                                    f(2)\n                                        f(1)\n        f(10)\n                            f(1)\n                        f(3)\n                                f(0)\n                            f(2)\n                                f(1)\n                    f(5)\n                                f(0)\n                            f(2)\n                                f(1)\n                        f(4)\n                                f(1)\n                            f(3)\n                                    f(0)\n                                f(2)\n                                    f(1)\n                f(7)\n                                f(0)\n                            f(2)\n                                f(1)\n                        f(4)\n                                f(1)\n                            f(3)\n                                    f(0)\n                                f(2)\n                                    f(1)\n                    f(6)\n                                f(1)\n                            f(3)\n                                    f(0)\n                                f(2)\n                                    f(1)\n                        f(5)\n                                    f(0)\n                                f(2)\n                                    f(1)\n                            f(4)\n                                    f(1)\n                                f(3)\n                                        f(0)\n                                    f(2)\n                                        f(1)\n            f(9)\n                                f(0)\n                            f(2)\n                                f(1)\n                        f(4)\n                                f(1)\n                            f(3)\n                                    f(0)\n                                f(2)\n                                    f(1)\n                    f(6)\n                                f(1)\n                            f(3)\n                                    f(0)\n                                f(2)\n                                    f(1)\n                        f(5)\n                                    f(0)\n                                f(2)\n                                    f(1)\n                            f(4)\n                                    f(1)\n                                f(3)\n                                        f(0)\n                                    f(2)\n                                        f(1)\n                f(8)\n                                f(1)\n                            f(3)\n                                    f(0)\n                                f(2)\n                                    f(1)\n                        f(5)\n                                    f(0)\n                                f(2)\n                                    f(1)\n                            f(4)\n                                    f(1)\n                                f(3)\n                                        f(0)\n                                    f(2)\n                                        f(1)\n                    f(7)\n                                    f(0)\n                                f(2)\n                                    f(1)\n                            f(4)\n                                    f(1)\n                                f(3)\n                                        f(0)\n                                    f(2)\n                                        f(1)\n                        f(6)\n                                    f(1)\n                                f(3)\n                                        f(0)\n                                    f(2)\n                                        f(1)\n                            f(5)\n                                        f(0)\n                                    f(2)\n                                        f(1)\n                                f(4)\n                                        f(1)\n                                    f(3)\n                                            f(0)\n                                        f(2)\n                                            f(1)\n",
        144
    )

    END_TEST;
}

bool test_hanoi() {
    {
        std::ostringstream sout;
        {
            redirect_cout r(sout);
            hanoi(3);
        }
        std::string actual_stdout = sout.str();
        std::string expected_stdout = "move disk 1 from A to C\nmove disk 2 from A to B\nmove disk 1 from C to B\nmove disk 3 from A to C\nmove disk 1 from B to A\nmove disk 2 from B to C\nmove disk 1 from A to C\n";
        expect_eq(actual_stdout, expected_stdout);
    }

    {
        std::ostringstream sout;
        {
            redirect_cout r(sout);
            hanoi(5);
        }
        std::string actual_stdout = sout.str();
        std::string expected_stdout = "move disk 1 from A to C\nmove disk 2 from A to B\nmove disk 1 from C to B\nmove disk 3 from A to C\nmove disk 1 from B to A\nmove disk 2 from B to C\nmove disk 1 from A to C\nmove disk 4 from A to B\nmove disk 1 from C to B\nmove disk 2 from C to A\nmove disk 1 from B to A\nmove disk 3 from C to B\nmove disk 1 from A to C\nmove disk 2 from A to B\nmove disk 1 from C to B\nmove disk 5 from A to C\nmove disk 1 from B to A\nmove disk 2 from B to C\nmove disk 1 from A to C\nmove disk 3 from B to A\nmove disk 1 from C to B\nmove disk 2 from C to A\nmove disk 1 from B to A\nmove disk 4 from B to C\nmove disk 1 from A to C\nmove disk 2 from A to B\nmove disk 1 from C to B\nmove disk 3 from A to C\nmove disk 1 from B to A\nmove disk 2 from B to C\nmove disk 1 from A to C\n";
        expect_eq(actual_stdout, expected_stdout);
    }

    END_TEST;
}

int main() {
    unsigned pass_cnt = 0, fail_cnt = 0, skip_cnt = 0;

    test(factorial);
    test(binary_search);
    test(fibonacci);
    test(hanoi);

    cout << endl;
    cout << magenta << "summary:" << reset << endl;
    cout << green << pass_cnt << " tests passing." << reset << endl;
    cout << red << fail_cnt << " tests failing." << reset << endl;
    cout << yellow << skip_cnt << " tests skipped." << reset << endl;

    return 0;
}