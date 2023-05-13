#ifndef TESTS_H
#define TESTS_H

#include <iostream>

#define expect(X) try {\
  if (!(X)) {\
    std::cout << "[FAIL] (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ") expected " << #X << "." << std::endl;\
    test_passed = false;\
  }\
} catch(...) {\
  std::cout << "[FAIL] (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ") " << #X << " threw an unexpected exception." << std::endl;\
  test_passed = false;\
}

#define expect_throw(X, E) {\
  bool threw_expected_exception = false;\
  try {\
    X;\
  }\
  catch(const E& err) {\
    threw_expected_exception = true;\
  } catch(...) {\
    std::cout << "[HELP] " << #X << " threw an exception." <<std::endl;\
  }\
  if (!threw_expected_exception) {\
    std::cout << "[FAIL] (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ") expected " << #X << " to throw " << #E << "." << std::endl;\
    test_passed = false;\
  }\
}

#define END_TEST bool this_test_passed = test_passed; test_passed = true; if (this_test_passed) { std::cout << "[PASS] " << __FUNCTION__ << std::endl; } return this_test_passed;

#define is ==
#define is_not !=
#define to_be ==

bool stack_tests();
bool arraylist_tests();

#endif  // TESTS_H