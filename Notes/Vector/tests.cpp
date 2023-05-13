#include <iostream>
#include "tests.hpp"
#include "vector.hpp"

#define expect(X) try {\
  if(!(X)) {\
    cout<<"[FAIL] ("<<__FILE__<<":"<<__FUNCTION__<<":"<<__LINE__<<") expected "<<#X<<"."<<endl;\
    test_passed = false;\
  }\
} catch(...) {\
  cout<<"[FAIL] ("<<__FILE__<<":"<<__FUNCTION__<<":"<<__LINE__<<") "<<#X<<" threw an unexpected exception."<<endl;\
  test_passed = false;\
}

#define expect_throw(X,E) {\
  bool threw_expected_exception = false;\
  try {\
    X;\
  }\
  catch(const E& err) {\
    threw_expected_exception = true;\
  } catch(...) {\
    cout<<"[HELP] "<<#X<<" threw an exception."<<endl;\
  }\
  if (!threw_expected_exception) {\
    cout<<"[FAIL] ("<<__FILE__<<":"<<__FUNCTION__<<":"<<__LINE__<<") expected "<<#X<<" to throw "<<#E<<"."<<endl;\
    test_passed = false;\
  }\
}

#define pending cout << "[PENDING] " << __FUNCTION__ << endl; return true;

#define END_TEST bool this_test_passed = test_passed; test_passed = true; if (this_test_passed) { cout << "[PASS] " << __FUNCTION__ << endl; } return this_test_passed;

#define is ==
#define to_be ==
#define to_be_not !=
#define not_to_be !=
#define to_be_greater_than >
#define to_be_at_least >=

#define DO_N_TIMES(N,X) for(int n = 0; n < N; ++n) { X; }

using std::cout, std::endl;

namespace {
  bool test_passed = true;
}

bool test_constructor() {
  {
    vector<int> v;
    expect(v.capacity() to_be_greater_than 0);
    expect(v.size() to_be 0);
    expect(v.data() not_to_be nullptr);
  }

  {
    vector<int> v(101);
    expect(v.capacity() to_be_at_least 101);
    expect(v.size() to_be 101);
    expect(v.data() not_to_be nullptr);
    for (size_t index = 0; index < 101; index++) {
      expect(v.data()[index] to_be 0);
    }
  }

  END_TEST
}

bool test_push_back() {
  // push a value onto an empty vector
  {
    vector<int> v;
    // preconditions
    //   underlying array ("A" for short) to_be not null
    //   capacity to_be_greater_than 0
    //   size to_be 0
    expect(v.data() not_to_be nullptr);
    expect(v.capacity() to_be_greater_than 0);
    expect(v.size() to_be 0);

    // expect push_back to succeed
    v.push_back(1);

    // postconditions
    //   A to_be not null
    //   capacity to_be_at_least 1
    //   size to_be 1
    //   A at index 0 to_be 1
    expect(v.data() not_to_be nullptr);
    expect(v.capacity() to_be_at_least 1);
    expect(v.size() to_be 1);
    expect(v.data()[0] to_be 1);
  }

  // push several values onto vector
  {
    vector<int> v(5);
    // preconditions
    //   A to_be not null
    //   capacity to_be_at_least 5
    //   size to_be 0
    for (int i = 0; i < 5; i++) {
      v.pop_back();
    }
    expect(v.data() not_to_be nullptr);
    expect(v.capacity() to_be_at_least 5);
    expect(v.size() to_be 0);
    
    // expect push_back to succeed several times
    for (int i = 1; i <= 5; i++) {
      // pre
      //   size to_be i-1
      //   back to_be i-1 if i to_be_greater_than 1
      expect(v.size() to_be unsigned(i-1));
      if (i > 1) {
        expect(v.data()[i-2] to_be i-1);
      }

      // expect push_back to suceed
      v.push_back(i);

      // post
      //   size to_be i
      //   back to_be i
      expect(v.size() to_be unsigned(i));
      expect(v.data()[i-1] to_be i);
    }
  }

  // push value onto full array
  {
    vector<int> v(3);
    // preconditions
    //   A to_be not null
    //   capacity to_be_at_least 3
    //   vector to_be full (size to_be capacity)
    expect(v.data() not_to_be nullptr);
    expect(v.capacity() to_be 3);
    expect(v.size() to_be v.capacity());
    
    // expect push_back to succeed
    size_t old_capacity = v.capacity();
    v.push_back(2);
    
    // postconditions
    //   A to_be not null
    //   capacity to_be_at_least 2 * old capacity
    //   size to_be old_capacity + 1
    //   A at end (index size-1) to_be 2
    expect(v.data() not_to_be nullptr);
    expect(v.size() to_be old_capacity + 1);
    expect(v.capacity() to_be_at_least 2*old_capacity);
    expect(v.data()[v.size()-1] to_be 2);
  }

  END_TEST
}

