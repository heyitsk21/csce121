// TODO: Implement this header file
#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <fstream>
#include <stdexcept>

class MyString {
  private:
    size_t priv_size;
    size_t priv_capacity;
    char* word;

    void resize(size_t toSize);

  public:
    MyString();
    MyString(const MyString& inputStr);
    MyString(const char* inputStr);
    ~MyString();

    size_t capacity() const;
    size_t size() const;
    size_t length() const;
    const char* data() const;
    bool empty() const;
    const char& front() const;
    const char& at(size_t index) const;
    void clear();

    MyString& operator=(const MyString& inputStr);
    MyString& operator+=(const MyString& inputStr);
    bool operator==(const MyString& rhs);
    friend MyString operator+(const MyString& lhs, const MyString& rhs);

    size_t find(const MyString& str = nullptr, size_t index = 0) const;
};

std::ostream& operator<<(std::ostream& a, const MyString& inputStr);

#endif