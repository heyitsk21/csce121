/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include <sstream>
#include <fstream>
#include "Post.h"

using std::string;
using std::vector;

Post::Post(unsigned int postId, string userName, string postText)
  : postId(postId), userName(userName), postText(postText) {
  if (postId == 0 || userName == "" || postText == "") {
    throw std::invalid_argument("post constructor: invalid parameter values");
  }
}

unsigned int Post::getPostId() {
  return postId;
}

string Post::getPostUser() {
  return userName;
}

string Post::getPostText() {
  return postText;
}

vector<string> Post::findTags() {
  // TODO(student): extracts candidate tags based on occurrences of # in the post
  vector<string> vectorOfTags;
  string inputPostText = this->postText;
  std::istringstream iss(inputPostText);
  string currWord;
  while (!iss.eof()) {
    iss >> currWord;
    if (currWord.at(0) == '#'){
      string currTag = "";
        for (char a : currWord) {
          switch (a) {
            case '!':
              continue;
            case ',':
              continue;
            case '.':
              continue;
            case '?':
              continue;
            default:
              currTag += tolower(a);
          }
        }
      vectorOfTags.push_back(currTag);
      // //int numPunct = 0;
      // for (unsigned int index = currWord.size()-1; index > 0; index--){
      //   if (currWord.at(index) == '!' || currWord.at(index) == ',' 
      //   || currWord.at(index) == '.' || currWord.at(index) == '?'){
      //     currWord.pop_back();
      //     index--;
      //     //numPunct++;
      //   }
      // }
      // for (unsigned int index = 0; index < currWord.size(); index++){
      //   currWord.at(index) = tolower(currWord.at(index));
      // }
      // if (vectorOfTags.size() == 0){
      //   vectorOfTags.push_back(currWord);
      // } else {
      //   bool alreadyInVector = false;
      //   for (unsigned int index = 0; index < vectorOfTags.size(); index++){
      //     if (vectorOfTags.at(index) == currWord){
      //       alreadyInVector = true;
      //     }
      //   }
      //   if(!alreadyInVector){
      //     vectorOfTags.push_back(currWord);
      //   }
      // }
    }
  }
  return vectorOfTags;
}