bool test_pop_back() {
  // remove element at back
  {
    vector<int> v(10);
    // preconditions
    //   capacity to_be_at_least 10
    //   size = 10
    //   A = {1,2,3,4,5,6,7,8,9,10}
    for (int i = 1; i <= 10; i++) {
      v.data()[i-1] = i;
    }
    expect(v.capacity() to_be_at_least 10);
    expect(v.size() to_be 10);
    expect(v.data()[8] to_be 9);
    expect(v.data()[9] to_be 10);
    // expect pop_back to remove 10
    size_t old_capacity = v.capacity();
    v.pop_back();
    // postconditions
    //   capacity did not change
    //   size to_be 9
    //   A at end to_be 9
    expect(v.capacity() to_be old_capacity);
    expect(v.size() to_be 9);
    expect(v.data()[8] to_be 9);
  }

  // remove all elements
  {
    vector<int> v(10);
    // preconditions
    //   capacity to_be_at_least 10
    //   size = 10
    //   A = {1,2,3,4,5,6,7,8,9,10}
    for (int i = 1; i <= 10; i++) {
      v.data()[i-1] = i;
    }
    expect(v.capacity() to_be_at_least 10);
    expect(v.size() to_be 10);
    for (int i = 1; i <= 10; i++) {
      expect(v.data()[i-1] to_be i);
    }
    // note: expect capacity to not change
    size_t old_capacity = v.capacity();
    for (int i = 10; i > 0; i--) {
      // preconditions
      //   capacity to_be to_be_greater_than 0
      //   size to_be i
      //   A at end to_be i
      expect(v.size() to_be unsigned(i));
      expect(v.data()[i-1] to_be i);
      // expect pop_back to remove i
      v.pop_back();
      // postconditions
      //   capacity did not change
      //   size to_be i-1
      //   A at index i-2 (end) to_be i-1 (if i-2 to_be_at_least 0)
      expect(v.capacity() to_be old_capacity);
      expect(v.size() to_be unsigned(i-1));
      if (i > 1) {
          expect(v.data()[i-2] to_be i-1);
      }
    }
  }

  // attempt to remove from empty
  {
    vector<int> v;
    // preconditions
    //   size to_be 0
    //   A to_be not null
    expect(v.size() to_be 0);
    expect(v.data() not_to_be nullptr);
    size_t old_capacity = v.capacity();
    const int* old_data = v.data();
    
    // expect pop_back to throw out_of_range exception
    expect_throw(v.pop_back(), std::out_of_range);

    // postconditions
    //   size to_be 0
    //   capacity to_be unchanged
    //   A to_be unchanged
    expect(v.size() to_be 0);
    expect(v.capacity() to_be old_capacity);
    expect(v.data() to_be old_data);
  }

  END_TEST
}

bool test_back() {
  // get back of non-empty vector
  {
    vector<int> v(2);
    // pre
    //   A[0] to_be 10
    //   A[1] to_be 11
    //   size to_be 2
    v.data()[0] = 10;
    v.data()[1] = 11;
    expect(v.data()[0] to_be 10);
    expect(v.data()[1] to_be 11);
    expect(v.size() to_be 2);
    
    // expect back to be 11
    expect(v.back() to_be 11);
    
    // post
    //   A[0] to_be 10
    //   A[1] to_be 11
    //   size to_be 2
    expect(v.data()[0] to_be 10);
    expect(v.data()[1] to_be 11);
    expect(v.size() to_be 2);
  }
  
  // attempt to get back of empty vector
  {
    vector<int> v;
    // pre
    //   A to_be not null
    //   size to_be 0
    expect(v.data() not_to_be nullptr);
    expect(v.size() to_be 0);
    size_t old_capacity = v.capacity();
    const int* old_data = v.data(); 
    
    // expect back of empty to throw out_of_range exception
    expect_throw(v.back(), std::out_of_range);
    
    // post
    //   size = 0
    //   capacity to_be unchanged
    //   A to_be changed 
    expect(v.size() to_be 0);
    expect(v.capacity() to_be old_capacity);
    expect(v.data() to_be old_data);
  }

  // back returns lvalue reference (assignable)
  {
    vector<int> v(3);
    // pre
    //   A at 1 to_be not 12
    expect(v.data()[1] to_be_not 12);
    expect(v.size() to_be 3);
    // expect assignment to succeed
    v.back() = 12;
    // post
    //   A at 1 to_be 12, others unchanged
    //   size to_be unchanged
    expect(v.data()[0] to_be 0);
    expect(v.data()[1] to_be 0);
    expect(v.data()[2] to_be 12);
    expect(v.back() to_be 12); // rvalue
    expect(v.size() to_be 3);
  }

  // back of const vector
  {
    const vector<int> v(3);
    expect(v.back() to_be 0);
  }

  // back of const empty vector
  {
    const vector<int> v;
    expect_throw(v.back(), std::out_of_range);
  expect(v.data() not_to_be nullptr);
  }

  END_TEST
}

