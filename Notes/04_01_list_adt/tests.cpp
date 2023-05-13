#include "tests.h"
#include "stack.h"
#include "arraylist.h"

namespace {
  bool test_passed = true;
}

bool stack_tests() {
    Stack s;

    expect(s.empty() to_be true);
    expect_throw(s.pop(), empty_stack);

    s.push(1);

    expect(s.empty() to_be false);
    expect(s.pop()   to_be 1);
    expect(s.empty() to_be true);
    expect_throw(s.pop(), empty_stack);

    s.push(1);
    s.push(2);
    s.push(3);

    expect(s.empty() to_be false);
    expect(s.pop()   to_be 3);
    expect(s.empty() to_be false);
    expect(s.pop()   to_be 2);
    expect(s.empty() to_be false);
    expect(s.pop()   to_be 1);
    expect(s.empty() to_be true);
    expect_throw(s.pop(), empty_stack);

    s.push(1);
    s.push(2);
    s.push(3);
    {
        Stack s2 = s;
        expect(s2.empty() to_be false);
        expect(s2.pop()   to_be 3);
        expect(s2.pop()   to_be 2);
        expect(s2.pop()   to_be 1);
        expect(s2.empty() to_be true);

        expect(s.pop() to_be 3);
    }
    expect(s.pop() to_be 2);
    expect(s.pop() to_be 1);

    {
        Stack s2;
        s2.push(4);
        s2.push(5);
        s2.push(6);

        s = s2;
        expect(s2.pop() to_be 6);
        expect(s2.pop() to_be 5);
        expect(s.pop()  to_be 6);
    }
    expect(s.pop() to_be 5);
    expect(s.pop() to_be 4);

    s.push(1);
    s.push(2);
    s.push(3);
    s = s;
    expect(s.empty() to_be false);
    expect(s.pop() to_be 3);
    expect(s.pop() to_be 2);
    expect(s.pop() to_be 1);
    expect(s.empty() to_be true);

    END_TEST
}

