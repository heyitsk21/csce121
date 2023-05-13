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
#include "User.h"

using std::string;
using std::vector;

User::User(string userName) /* TODO(student): initialize */ : userName(userName) {
  // TODO(student): implement constructor checks
  if (userName == "") {
    throw std::invalid_argument("User: userName is an empty string");
  }
  if (!(islower(userName.at(0)))) {
    throw std::invalid_argument("User: userName does not start with a lowercase letter");
  }
  for (unsigned int index = 0; index < userName.size(); index++){
    if (isupper(userName.at(index))){
      throw std::invalid_argument("User: userName contains uppercase letters");
    } else if (!(islower(userName.at(index)))){
      throw std::invalid_argument("User: userName contains non lowercase alphabetic letters");
    }
  }
}

string User::getUserName() {
  // TODO(student): implement getter
  return this->userName;
}

vector<Post*>& User::getUserPosts() {
  // TODO(student): implement getter
  // if (this->userPosts == nullptr){
  //   throw std::invalid_argument("User: userPosts is empty");
  // }
  return this->userPosts;
}

void User::addUserPost(Post* post) {
  // TODO(student): add post to user posts
  if (post == nullptr) {
    throw std::invalid_argument("User: post is a nullptr");
  }
  userPosts.push_back(post);
}