bool test_reserve() {
  // reserve bigger
  // capacity to_be updated, size to_be not, data pointer to_be updated, data content to_be not 
  {
    vector<int> v(3);
    size_t old_capacity = v.capacity();
    const int* old_data = v.data();
    // preconditions
    //   size to_be 3
    //   capacity to_be_at_least 3
    //   data = {1,2,3}
    v.data()[0] = 1;
    v.data()[1] = 2;
    v.data()[2] = 3;
    expect(v.capacity() to_be_at_least 3);
    expect(v.size() to_be 3);
    expect(v.data()[0] to_be 1);
    expect(v.data()[1] to_be 2);
    expect(v.data()[2] to_be 3);

    // expect reserve to succeed
    v.reserve(old_capacity + 10);

    // postconditions
    //   capacity to_be old capacity + 10
    //   data pointer to_be different
    //   size to_be 3
    //   data = {1,2,3,0,...}
    expect(v.capacity() to_be old_capacity + 10);
    expect(v.data() to_be_not old_data);
    expect(v.size() to_be 3);
    expect(v.data()[0] to_be 1);
    expect(v.data()[1] to_be 2);
    expect(v.data()[2] to_be 3);
    for (size_t index = 3; index < v.capacity(); index++) {
      expect(v.data()[index] to_be 0);
    }
  }

  // reserve smaller
  // do nothing
  {
    vector<int> v(5);
    size_t old_capacity = v.capacity();
    const int* old_data = v.data();
    // preconditions
    //   size to_be 5
    //   capacity to_be_at_least 5
    //   data = {1,2,3,4,5}
    v.data()[0] = 1;
    v.data()[1] = 2;
    v.data()[2] = 3;
    v.data()[3] = 4;
    v.data()[4] = 5;
    expect(v.capacity() to_be_at_least 5);
    expect(v.size() to_be 5);
    expect(v.data()[0] to_be 1);
    expect(v.data()[1] to_be 2);
    expect(v.data()[2] to_be 3);
    expect(v.data()[3] to_be 4);
    expect(v.data()[4] to_be 5);

    // expect reserve to do nothing
    v.reserve(3);

    // postconditions
    //   capacity to_be old capacity
    //   data pointer to_be old data pointer
    //   size to_be 5
    //   data = {1,2,3,4,5}
    expect(v.capacity() to_be old_capacity);
    expect(v.data() to_be old_data);
    expect(v.size() to_be 5);
    expect(v.data()[0] to_be 1);
    expect(v.data()[1] to_be 2);
    expect(v.data()[2] to_be 3);
    expect(v.data()[3] to_be 4);
    expect(v.data()[4] to_be 5);
  }

  END_TEST
}

