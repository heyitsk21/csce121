#include <iostream>
#include <string>
#include <sstream>
#include "functions.h"
using std::cin, std::cout, std::endl, std::string, std::istringstream;

int main() {
  // prompt user input
  cout << "Type RPN expression (end with '=')." << endl;
  cout << "> ";
  
  //TODO: create a command-line interface for calculator GUI
  Stack s;

  for (int i = 0; i < 500; ++i)
    push(s, i);

  delete[] s.numbers;


  return 0;
}