bool arraylist_tests() {
    ArrayList a;

    expect(a.size() to_be 0);
    expect_throw(a.at(0), std::out_of_range);
    expect_throw(a.insert(1, 1), std::out_of_range);
    expect_throw(a.remove(0), std::out_of_range);

    a.insert(0, 1);

    expect(a.size() to_be 1);
    expect(a.at(0) to_be 1);
    expect_throw(a.at(1), std::out_of_range);
    expect_throw(a.insert(2, 1), std::out_of_range);
    expect_throw(a.remove(1), std::out_of_range);

    a.insert(0, 2);

    expect(a.size() to_be 2);
    expect(a.at(0) to_be 2);
    expect(a.at(1) to_be 1);
    expect_throw(a.at(2), std::out_of_range);
    expect_throw(a.insert(3, 1), std::out_of_range);
    expect_throw(a.remove(2), std::out_of_range);

    a.insert(2, 3);

    expect(a.size() to_be 3);
    expect(a.at(0) to_be 2);
    expect(a.at(1) to_be 1);
    expect(a.at(2) to_be 3);
    expect_throw(a.at(3), std::out_of_range);
    expect_throw(a.insert(4, 1), std::out_of_range);
    expect_throw(a.remove(3), std::out_of_range);

    a.insert(1, 4);

    expect(a.size() to_be 4);
    expect(a.at(0) to_be 2);
    expect(a.at(1) to_be 4);
    expect(a.at(2) to_be 1);
    expect(a.at(3) to_be 3);
    expect_throw(a.at(4), std::out_of_range);
    expect_throw(a.insert(5, 1), std::out_of_range);
    expect_throw(a.remove(4), std::out_of_range);

    a.remove(2);

    expect(a.size() to_be 3);
    expect(a.at(0) to_be 2);
    expect(a.at(1) to_be 4);
    expect(a.at(2) to_be 3);
    expect_throw(a.at(3), std::out_of_range);
    expect_throw(a.insert(4, 1), std::out_of_range);
    expect_throw(a.remove(3), std::out_of_range);

    a.remove(0);

    expect(a.size() to_be 2);
    expect(a.at(0) to_be 4);
    expect(a.at(1) to_be 3);
    expect_throw(a.at(2), std::out_of_range);
    expect_throw(a.insert(3, 1), std::out_of_range);
    expect_throw(a.remove(2), std::out_of_range);

    a.remove(1);

    expect(a.size() to_be 1);
    expect(a.at(0) to_be 4);
    expect_throw(a.at(1), std::out_of_range);
    expect_throw(a.insert(2, 1), std::out_of_range);
    expect_throw(a.remove(1), std::out_of_range);

    a.remove(0);

    expect(a.size() to_be 0);
    expect_throw(a.at(0), std::out_of_range);
    expect_throw(a.insert(1, 1), std::out_of_range);
    expect_throw(a.remove(0), std::out_of_range);

    a.insert(0, 1);
    a.insert(1, 2);
    a.insert(2, 3);
    {
        ArrayList b = a;

        expect(b.size() to_be a.size());
        expect(b.at(0) to_be a.at(0));
        expect(b.at(1) to_be a.at(1));
        expect(b.at(2) to_be a.at(2));
        expect(a.size() to_be 3);
        expect(a.at(0) to_be 1);
        expect(a.at(1) to_be 2);
        expect(a.at(2) to_be 3);

        b.insert(3, 4);

        expect(b.size() to_be 4);
        expect(b.at(0) to_be 1);
        expect(b.at(1) to_be 2);
        expect(b.at(2) to_be 3);
        expect(b.at(3) to_be 4);
        expect(a.size() to_be 3);
        expect(a.at(0) to_be 1);
        expect(a.at(1) to_be 2);
        expect(a.at(2) to_be 3);
    }
    expect(a.size() to_be 3);
    expect(a.at(0) to_be 1);
    expect(a.at(1) to_be 2);
    expect(a.at(2) to_be 3);

    a.insert(0, 1);
    a.insert(1, 2);
    a.insert(2, 3);
    {
        ArrayList b;
        b.insert(0, 4);
        b.insert(1, 5);
        b.insert(2, 6);
        b.insert(3, 7);

        a = b;

        expect(b.size() to_be a.size());
        expect(b.at(0) to_be a.at(0));
        expect(b.at(1) to_be a.at(1));
        expect(b.at(2) to_be a.at(2));
        expect(b.at(3) to_be a.at(3));
        expect(a.size() to_be 4);
        expect(a.at(0) to_be 4);
        expect(a.at(1) to_be 5);
        expect(a.at(2) to_be 6);
        expect(a.at(3) to_be 7);

        b.insert(4, 8);

        expect(b.size() to_be 5);
        expect(b.at(0) to_be 4);
        expect(b.at(1) to_be 5);
        expect(b.at(2) to_be 6);
        expect(b.at(3) to_be 7);
        expect(b.at(4) to_be 8);
        expect(a.size() to_be 4);
        expect(a.at(0) to_be 4);
        expect(a.at(1) to_be 5);
        expect(a.at(2) to_be 6);
        expect(a.at(3) to_be 7);
    }
    expect(a.size() to_be 4);
    expect(a.at(0) to_be 4);
    expect(a.at(1) to_be 5);
    expect(a.at(2) to_be 6);
    expect(a.at(3) to_be 7);

    a = a;

    expect(a.size() to_be 4);
    expect(a.at(0) to_be 4);
    expect(a.at(1) to_be 5);
    expect(a.at(2) to_be 6);
    expect(a.at(3) to_be 7);

    a.remove(0);

    expect(a.size() to_be 3);
    expect(a.at(0) to_be 5);
    expect(a.at(1) to_be 6);
    expect(a.at(2) to_be 7);

    const ArrayList const_a = a;

    expect(const_a.at(0) to_be 5);
    expect(const_a.at(1) to_be 6);
    expect(const_a.at(2) to_be 7);
    expect_throw(const_a.at(3), std::out_of_range);

    END_TEST
}