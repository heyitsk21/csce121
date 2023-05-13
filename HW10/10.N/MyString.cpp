// TODO: Implement this source file
#include "Rover.h"
#include "MyString.h"
#include <iostream>
#include <fstream>

MyString::MyString(): size_(0), capacity_(0), word(new char[1]{'\0'}) {}

MyString::~MyString() {
    delete[] word;
    word = nullptr;
    capacity_ = 0;
    size_ = 0;
}

MyString::MyString(const MyString &stringy): size_(0), capacity_(0), word(nullptr){

    size_ = stringy.size_;
    capacity_ = stringy.capacity_;
    word = new char[capacity_ + 1]{};

    for(unsigned int i = 0; i < size_; i++){
        word[i] = stringy.word[i];
    }

    word[capacity_] = '\0';
}

MyString::MyString(const char *letter): size_(0), capacity_(0), word(nullptr){

    int count = 0;
    while(letter[count] != '\0'){
        count += 1;
    }

    word = new char[count + 1]{};

    for(int j = 0; j < count; j++){
        word[j] = letter[j];
    }

    size_ = count;
    capacity_ = count;
    word[count] = '\0';
}

bool MyString::empty() const{
    if(size_ == 0){
        return true;
    }else{
        return false;
    }
}

size_t MyString::capacity() const{
    return capacity_;
}

size_t MyString::length() const{
    return size_;
}

const char& MyString::front() const{
    return word[0];
}

void MyString::clear(){
    resize(0);
    size_ = 0;
}

const char& MyString::at(size_t index) const{
    if(index < size_){
        return word[index];
    }else{
        throw std::out_of_range("index is out of bounds");
    }
}

MyString& MyString::operator=(const MyString& str){

    delete[] word;
    size_ = str.size_;
    capacity_ = str.capacity_;
    word = new char[size_ + 1]{};
    for(size_t i = 0; i < size_; i++){
        word[i] = str.word[i];
    }
    word[size_] = '\0';
    return *this;
}

MyString& MyString::operator+=(const MyString& str){

    size_ = size_ + str.size_;
    if(size_ > capacity_){
        resize(size_);
    }
    for(size_t i = 0; i < str.size_; i++){
        word[size_ - str.size_ + i] = str.word[i];
    }
    return *this;
}

MyString operator+(const MyString& str3, const MyString& str2){
    char *newArray = new char[1 + str3.size() + str2.size()]{};
    size_t count = 0;
    size_t count2 = 0;
    for(size_t i = 0; i < str3.size(); i++){
        count += 1;
        newArray[i] = str3.at(i);
    }
    for(size_t j = 0; j < str2.size(); j++){
        newArray[count + j] = str2.at(j);
        count2 += 1;
    }
    newArray[count + count2] = '\0';
    return newArray;
}

bool MyString::operator==(const MyString& equal){
    return true;
}

const char *MyString::data() const{
    return word;
}

size_t MyString::find(const MyString& str, size_t index) const{
    for(size_t i = index; i < size_; i++){
        for(size_t j = 0; j < str.size_; j++){
            if(str.word[j] != word[i + j]){
                break;
            }
            if(j == (str.size_ - 1)){
                return i;
            }
        }
    }
    return -1;
}

void MyString::resize(size_t newsize){

    char *newArr = new char[newsize + 1]{};
    if(newsize < size_){
        size_ = newsize;
        for(size_t i = 0; i < size_; i++){
            newArr[i] = word[i];
        }
        newArr[newsize] = '\0';
        capacity_ = newsize;
    }else{
        for(size_t i = 0; i < size_; i++){
            newArr[i] = word[i];
        }
        newArr[newsize] = '\0';
        capacity_ = newsize;
    }
    delete[] word;
    word = newArr;

    
}

std::ostream& operator<<(std::ostream& output, const MyString& newstr){
    
    size_t hold = 0;
    while(hold < newstr.size()){
        output << newstr.at(hold);
        hold += 1;
    }
    return output;
}

size_t MyString::size() const{
    return size_;
}






