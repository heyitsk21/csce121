// TODO: Implement this source file
#include <iostream>
#include <fstream>
#include <stdexcept>
#include "Rover.h"
#include "MyString.h"
using std::cin, std::cout, std::endl, std::ifstream, std::istream, std::ostream;


// size_t priv_size;
// size_t priv_capacity;
// char *word;

//////////////////////////////

// MyString();                                  // default constructor (1)
MyString::MyString() : priv_size(0), priv_capacity(0), word(new char[1]{'\0'}){}

// MyString::MyString(const MyString& inputStr) : priv_size(0), priv_capacity(0), word(nullptr){
//     // MyString(const MyString& inputStr);          // copy constructor (2)
//     priv_size = inputStr.priv_size;
//     priv_capacity = inputStr.priv_capacity;
//     word = new char[priv_capacity]{};
//     for (size_t a = 0; a < priv_capacity; a++){
//         if (a < priv_size){
//             word[a] = inputStr.at(a);
//         }
//         word[priv_capacity] = '\0';
//     }
//     // char* newWord = new char[priv_capacity]{};
//     // for (size_t a = 0; a < priv_capacity; a++){
//     //     if (a < priv_size){
//     //         newWord[a] = inputStr.at(a);
//     //     }
//     //     newWord[priv_capacity] = '\0';
//     // }
//     // word = newWord;
//     // delete[] newWord;
// }
MyString::MyString(const MyString& inputStr) : priv_size{inputStr.priv_size}, priv_capacity{inputStr.priv_capacity}, word{nullptr} {
    this->word = new char[this->priv_capacity];
    size_t i;
    for (i = 0; i < this->priv_capacity; ++i)
        this->word[i] = i < this->priv_size ? inputStr.at(i) : static_cast<char>(0);
}

MyString::MyString(const char* letter) : priv_size(0), priv_capacity(0), word(nullptr){
    // Mystring(const char* letter);                // from c-string (4)
    size_t indexCount = 0;
    while(letter[indexCount] != '\0'){
        indexCount++;
    }
    word = new char[indexCount+1]{};
    for (unsigned int i = 0; i < indexCount; i++){
        word[i] = letter[i];
    }
    priv_capacity = indexCount;
    priv_size = indexCount;
    word[indexCount] = '\0';
}

MyString::~MyString(){
    // ~MyString();                                 // destructor
    delete[] word;
}

void MyString::resize(size_t toSize) {
    // void resize(size_t toSize);                  // resize
    char* outputWord = new char[toSize+1]{};
    if (toSize < priv_size){
        priv_size = toSize;
    }
    size_t a;
    for (a = 0; a < priv_size; a++){
        outputWord[a] = word[a];
    }
    outputWord[toSize] = '\0';
    delete[] word;
    word = outputWord;
    priv_capacity = toSize;
}

size_t MyString::capacity() const {
    // size_t capacity() const;                     // capacity
    return priv_capacity;
}

size_t MyString::size() const {
    // size_t size() const;                         // size
    return priv_size;
}

size_t MyString::length() const {
    // size_t length() const;                       // length
    return priv_size;
}

const char* MyString::data() const {
    //return '\0';
    // const char* data() const;                    // data
    return word;
}

bool MyString::empty() const {
    // bool empty() const;                          // empty
    if (priv_size > 0){
        return false;
    }
    return true;
}

const char& MyString::front() const {
    // const char& front() const;                   // front
    return word[0];
}

const char& MyString::at(size_t index) const {
    // const char& at(size_t index) const;          // at
    if (index >= priv_size){
        throw std::out_of_range("at: index goes beyond the size of the MyString");
    }
    return word[index];
}

void MyString::clear() {
    // void clear();                                // clear
    resize(0);
    priv_size = 0;
}

ostream& operator<<(ostream& a, const MyString& inputStr){
    // ostream& operator<<(ostream& os, const MyString& inputStr);              // operator<<
    // size_t b;
    // for (b = 0; b < inputStr.size(); b++){
    //     a << inputStr.at(b);
    // }
    size_t b = 0;
    while(b < inputStr.size()){
        a << inputStr.at(b);
        b++;
    }
    return a;
} 

// MyString& MyString::operator=(const MyString& inputStr){
//     // MyString& operator=(const MyString& inputStr);                           // operator=

//     // if (inputStr == this){
//     //     return *this;
//     // }
//     delete[] word;
//     priv_size = inputStr.priv_size;
//     priv_capacity = inputStr.priv_capacity;
//     word = new char[priv_capacity+1]{};

//     size_t a = 0;
//     while (a < priv_size){
//         word[a] = inputStr.word[a];
//         ++a;
//     }
//     word[priv_size+1] = '\0';
//     return *this;
// }

MyString& MyString::operator=(const MyString& inputStr) {
    this->priv_size = inputStr.size();
    this->priv_capacity = inputStr.capacity();

    delete[] this->word;
    this->word = new char[this->priv_capacity];

    const char* temp = inputStr.data();
    size_t i;
    for (i = 0; i < this->priv_capacity; ++i)
        this->word[i] = temp[i];

    return *this;
}

MyString& MyString::operator+=(const MyString& inputStr){
    // MyString& operator+=(const MyString& inputStr);                          // operator+=
    //char* outputWord = new char[priv_size + inputStr.priv_size+1]{};
    size_t tempSize = priv_size + inputStr.priv_size;
    if (tempSize > priv_capacity){
        resize(tempSize);
    }
    size_t a;
    for (a = 0; a < inputStr.priv_size; a++){
        word[a+priv_size] = inputStr.word[a];
    }
    priv_size = tempSize;
    return *this;
}

size_t MyString::find(const MyString& inputStr, size_t index) const {
    // size_t find(const MyString& str = nullptr, size_t index = 0) const;      // find
    size_t a;
    size_t b;
    bool areSame = true;
    size_t max = inputStr.priv_size-1;
    for (a = index; a < priv_size; a++){
        for (b = 0; b < inputStr.priv_size; b++){
            if(inputStr.word[b] != word[a + b]){
                areSame = false;
                break;
            }
            if (b == max){
                return a;
            }
        }
    }
    if (areSame){

    }
    return -1;
}

/////////////EXTRA CREDIT////////////

bool MyString::operator==(const MyString& rhs){
    // bool operator==(const MyString& rhs);                                    // operator==
    if (priv_size == rhs.priv_size && priv_capacity == rhs.priv_capacity){
        for (size_t a = 0; a < priv_size; a++){
            if(word[a] != rhs.word[a]){
                return false;
            }
        }
        return true;
    }
    return false;
}

MyString operator+(const MyString& lhs, const MyString& rhs){
    // friend MyString operator+(const MyString& lhs, const MyString& rhs);     // operator+
    size_t tempSize = lhs.priv_size + rhs.priv_size;
    char* outputWord = new char[tempSize+1]{};
    size_t a;
    for (a = 0; a < lhs.priv_size; a++){
        outputWord[a] = lhs.at(a);
    }
    for (a = lhs.priv_size; a < tempSize; a++){
        outputWord[a] = rhs.at(a-lhs.priv_size);
    }
    outputWord[tempSize] = '\0';
    return outputWord;
}