bool test_resize() {
  // increase size beyond capacity
  {
    vector<int> v(3);
    size_t old_capacity = v.capacity();
    const int* old_data = v.data();
    // preconditions
    //   size to_be 3
    //   capacity to_be_at_least 3
    //   data = {1,2,3}
    v.data()[0] = 1;
    v.data()[1] = 2;
    v.data()[2] = 3;
    expect(v.capacity() to_be_at_least 3);
    expect(v.size() to_be 3);
    expect(v.data()[0] to_be 1);
    expect(v.data()[1] to_be 2);
    expect(v.data()[2] to_be 3);

    // expect resize to succeed
    v.resize(old_capacity + 1);

    // post-conditions
    //   size to_be old_capacity + 1
    //   capacity to_be to_be_at_least size
    //   data pointer to_be new
    //   data = {1,2,3,0,...}
    expect(v.size() to_be old_capacity + 1);
    expect(v.capacity() to_be_at_least v.size());
    expect(v.data() to_be_not old_data);
    expect(v.data()[0] to_be 1);
    expect(v.data()[1] to_be 2);
    expect(v.data()[2] to_be 3);
    for (size_t index = 3; index < v.size(); index++) {
      expect(v.data()[index] to_be 0);
    }
  }

  // increase size within capacity
  {
    vector<int> v(3);
    // preconditions
    //   size to_be 3
    //   capacity to_be 10
    //   data = {1,2,3,-1,...}
    v.reserve(10);
    const int* old_data = v.data();
    v.data()[0] = 1;
    v.data()[1] = 2;
    v.data()[2] = 3;
    for (size_t index = 3; index < v.capacity(); index++) {
      v.data()[index] = -1;
    }
    expect(v.capacity() to_be 10);
    expect(v.size() to_be 3);
    expect(v.data()[0] to_be 1);
    expect(v.data()[1] to_be 2);
    expect(v.data()[2] to_be 3);
    for (size_t index = 3; index < v.capacity(); index++) {
      expect(v.data()[index] to_be -1);
    }

    // expect resize to succeed
    v.resize(4);

    // post-conditions
    //   size to_be 4
    //   capacity to_be 10
    //   data pointer to_be same
    //   data = {1,2,3,0,-1,...}
    expect(v.size() to_be 4);
    expect(v.capacity() to_be 10);
    expect(v.data() to_be old_data);
    expect(v.data()[0] to_be 1);
    expect(v.data()[1] to_be 2);
    expect(v.data()[2] to_be 3);
    expect(v.data()[3] to_be 0);
    for (size_t index = 4; index < v.capacity(); index++) {
      expect(v.data()[index] to_be -1);
    }
  }

  // decrease size
  {
    vector<int> v(5);
    size_t old_capacity = v.capacity();
    // preconditions
    //   size to_be 5
    //   capacity to_be to_be_at_least 5
    //   data = {1,2,3,4,5}
    const int* old_data = v.data();
    for (size_t index = 0; index < v.size(); index++) {
      v.data()[index] = int(index+1);
    }
    expect(v.capacity() to_be_at_least 5);
    expect(v.size() to_be 5);
    for (size_t index = 0; index < v.size(); index++) {
      expect(v.data()[index] to_be int(index+1));
    }

    // expect resize to succeed
    v.resize(3);

    // post-conditions
    //   size to_be 3
    //   capacity to_be unchanged
    //   data pointer to_be unchanged
    //   data = {1,2,3}
    expect(v.size() to_be 3);
    expect(v.capacity() to_be old_capacity);
    expect(v.data() to_be old_data);
    expect(v.data()[0] to_be 1);
    expect(v.data()[1] to_be 2);
    expect(v.data()[2] to_be 3);
  }

  // increase size beyond capacity with value
  {
    vector<int> v(3);
    size_t old_capacity = v.capacity();
    const int* old_data = v.data();
    // preconditions
    //   size to_be 3
    //   capacity to_be_at_least 3
    //   data = {1,2,3}
    v.data()[0] = 1;
    v.data()[1] = 2;
    v.data()[2] = 3;
    expect(v.capacity() to_be_at_least 3);
    expect(v.size() to_be 3);
    expect(v.data()[0] to_be 1);
    expect(v.data()[1] to_be 2);
    expect(v.data()[2] to_be 3);

    // expect resize to succeed
    v.resize(old_capacity + 1, 7);

    // post-conditions
    //   size to_be old_capacity + 1
    //   capacity to_be to_be_at_least size
    //   data pointer to_be new
    //   data = {1,2,3,0,...}
    expect(v.size() to_be old_capacity + 1);
    expect(v.capacity() to_be_at_least v.size());
    expect(v.data() to_be_not old_data);
    expect(v.data()[0] to_be 1);
    expect(v.data()[1] to_be 2);
    expect(v.data()[2] to_be 3);
    for (size_t index = 3; index < v.size(); index++) {
      expect(v.data()[index] to_be 7);
    }
  }

  // increase size within capacity with value
  {
    vector<int> v(3);
    // preconditions
    //   size to_be 3
    //   capacity to_be 10
    //   data = {1,2,3,-1,...}
    v.reserve(10);
    const int* old_data = v.data();
    v.data()[0] = 1;
    v.data()[1] = 2;
    v.data()[2] = 3;
    for (size_t index = 3; index < v.capacity(); index++) {
      v.data()[index] = -1;
    }
    expect(v.capacity() to_be 10);
    expect(v.size() to_be 3);
    expect(v.data()[0] to_be 1);
    expect(v.data()[1] to_be 2);
    expect(v.data()[2] to_be 3);
    for (size_t index = 3; index < v.capacity(); index++) {
      expect(v.data()[index] to_be -1);
    }

    // expect resize to succeed
    v.resize(5, 7);

    // post-conditions
    //   size to_be 5
    //   capacity to_be 10
    //   data pointer to_be same
    //   data = {1,2,3,7,7,-1,...}
    expect(v.size() to_be 5);
    expect(v.capacity() to_be 10);
    expect(v.data() to_be old_data);
    expect(v.data()[0] to_be 1);
    expect(v.data()[1] to_be 2);
    expect(v.data()[2] to_be 3);
    expect(v.data()[3] to_be 7);
    expect(v.data()[4] to_be 7);
    for (size_t index = 5; index < v.capacity(); index++) {
      expect(v.data()[index] to_be -1);
    }
  }

  END_TEST
}

bool test_at() {
  // get value at index
  {
    // preconditions
    //   vector v exto_bets
    //   v has size 3
    //   v's data = {?,1,?}
    vector<int> v(3);
    v.data()[1] = 1;
    const int* old_data = v.data();
    expect(v.size() to_be 3);
    expect(v.data()[1] to_be 1);
    
    // action and expected result
    expect(v.at(1) to_be 1);

    // postconditions
    //   v to_be unchanged (size, data)
    expect(v.size() to_be 3);
    expect(v.data() to_be old_data);
  }

  // arg of at to_be unsigned long
  {
    vector<int> v(3);
    v.data()[1] = 7;
    expect(v.at(-UINT64_MAX) to_be 7);
  }

  // set value at index within bounds
  {
    // preconditions
    //   vector v exto_bets
    //   v has size 3
    //   index to_be between 0 and size (1)
    //   value to set to_be type int (INT32_MAX)
    //   value at index to_be not INT32_MAX
    size_t expected_size = 3;
    vector<int> v(expected_size);
    expect(v.size() to_be expected_size);
    size_t index = 1;
    expect(index < expected_size);
    int value = INT32_MAX;
    expect(v.data()[index] to_be_not value);
    const int* old_data = v.data();

    // action [and expected behavior]
    v.at(index) = value;

    // postconditions
    //   v at index should be value
    //   v's size to_be 3
    //    v's data pointer to_be unchanged
    expect(v.data()[index] to_be value);
    //expect(v.at(index) to_be value);
    expect(v.size() to_be 3);
    expect(v.data() to_be old_data);
  }

  // attempt to get value out of bounds
  {
    const vector<int> v(5);

    expect_throw(v.at(5), std::out_of_range);

    expect_throw(v.at(-1), std::out_of_range);
  }

  // attempt to set value out of bounds
  {
    vector<int> v(5);
    expect_throw(v.at(5) = 13, std::out_of_range);
  }

  END_TEST
}

