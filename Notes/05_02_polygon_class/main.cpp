#include <iostream>
#include <vector>
#include <tuple>
#include "tests.h"

using std::cout, std::endl;

int main() {
  unsigned pass_cnt = 0, fail_cnt = 0;
  
  test(triangle)
  test(rectangle)
  test(square)

  if (fail_cnt == 0) cout << green << "[PASS]" << reset;
  else if (pass_cnt > 0) cout << yellow << "[PARTIAL]" << reset;
  else cout << red << "[FAIL]" << reset;
  cout << " " << pass_cnt << "/" << (pass_cnt + fail_cnt) <<  " tests passing" << endl;
  
  return fail_cnt;  
}
