#include "functions.h"
using std::cin, std::cout, std::endl, std::ostream, std::string;

#define INFO(X)  cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << endl;
#define INFO_STRUCT(X) cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " count = " << X.count << endl;

/**
 * ----- REQUIRED -----
 * Pushes number to top of stack. If stack is full, then resize stack's array.
 * @param   stack   Target stack.
 * @param   number  Number to push to stack.
 */
void push(Stack& stack, int number) {
  // TODO: implement push function for stack
  INFO_STRUCT(stack);
  INFO(number);
  
  //capacity is how many spaces you can have
  //size is the number of spaces currently being used

  //segfault = going out of bounds (0 is returned in gradescope)

  //c++ deletes off the stack whenever the function finishes
  //the heap's memory will stay

  ///////////int oldcapacity = stack.capacity;

  //only resize (double the capacity) when you run out of space
  if(++stack.count > stack.capacity){
    //change the capacity
    stack.capacity *= 2;

    //make new pointer to new array in the heap
    int* numbers2 = new int[stack.capacity]; //{};

    //repopulate the new array with the data from the old array
    std::copy(stack.numbers, stack.numbers + stack.count - 1, numbers2);
    /*
    for (int i = 0; i < stack.count - 1; i++){
      numbers2[i] = stack.numbers[i];
    }
    */

    // Delete old pointer
    delete[] stack.numbers;

    //point the old pointer to the new array
    stack.numbers = numbers2; 
  }

    //add the input value where the old array ended
    //PRE INCREMENT
    //
    /*
    POST INCREMENT
    numbers2[count+1] = number;
    stack.count += 1;
    */
  stack.numbers[stack.count - 1] = number;
}

/**
 * ----- REQUIRED -----
 * Pops number from top of stack. If stack is empty, return INT32_MAX.
 * @param   stack   Target stack.
 * @return          Value of popped number.
 */
int pop(Stack& stack) {
  // TODO: implement pop function for stack
  INFO_STRUCT(stack);

  if (stack.count <= 0){
    return INT32_MAX;
  }

  int answer;

  //make new pointer to new array in the heap
  int* numbers2 = new int[stack.capacity];

  //repopulate the new array with the data from the old array except for last element
  std::copy(stack.numbers, stack.numbers + stack.count - 1, numbers2);

  stack.count -= 1;
  answer = stack.numbers[stack.count];

  // Delete old pointer
  delete[] stack.numbers;

  //point the old pointer to the new array
  stack.numbers = numbers2;
  
  return answer;
}

/**
 * ----- OPTIONAL -----
 * Returns the number at top of stack without popping it. If stack is empty, return INT32_MAX.
 * @param   stack   Target statck.
 * @return          Number at top of stack.
 */
int peek(const Stack& stack) {
  // TODO (optional): implement peek function for stack
  INFO_STRUCT(stack);
  
  if (stack.count <= 0){
    return INT32_MAX;
  }

  return stack.numbers[stack.count-1];
}
