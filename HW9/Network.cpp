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
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Network.h"

using std::string;
using std::vector;

Network::Network() {
  // empty containers of vectors already created
  // no implementation is needed here
}

void Network::loadFromFile(string fileName) {
  // TODO(student): load user and post information from file
  std::ifstream input_file(fileName);
  if (!input_file.is_open()){
    throw std::invalid_argument("Network: cannot load from that file");
  }
  string currWord;
  string userName_a;
  unsigned int postId_b;
  string userName_b;
  string postText_b;
  
  while (input_file >> currWord){
    if (currWord == "User"){
      input_file >> userName_a;
      if(input_file.fail()){
        throw std::runtime_error("Network: loadFromFile() - invalid username A");
      }
      try {
        addUser(userName_a);
      } catch (const std::invalid_argument& err) {
        throw std::runtime_error("Network: runtime_error thrown because addUser() threw invalid_argument");
      }
    } else if (currWord == "Post"){
      input_file >> postId_b;
      if(input_file.fail()){
        throw std::runtime_error("Network: loadFromFile() - invalid postId");
      }
      input_file >> userName_b;
      if(input_file.fail()){
        throw std::runtime_error("Network: loadFromFile() - invalid username B");
      }
      getline(input_file, postText_b);
      if(input_file.fail()){
        throw std::runtime_error("Network: loadFromFile() - invalid postText");
      }
      try {
        addPost(postId_b, userName_b, postText_b);
      } catch (const std::invalid_argument& err) {
        throw std::runtime_error("Network: runtime_error thrown because addPost() threw invalid_argument");
      }
    }
     else {
      throw std::runtime_error("Network: trying to load a file that doesn't match format");
    }
  }
}

bool Network::userExists1(const std::string& userName){
  for (User* user : users){
    if (user->getUserName() == userName){
      //u = user;
      return true;
    }
  }
  return false;
}

User* Network::userExistsUserPtr(const std::string& userName){
  for (User* user : this->users){
    if (user->getUserName() == userName){
      //u = user;
      return user;
    }
  }
  return nullptr;
}

void Network::addUser(string userName) {
  // TODO(student): create user and add it to network
  // for (unsigned int index = 0; index < users.size(); index++){
  //   if (users.at(index)->getUserName() == userName){
  //     throw std::invalid_argument("Network: trying to add a user that already exists");
  //   }
  // }
  if (userExists1(userName)){
    throw std::invalid_argument("Network: trying to add a user that already exists");
  }
  User* currUser = new User(userName);
  users.push_back(currUser);
          //std::cout << users.at(users.size()-1)->getUserName() << std::endl;
  std::cout << "Added User " << userName << std::endl;
}

void Network::addPost(unsigned int postId, string userName, string postText) {
  // TODO(student): create post and add it to network
  for (Post* currPost : this->posts){
    if (currPost->getPostId() == postId){
      throw std::invalid_argument("Network: trying to add a post that already has this post ID");
    }
  }
  
  bool doesUserExisttt = userExists1(userName);
  if(!doesUserExisttt){
    throw std::invalid_argument("Network: trying to add a post by a user that doesn't exist 2");
  }
  
  Post* currPost = new Post(postId, userName, postText);
  this->posts.push_back(currPost);

  vector<string> currVectorOfTags = currPost->findTags();
  if (!currVectorOfTags.empty()){
    for (string currTag : currVectorOfTags){
      bool isADuplicateTag = false;
      for (Tag* secTag : this->tags){
        if (currTag == secTag->getTagName()){
          isADuplicateTag = true;
          secTag->addTagPost(currPost);
          break;
        }
      }
      if (!isADuplicateTag){
        try {
          //create the tag, add it to the network, add the post to the tag
          Tag* newTag = new Tag(currTag);
          this->tags.push_back(newTag);
          newTag->addTagPost(currPost);
        } catch (/*const std::exception& err*/...){
          continue;
        }
      }
    }
  }

  User* u = userExistsUserPtr(userName);
  if (u != nullptr){
    u->addUserPost(currPost);
  }

  std::cout << "Added Post " << postId << " by " << userName << std::endl;
  //std::cout << "postText: " << postText << std::endl << std::endl;
}

vector<Post*> Network::getPostsByUser(string userName) {
  // TODO(student): return posts created by the given user
  if (userName == ""){
    throw std::invalid_argument("Network: getPostsByUser() - empty userName");
  }
  if (!userExists1(userName)){
    throw std::invalid_argument("Network: getPostsByUser() - userName does not already exist");
  }
  return userExistsUserPtr(userName)->getUserPosts();
}

Tag* Network::tagExistsUserPtr(const std::string& tagName){
  for (Tag* tag : this->tags){
    if (tag->getTagName() == tagName){
      return tag;
    }
  }
  return nullptr;
}

vector<Post*> Network::getPostsWithTag(string tagName) {
  // TODO(student): return posts containing the given tag
  if (tagName == ""){
    throw std::invalid_argument("Network: getPostsWithTag() - empty tagName");
  }
  Tag* tag = tagExistsUserPtr(tagName);
  if (tag == nullptr){
    throw std::invalid_argument("Network: getPostsWithTag() - tagName does not exist");
  }
  return tag->getTagPosts();

  // if (!tagExistsUserPtr(tagName)){
  //   throw std::invalid_argument("Network: getPostsWithTag() - tagName does not exist");
  // }
  // return tagExistsUserPtr(tagName)->getTagPosts();
}

vector<string> Network::getMostPopularHashtag() {
  // TODO(student): return the tag occurring in most posts
  
  vector<string> mostPopTags;
  vector<Post*> getPostsWithTagVEC;
  int maxNumInstances = 0;
  int numInstances;

  for (Tag* tag : this->tags) {
    numInstances = 0;
    //std::cout<<"--------------NEW VECT--------------"<<std::endl;
    getPostsWithTagVEC = getPostsWithTag(tag->getTagName());
    for (Post* p : getPostsWithTagVEC){
      //std::cout<<p->getPostText()<<std::endl;
      p=p;
      numInstances++;
    }
    //std::cout<<"--------------END VECT--------------"<<std::endl<<std::endl<<std::endl<<std::endl;
    if (numInstances>=maxNumInstances){
      maxNumInstances = numInstances;
    }
  }
  //std::cout<<std::endl<<std::endl<<std::endl<<std::endl<<"--------------ADD TAG WITH MOST INSTANCES TO VEC--------------"<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl<<std::endl;
  for (Tag* tag : this->tags) {
    numInstances = 0;
    //std::cout<<"--------------NEW VECT2--------------"<<std::endl;
    getPostsWithTagVEC = getPostsWithTag(tag->getTagName());
    for (Post* p : getPostsWithTagVEC){
      //std::cout<<p->getPostText()<<std::endl;
      p=p;
      numInstances++;
    }
    //std::cout<<"--------------END VECT2--------------"<<std::endl<<std::endl<<std::endl<<std::endl;
    if (numInstances==maxNumInstances){
      mostPopTags.push_back(tag->getTagName());
    }
  }
  
  return mostPopTags;
}

/**
  * Destructor
  * Do not change; already implemented.
  */
Network::~Network() {
  for (unsigned int i = 0; i < users.size(); ++i) {
    delete users.at(i);
  }
  for (unsigned int i = 0; i < tags.size(); ++i) {
    delete tags.at(i);
  }
  for (unsigned int i = 0; i < posts.size(); ++i) {
    delete posts.at(i);
  }
}