bool test_front() {
  // get front of non-empty vector
  {
    vector<int> v(3);
    v.data()[0] = 7;
    expect(v.front() to_be 7);
  }

  // attempt to get front of empty vector
  {
    vector<int> v;
    expect_throw(v.front(), std::out_of_range);
  }

  END_TEST
}

bool test_empty() {
  // empty vector
  {
    vector<int> v;
    expect(v.empty() to_be true);
  }

  // non-empty vector
  {
    vector<int> v(3);
    expect(v.empty() to_be false);
  }

  END_TEST
}

bool test_shrink_to_fit() {
  // shrink to fit non-empty vector (at most 50% full)
  {
    vector<int> v(50);
    v.reserve(100);
    v.shrink_to_fit();
    expect(v.capacity() to_be 50);
    expect(v.size() to_be 50);
  }

  // shrink to fit non-empty vector (strictly more than 50% full)
  {
    vector<int> v(51);
    v.reserve(100);
    v.shrink_to_fit();
    expect(v.capacity() to_be 100);
    expect(v.size() to_be 51);
  }

  // shrink to fit empty vector
  {
    vector<int> v;
    v.reserve(100);
    v.shrink_to_fit();
    expect(v.capacity() to_be 1); // quirk of our design
    expect(v.size() to_be 0);
  }

  END_TEST
}

bool test_clear() {
  // clear non-empty vector
  {
    vector<int> v(100);
    expect(v.size() to_be 100);
    size_t old_capacity = v.capacity();
    v.clear();
    expect(v.size() to_be 0);
    expect(v.capacity() to_be old_capacity);
  }

  // clear empty vector
  {
    vector<int> v;
    v.clear();
    size_t old_capacity = v.capacity();
    v.clear();
    expect(v.size() to_be 0);
    expect(v.capacity() to_be old_capacity);
  }

  END_TEST
}

bool test_insert() {
  // insert value into non-full non-empty vector at back
  {
    vector<int> v(3);
    v.reserve(5);
    expect(v.capacity() to_be_greater_than v.size());
    expect(v.size() to_be 3);
    size_t old_capacity = v.capacity();
    v.insert(3,1);
    expect(v.data()[0] to_be 0);
    expect(v.data()[1] to_be 0);
    expect(v.data()[2] to_be 0);
    expect(v.data()[3] to_be 1);
    expect(v.size() to_be 4);
    expect(v.capacity() to_be old_capacity);
  }

  // insert value into non-full non-empty vector at middle
  {
    vector<int> v(3);
    v.reserve(5);
    expect(v.capacity() to_be_greater_than v.size());
    expect(v.size() to_be 3);
    size_t old_capacity = v.capacity();
    v.insert(1,1);
    expect(v.data()[0] to_be 0);
    expect(v.data()[1] to_be 1);
    expect(v.data()[2] to_be 0);
    expect(v.data()[3] to_be 0);
    expect(v.size() to_be 4);
    expect(v.capacity() to_be old_capacity);
  }

  // insert value into non-full non-empty vector at front
  {
    vector<int> v(3);
    v.reserve(5);
    expect(v.capacity() to_be_greater_than v.size());
    expect(v.size() to_be 3);
    size_t old_capacity = v.capacity();
    v.insert(0,1);
    expect(v.data()[0] to_be 1);
    expect(v.data()[1] to_be 0);
    expect(v.data()[2] to_be 0);
    expect(v.data()[3] to_be 0);
    expect(v.size() to_be 4);
    expect(v.capacity() to_be old_capacity);
  }

  // insert value into non-full non-empty vector out of bounds
  {
    vector<int> v(3);
    v.reserve(5);
    expect_throw(v.insert(4,1), std::out_of_range);
  }

  // insert value into full vector at back
  {
    vector<int> v(3);
    while (v.size() < v.capacity()) { v.push_back(0); }
    size_t old_size = v.size();
    size_t old_capacity = v.capacity();
    v.insert(old_size,1);
    expect(v.capacity() to_be 2*old_capacity);
    expect(v.size() to_be old_size+1);
    expect(v.data()[0] to_be 0);
    expect(v.data()[1] to_be 0);
    expect(v.data()[2] to_be 0);
    expect(v.data()[old_size-1] to_be 0);
    expect(v.data()[old_size] to_be 1);
  }

  // insert value into full vector at middle
  {
    vector<int> v(3);
    while (v.size() < v.capacity()) { v.push_back(0); }
    size_t old_size = v.size();
    size_t old_capacity = v.capacity();
    v.insert(1,1);
    expect(v.capacity() to_be 2*old_capacity);
    expect(v.size() to_be old_size+1);
    expect(v.data()[0] to_be 0);
    expect(v.data()[1] to_be 1);
    expect(v.data()[2] to_be 0);
    expect(v.data()[old_size-1] to_be 0);
    expect(v.data()[old_size] to_be 0);
  }

  // insert value into full vector at front
  {
    vector<int> v(3);
    while (v.size() < v.capacity()) { v.push_back(0); }
    size_t old_size = v.size();
    size_t old_capacity = v.capacity();
    v.insert(0,1);
    expect(v.capacity() to_be 2*old_capacity);
    expect(v.size() to_be old_size+1);
    expect(v.data()[0] to_be 1);
    expect(v.data()[1] to_be 0);
    expect(v.data()[2] to_be 0);
    expect(v.data()[3] to_be 0);
    expect(v.data()[old_size-1] to_be 0);
    expect(v.data()[old_size] to_be 0);
  }

  // insert value into empty vector at front=back=middle
  {
    vector<int> v;
    expect(v.size() to_be 0);
    v.insert(0,1);
    expect(v.data()[0] to_be 1);
    expect(v.size() to_be 1);
  }

  // insert value into empty vector out of bounds
  {
    vector<int> v;
    expect_throw(v.insert(1,1), std::out_of_range);
  }

  END_TEST
}

