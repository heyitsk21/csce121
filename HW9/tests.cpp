#include <iostream>
#include "Network.h"

// void expect(X) try {
//   if (!(X)) {
//     std::cout << "  [fail] (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ") " << "expected " << X << "." << std::endl;
//   }
// } catch(...) {
//   std::cout << "  [fail] (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ") " << X << " threw an unexpected exception." << std::endl;
// }

#define expect_throw(X,E) {\
  bool threw_expected_exception = false;\
  try {\
    X; \
  }\
  catch(const E& err) {\
    threw_expected_exception = true;\
    std::cout << "  [PASS] " << /*#X*/__FILE__<<":"<<__LINE__ << " - correct exception thrown!" << std::endl << std::endl;\
  } catch(...) {\
    std::cout << "  [HELP] " << /*#X*/__FILE__<<":"<<__LINE__ << " threw an incorrect exception." << std::endl;\
  }\
  if (!threw_expected_exception) {\
    std::cout << "  [FAIL]" << " (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ") " << "expected " << #X << " to throw " << #E << "." << std::endl << std::endl;\
  }\
}

int main(){

    std::cout << std::endl << std::endl << " -----------------BEGIN TESTING-----------------" << std::endl << std::endl;
    Network facebook;
    facebook.addUser("ritchey");
    facebook.addPost(1024,"ritchey","I'm an epic prof");
    facebook.addPost(1025,"ritchey","You should know how to #compile your code!");

    std::cout << "  [ 5b ]: Network::addPost() - valid (invalid candidate hastags)" << std::endl;
    expect_throw(facebook.addPost(1026,"ritchey","You should know how to #delete!!!"),std::invalid_argument);

    // try {
    //     facebook.addPost(1024,"ritchey","I'm a super epic prof");
    //     std::cout << "FAIL" << std::endl;
    // } catch (const std::invalid_argument& err){
    //     std::cout << "PASS" << std::endl;
    // }
    std::cout << "  [ 5c ]: Network::addPost() - invalid (duplicate post id)" << std::endl;
    expect_throw(facebook.addPost(1024,"ritchey","I'm a super epic prof"),std::invalid_argument);
    
    // try {
    //     facebook.addPost(1234,"katelyn","wow");
    //     std::cout << "FAIL" << std::endl;
    // } catch (const std::invalid_argument& err){
    //     std::cout << "PASS" << std::endl;
    // }
    std::cout << "  [ 5d ]: Network::addPost() - invalid (user does not exist)" << std::endl;
    expect_throw(facebook.addPost(1234,"katelyn","wow"),std::invalid_argument);

    std::cout << "  [ 6a ]: Network::loadFromFile() - file does not exist" << std::endl;
    expect_throw(facebook.loadFromFile("abc.txt"),std::invalid_argument);

    std::cout << "  [ 6b ]: Network::loadFromFile() - invalid file format (unknown entry)" << std::endl;
    expect_throw(facebook.loadFromFile("unknown_entry.txt"),std::runtime_error);

    std::cout << "  [ 6c ]: Network::loadFromFile() - invalid user format (missing data)" << std::endl;
    expect_throw(facebook.loadFromFile("invalid_user_format2.txt"),std::runtime_error);

    std::cout << "  [ 6d ]: Network::loadFromFile() - invalid user format (name)" << std::endl;
    expect_throw(facebook.loadFromFile("invalid_user_format1.txt"),std::runtime_error);

    std::cout << "  [ 6e ]: Network::loadFromFile() - invalid post format (id)" << std::endl;
    expect_throw(facebook.loadFromFile("invalid_post_format1.txt"),std::runtime_error);

    //????
    std::cout << "  [ 6f?]: Network::loadFromFile() - invalid post format (username)" << std::endl;
    expect_throw(facebook.loadFromFile("invalid_user_format2.txt"),std::runtime_error);

    std::cout << "  [ 6g ]: Network::loadFromFile() - invalid post format (missing data)" << std::endl;
    expect_throw(facebook.loadFromFile("invalid_user_format3.txt"),std::runtime_error);

    std::cout << "  [ 6h ]: Network::loadFromFile() - invalid post format (missing data in between)" << std::endl;
    expect_throw(facebook.loadFromFile("invalid_user_format4.txt"),std::runtime_error);

    // std::cout << "  [ 6i ]: Network::loadFromFile() - valid file" << std::endl;
    // //std::cout << users << std::endl;
    // facebook.loadFromFile("valid_file.txt");
    // std::cout << "  [PASS] no exception thrown" << std::endl;

    std::cout << "  [ 7a ]: Network::getPostsByUser()" << std::endl;
    //vector<Post*> postsByRitchey = facebook.getPostsByUser("ritchey");
    //std::cout << postsByRitchey << std::endl;
    expect_throw(facebook.getPostsByUser("katelyn"),std::invalid_argument);

    std::cout << "  [ 8a ]: Network::getPostsWithTag()" << std::endl;

    std::cout << "  [ 9a ]: Network::getMostPopularHashtag() - no tie" << std::endl;

    std::cout << "  [ 9b ]: Network::getMostPopularHashtag() - tie" << std::endl;

    /*
    std::cout << "  [ 10a ]: Full Program - Small Input File (Posts By User)" << std::endl;

    std::cout << "  [ 10b ]: Full Program - Small Input File (Posts By User) (hidden)" << std::endl;

    std::cout << "  [ 10c ]: Full Program - Small Input File (Posts With Tag)" << std::endl;

    std::cout << "  [ 10d ]: Full Program - Small Input File (Most Popular Tag)" << std::endl;
    */

    /*
    std::cout << "  [ 11a ]: Full Program - Large Input File (hidden]" << std::endl;

    std::cout << "  [ 11b ]: Full Program - Large Input File (hidden)" << std::endl;

    std::cout << "  [ 11c ]: Full Program - Large Input File (hidden)" << std::endl;

    std::cout << "  [ 11d ]: Full Program - Large Input File (hidden)" << std::endl;
    */
}