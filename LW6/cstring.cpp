#include <iostream>
#include "cstring.h"

using std::cout, std::cin, std::endl;

unsigned int length(char str[]) {
  // returns the length of the string including zero (0)
  unsigned int count = 0;
  char pee = str[count];
  while(pee != '\0'){
    count++;
    pee = str[count];
  }
  return count;
}

unsigned int find(char str[], char character) {
  // returns 
  //  - the index of the first occurence of character in str
  //  - the size if the character is not found
  
  //cout<<"LENGTH="<<length(str)<<endl;
  for (unsigned int i = 0; i<length(str); i++){
    if(str[i] == character){
      return i;
    }
  }
  
  //cout<<str[0]<<character<<endl;
  return length(str);
}

bool equalStr(char str1[], char str2[]) {
  // returns true if they are equal and false if they are not
  if(length(str1) != length(str2)){
    return false;
  }
  for (unsigned int i = 0; i < length(str1); i++){
    if (str1[i] != str2[i]){
      return false;
    }
  }
  //cout<<str1[0]<<str2[0]<<endl;
  return true;
}