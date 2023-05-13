#ifndef TESTS
#define TESTS

#include <iostream>
#include <sstream>
#include "terminal_colors.h"

#define to_be ==
#define not_to_be !=
#define is to_be
#define is_not not_to_be

#define END_TEST bool this_test_passed = test_passed;\
test_passed = true;\
return this_test_passed;

#define expect(X) try {\
  if (!(X)) {\
    std::cout << red "  [fail]" reset " (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ") " << red << "expected " << #X << "." << reset << std::endl;\
    test_passed = false;\
  }\
} catch(...) {\
  std::cout << red "  [fail]" reset " (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ") " << red << #X << " threw an unexpected exception." << reset << std::endl;\
  test_passed = false;\
}

#define expect_eq(X,Y) {\
  bool save_test_passed = test_passed;\
  {\
    bool test_passed = true;\
    expect(X to_be Y)\
    if (!test_passed) {\
      std::cout << "    " << #X << " :=" << endl << X << endl;\
      std::cout << "    " << #Y << " :=" << endl << Y << endl;\
      save_test_passed = false;\
    }\
  }\
  test_passed = save_test_passed;\
}

#define assert(X) try {\
  if (!(X)) {\
    std::cout << red "  [fail]" reset " (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ") " << red << "failed assertion that " << #X << "." << reset << std::endl;\
    test_passed = false;\
    END_TEST;\
  }\
} catch(...) {\
  std::cout << red "  [fail]" reset " (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ") " << red << #X << " assertion threw an unexpected exception." << reset << std::endl;\
  test_passed = false;\
  END_TEST;\
}

#define expect_throw(X,E) {\
  bool threw_expected_exception = false;\
  try { X; }\
  catch(const E& err) {\
    threw_expected_exception = true;\
  } catch(...) {\
    std::cout << blue << "  [help] " << #X << " threw an incorrect exception." << reset << std::endl;\
  }\
  if (!threw_expected_exception) {\
    std::cout << red <<"  [fail]" << reset << " (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ") " << red << "expected " << #X << " to throw " << #E <<"." << reset <<std::endl;\
    test_passed = false;\
  }\
}

#define expect_no_throw(X) {\
  try { X; }\
  catch(...) {\
    std::cout << red << "  [fail]" << red << " (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ") " << red << "expected " << #X << " not to throw an excpetion." << reset << std::endl;\
    test_passed = false;\
  }\
}

#define expect_output(X,E) {\
  try {\
    std::ostringstream sout;\
    sout << X;\
    std::string output = sout.str();\
    expect(output to_be E);\
  } catch(...) {\
    std::cout << red "  [fail]" reset " (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ") " << red << #X << " threw an unexpected exception." << reset << std::endl;\
    test_passed = false;\
  }\
}

#define test(x) if (test_##x()) { std::cout << green << "[PASS] "; pass_cnt++; } else { std::cout << red << "[FAIL] "; fail_cnt++; } std::cout << #x << reset << std::endl;
#define skip(x) std::cout << yellow << "[SKIP] " << #x << reset << std::endl; skip_cnt++;

struct redirect_cout {
  std::streambuf* cout_buf;

  redirect_cout(const std::ostream& rout) : cout_buf{std::cout.rdbuf(rout.rdbuf())} {}
  ~redirect_cout() { std::cout.rdbuf(cout_buf); }
  redirect_cout(const redirect_cout&) = delete;
  redirect_cout& operator=(const redirect_cout&) = delete;
};

#endif  // TESTS