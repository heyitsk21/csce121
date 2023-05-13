#include <iostream>

bool f(bool x, bool y, bool z) {
  /*
  cout << " x | y | z | () (y OR z)" << endl;
  cout << "---+---+---+---------------" << endl;
  cout << " 0 | 0 | 0 |   0" << endl;
  cout << " 0 | 0 | 1 |   1" << endl;
  cout << " 0 | 1 | 0 |   1" << endl;
  cout << " 0 | 1 | 1 |   1" << endl;
  cout << " 1 | 0 | 0 |   1" << endl;
  cout << " 1 | 0 | 1 |   0" << endl;
  cout << " 1 | 1 | 0 |   0" << endl;
  cout << " 1 | 1 | 1 |   1" << endl;
  */



  // write your code to compute f(x,y,z) here
  bool value = (x ^ (y || z)); // TODO: change this line
  return value;
}