bool test_erase() {
  // erase front
  {
    vector<int> v(3);
    v.data()[0] = 1;
    v.data()[1] = 2;
    v.data()[2] = 3;
    size_t old_capacity = v.capacity();
    v.erase(0);
    expect(v.size() to_be 2);
    expect(v.capacity() to_be old_capacity);
    expect(v.data()[0] to_be 2);
    expect(v.data()[1] to_be 3);
  }

  // erase middle
  {
    vector<int> v(3);
    v.data()[0] = 1;
    v.data()[1] = 2;
    v.data()[2] = 3;
    size_t old_capacity = v.capacity();
    v.erase(1);
    expect(v.size() to_be 2);
    expect(v.capacity() to_be old_capacity);
    expect(v.data()[0] to_be 1);
    expect(v.data()[1] to_be 3);
  }

  // erase back
  {
    vector<int> v(3);
    v.data()[0] = 1;
    v.data()[1] = 2;
    v.data()[2] = 3;
    size_t old_capacity = v.capacity();
    v.erase(2);
    expect(v.size() to_be 2);
    expect(v.capacity() to_be old_capacity);
    expect(v.data()[0] to_be 1);
    expect(v.data()[1] to_be 2);
  }

  // erase out of bounds
  {
    vector<int> v(3);
    v.data()[0] = 1;
    v.data()[1] = 2;
    v.data()[2] = 3;
    size_t old_capacity = v.capacity();
    expect_throw(v.erase(3), std::out_of_range);
    expect(v.size() to_be 3);
    expect(v.capacity() to_be old_capacity);
    expect(v.data()[0] to_be 1);
    expect(v.data()[1] to_be 2);
    expect(v.data()[2] to_be 3);

  }

  // erase range including front
  {
    vector<int> v(5);
    v.data()[0] = 1;
    v.data()[1] = 2;
    v.data()[2] = 3;
    v.data()[3] = 4;
    v.data()[4] = 5;
    size_t old_capacity = v.capacity();
    v.erase(0,2);
    expect(v.size() to_be 3);
    expect(v.capacity() to_be old_capacity);
    expect(v.data()[0] to_be 3);
    expect(v.data()[1] to_be 4);
    expect(v.data()[2] to_be 5);
  }

  // erase range not containing front or back
  {
    vector<int> v(5);
    v.data()[0] = 1;
    v.data()[1] = 2;
    v.data()[2] = 3;
    v.data()[3] = 4;
    v.data()[4] = 5;
    size_t old_capacity = v.capacity();
    v.erase(1,4);
    expect(v.size() to_be 2);
    expect(v.capacity() to_be old_capacity);
    expect(v.data()[0] to_be 1);
    expect(v.data()[1] to_be 5);
  }

  // erase range containing back
  {
    vector<int> v(5);
    v.data()[0] = 1;
    v.data()[1] = 2;
    v.data()[2] = 3;
    v.data()[3] = 4;
    v.data()[4] = 5;
    size_t old_capacity = v.capacity();
    v.erase(3,5);
    expect(v.size() to_be 3);
    expect(v.capacity() to_be old_capacity);
    expect(v.data()[0] to_be 1);
    expect(v.data()[1] to_be 2);
    expect(v.data()[2] to_be 3);
  }

  // erase entire vector by range
  {
    vector<int> v(5);
    v.data()[0] = 1;
    v.data()[1] = 2;
    v.data()[2] = 3;
    v.data()[3] = 4;
    v.data()[4] = 5;
    size_t old_capacity = v.capacity();
    v.erase(0, v.size());
    expect(v.size() to_be 0);
    expect(v.capacity() to_be old_capacity);
  }

  // erase range that goes out of bounds
  {
    vector<int> v(5);
    v.data()[0] = 1;
    v.data()[1] = 2;
    v.data()[2] = 3;
    v.data()[3] = 4;
    v.data()[4] = 5;
    size_t old_capacity = v.capacity();
    size_t old_size = v.size();
    expect_throw(v.erase(2,6), std::out_of_range);
    expect(v.size() to_be old_size);
    expect(v.capacity() to_be old_capacity);
    expect(v.data()[0] to_be 1);
    expect(v.data()[1] to_be 2);
    expect(v.data()[2] to_be 3);
    expect(v.data()[3] to_be 4);
    expect(v.data()[4] to_be 5);
  }

  // erase range entirely out of bounds
  {
    vector<int> v(5);
    v.data()[0] = 1;
    v.data()[1] = 2;
    v.data()[2] = 3;
    v.data()[3] = 4;
    v.data()[4] = 5;
    size_t old_capacity = v.capacity();
    size_t old_size = v.size();
    expect_throw(v.erase(5,10), std::out_of_range);
    expect(v.size() to_be old_size);
    expect(v.capacity() to_be old_capacity);
    expect(v.data()[0] to_be 1);
    expect(v.data()[1] to_be 2);
    expect(v.data()[2] to_be 3);
    expect(v.data()[3] to_be 4);
    expect(v.data()[4] to_be 5);
  }

  // erase backwards range is no-op
  {
    vector<int> v(5);
    v.data()[0] = 1;
    v.data()[1] = 2;
    v.data()[2] = 3;
    v.data()[3] = 4;
    v.data()[4] = 5;
    size_t old_capacity = v.capacity();
    size_t old_size = v.size();
    v.erase(3,1);
    expect(v.size() to_be old_size);
    expect(v.capacity() to_be old_capacity);
    expect(v.data()[0] to_be 1);
    expect(v.data()[1] to_be 2);
    expect(v.data()[2] to_be 3);
    expect(v.data()[3] to_be 4);
    expect(v.data()[4] to_be 5);
  }

  END_TEST
}

