#include <iostream>
#include "tests.hpp"

using std::cout, std::endl;

int main() {
  bool passing_all_tests = true;
  
  passing_all_tests &= test_constructor();
  passing_all_tests &= test_push_back();
  passing_all_tests &= test_pop_back();
  passing_all_tests &= test_back();

  passing_all_tests &= test_reserve();
  passing_all_tests &= test_resize();
  
  passing_all_tests &= test_at();
  passing_all_tests &= test_front();
  passing_all_tests &= test_empty();
  passing_all_tests &= test_shrink_to_fit();
  passing_all_tests &= test_clear();
  passing_all_tests &= test_insert();
  passing_all_tests &= test_erase();

  passing_all_tests &= test_rule_of_three();
  passing_all_tests &= integration_test();
  passing_all_tests &= test_iterator();

  if (passing_all_tests) {
    cout << "ALL TESTS PASSING" << endl;
  }
}