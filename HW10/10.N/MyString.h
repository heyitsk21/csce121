// TODO: Implement this header file
#include <fstream>
#include <iostream>
#include "Rover.h"
#ifndef MyString_H
#define MyString_H

class MyString {

    private:
        size_t size_;
        size_t capacity_;
        char *word;
        void resize(size_t newsize);

    public:
        MyString(); //
        ~MyString(); //
        MyString(const MyString &stringy); //
        MyString(const char *letter); //
        MyString& operator+=(const MyString& str); //
        bool operator==(const MyString& str2); //
        MyString& operator=(const MyString& str); //
        friend MyString operator+(const MyString& str3, const MyString& str2); //
    
        bool empty() const; //
        void clear(); //
        size_t size() const;
        size_t find(const MyString& stringy = nullptr, size_t index = 0) const; //
        size_t capacity() const; //
        size_t length() const; //
        const char& at(size_t index) const; //
        const char *data() const; //
        const char& front() const; //
        // void append(const std::string& word, char letter);
        // size_t size() const;
        // bool insert(const std::string& word, char letter, size_t index);


};

std::ostream& operator<<(std::ostream& output, const MyString& newstr);
#endif