bool test_destructor() {
  int* data_ptr;
  {
    vector<int> v(3);
    data_ptr = v.data();
  } // destructor invoked here
  
  // allocate an int on the heap
  int* ptr = (int*)malloc(1);
  
  // if the destructor freed the memory,
  //   the just-allocated int should be
  //   where the array used to be
  expect(ptr to_be data_ptr);

  free(ptr);
  
  END_TEST
}

bool test_copy_constructor() {  
  vector<int> v(3);
  expect(v.data() not_to_be nullptr);
  v.data()[0] = 1;
  v.data()[1] = 2;
  v.data()[2] = 3;
  size_t v_capacity = v.capacity();
  size_t v_size = v.size();
  int* v_data = v.data(); 
  {
    vector<int> copy = v;
    // copy is a copy of v
    expect(copy.capacity() to_be v.capacity());
    expect(copy.size() to_be v.size());
    //   copy is deep
    expect(copy.data() not_to_be v.data());
    expect(copy.data()[0] to_be v.data()[0]);
    expect(copy.data()[1] to_be v.data()[1]);
    expect(copy.data()[2] to_be v.data()[2]);
    // v is unchanged
    expect(v.capacity() to_be v_capacity);
    expect(v.size() to_be v_size);
    expect(v.data() to_be v_data);
    expect(v.data()[0] to_be 1);
    expect(v.data()[1] to_be 2);
    expect(v.data()[2] to_be 3);

    // another way to test for deep copy
    v.data()[0] = -9;
    expect(copy.data()[0] to_be 1);
  } // copy is destructed

  // v should be unchanged
  expect(v.capacity() to_be v_capacity);
  expect(v.size() to_be v_size);
  expect(v.data() to_be v_data);
  expect(v.data()[0] to_be -9);
  expect(v.data()[1] to_be 2);
  expect(v.data()[2] to_be 3);

  END_TEST
}

