#include <iostream>
#include "tests.h"
#include "functions.h"

using std::cout, std::endl;

int main() {
  bool passing = crop_tests();

  if (passing) {
    cout << "all tests passing" << endl;
  } else {
    cout << "some failed tests" << endl;
  }

  return 0;  
}