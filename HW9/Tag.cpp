/*
 *
 * This code is copyrighted (c) 2021 by
 * Texas A&M Computer Science
 *
 *	There will be RIGOROUS cheat checking on your exams!!
 *	DON'T POST ANYWHERE!! such as CHEGG, public Github, etc
 *  You will be legally responsible.
 */

#include <string>
#include <stdexcept>
#include <iostream>
#include "Tag.h"

using std::string;
using std::vector;

Tag::Tag(string tagName) /* TODO(student): initialize */ : tagName(tagName) {
  // TODO(student): implement constructor checks
  if (tagName == ""){
    throw std::invalid_argument("Tag: tagName cannot be an empty string");
  }
  if (tagName.size() < 2){
    throw std::invalid_argument("Tag: tagName too short");
  }
  if (tagName.at(0) != '#'){
    throw std::invalid_argument("Tag: tagName does not start with a '#'");
  }
  if (!islower(tagName.at(1)) /*&& tagName.at(1) <= 'z'*/){
    throw std::invalid_argument("Tag: tagName at index 1 is not a lowercase letter");
  }
  for (unsigned int index = tagName.size()-1; index > 0; index--){
    if (tagName.at(index) == '!' || tagName.at(index) == ',' 
    || tagName.at(index) == '.' || tagName.at(index) == '?'){
      // tagName.pop_back();
      // index--;
      throw std::invalid_argument("Tag: tagName ends with punctuation");
    }
    if (isupper(tagName.at(index))){
      throw std::invalid_argument("Tag: tagName contains uppercase letters");
    }
  }

  // if (tagName.at(tagName.size()-1) == '!' || tagName.at(tagName.size()-1) == ',' || 
  // tagName.at(tagName.size()-1) == '.' || tagName.at(tagName.size()-1) == '?'){
  //   std::cout << "TagName contains punctuation at the end" << std::endl;
  //   throw std::invalid_argument("Tag: tagName ends with punctuation");
  // }

  for (unsigned int index = 1; index < tagName.size(); index++){
    if (!islower(tagName.at(index))){
      throw std::invalid_argument("Tag: tagName cannot contain capital letters");
    }
  }
}

string Tag::getTagName() {
  // TODO(student): implement getter
  return this->tagName;
}

vector<Post*>& Tag::getTagPosts() {
  // TODO(student): implement getter
  return this->tagPosts;
}

void Tag::addTagPost(Post* post) {
  // TODO(student): add post to tag posts
  if (post == nullptr){
    throw std::invalid_argument("Tag: post is a nullptr and cannot be added");
  }
  tagPosts.push_back(post);
}