bool test_copy_assignment_operator() {
  {
    vector<int> v(3);
    v.data()[0] = 1;
    v.data()[1] = 2;
    v.data()[2] = 3;
    size_t v_capacity = v.capacity();
    size_t v_size = v.size();
    int* v_data = v.data(); 
    {
      vector<int> u(5);
      u.data()[0] = 11;
      u.data()[1] = 12;
      u.data()[2] = 13;
      u.data()[3] = 14;
      u.data()[4] = 15;
  
      u = v;
      
      // u is a copy of v
      expect(u.capacity() to_be v.capacity());
      expect(u.size() to_be v.size());
      //   copy is deep
      expect(u.data() not_to_be v.data());
      expect(u.data()[0] to_be v.data()[0]);
      expect(u.data()[1] to_be v.data()[1]);
      expect(u.data()[2] to_be v.data()[2]);
      
      // v is unchanged
      expect(v.capacity() to_be v_capacity);
      expect(v.size() to_be v_size);
      expect(v.data() to_be v_data);
      expect(v.data()[0] to_be 1);
      expect(v.data()[1] to_be 2);
      expect(v.data()[2] to_be 3);
  
      // another way to test for deep copy
      v.data()[0] = -9;
      expect(u.data()[0] to_be 1);
    } // u is destructed
  
    // v should be unchanged
    expect(v.capacity() to_be v_capacity);
    expect(v.size() to_be v_size);
    expect(v.data() to_be v_data);
    expect(v.data()[0] to_be -9);
    expect(v.data()[1] to_be 2);
    expect(v.data()[2] to_be 3);
  }

  {
    vector<int> v(3);
    v.data()[0] = 1;
    v.data()[1] = 2;
    v.data()[2] = 3;
    {
      vector<int> u(5);
      u.data()[0] = 11;
      u.data()[1] = 12;
      u.data()[2] = 13;
      u.data()[3] = 14;
      u.data()[4] = 15;
      size_t u_capacity = u.capacity();
      size_t u_size = u.size();
      int* u_data = u.data(); 
  
      v = u;
      
      // v is a copy of u
      expect(v.capacity() to_be u.capacity());
      expect(v.size() to_be u.size());
      //   copy is deep
      expect(v.data() not_to_be u.data());
      expect(v.data()[0] to_be u.data()[0]);
      expect(v.data()[1] to_be u.data()[1]);
      expect(v.data()[2] to_be u.data()[2]);
      expect(v.data()[3] to_be u.data()[3]);
      expect(v.data()[4] to_be u.data()[4]);
      
      // u is unchanged
      expect(u.capacity() to_be u_capacity);
      expect(u.size() to_be u_size);
      expect(u.data() to_be u_data);
      expect(u.data()[0] to_be 11);
      expect(u.data()[1] to_be 12);
      expect(u.data()[2] to_be 13);
      expect(u.data()[3] to_be 14);
      expect(u.data()[4] to_be 15);
  
      // another way to test for deep copy
      v.data()[0] = -9;
      expect(u.data()[0] to_be 11);
    } // u is destructed
  
    // v should not be affected
    expect(v.capacity() to_be 5);
    expect(v.size() to_be 5);
    expect(v.data()[0] to_be -9);
    expect(v.data()[1] to_be 12);
    expect(v.data()[2] to_be 13);
    expect(v.data()[3] to_be 14);
    expect(v.data()[4] to_be 15);
  }

  {
    vector<int> v(3);
    v.data()[0] = 1;
    v.data()[1] = 2;
    v.data()[2] = 3;
    size_t v_capacity = v.capacity();
    size_t v_size = v.size();
    int* v_data = v.data();

    v = v;

    expect(v.capacity() to_be v_capacity);
    expect(v.size() to_be v_size);
    expect(v.data() to_be v_data);
    expect(v.data()[0] to_be 1);
    expect(v.data()[1] to_be 2);
    expect(v.data()[2] to_be 3);
  }
  
  END_TEST
}

bool test_rule_of_three() {
  expect(test_destructor() to_be true);
  expect(test_copy_constructor() to_be true);
  expect(test_copy_assignment_operator() to_be true);
  END_TEST
}

bool integration_test() {
  {
    vector<int> v;
    for (int n = 0; n < 100; n++) {
      v.push_back(n);
    }
    v.at(0) = 0;
    v.at(1) = 0;
    
    size_t index = 2;
    while (index < v.size()) {
      if (v.at(index) is 0) {
        index++;
        continue;
      }
      int n = v.at(index);
      for (size_t i = n*n; i < v.size(); i += n) {
        v.at(i) = 0;
      }
      index++;
    }
    
    index = 0;
    while (index < v.size()) {
      if (v.at(index) == 0) {
        v.erase(index);
      } else {
        index++;
      }
    }
    
    expect(v.size() to_be 25);
    expect(v.at(0) to_be 2);
    expect(v.at(1) to_be 3);
    expect(v.at(13) to_be 43);
    expect(v.at(24) to_be 97);
  }

  {
    vector<vector<int>> v;
    DO_N_TIMES(3,v.push_back(vector<int>()));
    int i = 0;
    DO_N_TIMES(3, DO_N_TIMES(5,{v.at(i/5).push_back(i); i++;}));

    vector<vector<int>> v2;
    v2 = v;
    
    
    expect(v2.at(1).at(1) to_be 6);

    v.back().pop_back();
    expect(v.back().back() to_be 13);
    expect(v2.back().back() to_be 14);

    v.pop_back();
    expect(v.back().back() to_be 9);
    expect(v2.back().back() to_be 14);

    expect_throw(v.at(2), std::out_of_range);
  }

  END_TEST
}

bool test_iterator() {
  vector<int> v;
  DO_N_TIMES(10, v.push_back(n));
  int expected = 0;
  for (int n : v) {
    expect(n to_be expected);
    expected++;
  }

  const vector<int> const_v = v;
  expected = 0;
  for (int n : const_v) {
    expect(n to_be expected);
    expected++;
  } 

  END_TEST
}