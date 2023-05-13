#include "linked_list.h"
#include <iostream>
#include <string>

using std::cout, std::endl, std::string, std::ostream;

void MyList::add(const std::string& name, int score) {
    // TODO(student)
    MyNode* currNode = new MyNode(name, score);
    if (this->_head == nullptr){ //adding to an empty list
        //MyNode* currNode = new MyNode(name, score);
        _head = currNode;
        _tail = currNode;
        //_size += 1;
    } else { //add to the tail end
        //MyNode* currNode = new MyNode(name, score);
        currNode->prev = _tail;
        _tail->next = currNode;
        _tail = currNode;
        //_size += 1;
    }
    _size += 1;
}

void MyList::clear() {
    // TODO(student)
    if (_size == 0){
        return;
    }
    
    if (_size == 1){
        delete this->_head;
        _size -= 1;
        return;
    }
    MyNode* currNode = this->_head;
    while (currNode != nullptr){
        if (currNode->next == nullptr) {
            // If at the tail, break from the while loop
            break;
        }

        currNode = currNode->next;
        delete currNode->prev;
    }
    _size = 0;
    //delete this->_head;
    delete currNode;
    return;
    /*{
        // MyNode* currNode = (this->_head)->next;
        // while (currNode != nullptr){
        //     currNode = ((this->_head)->next)->next;
        //     //delete this->head();
        //     delete currNode->prev;
        //     //_size -= 1;
        // }
        // _size = 0;
        // delete this->_head;
        // delete currNode;
        // return;
    }*/
}

bool MyList::remove(const std::string& name) {
    // TODO(student)
    return false;
}

bool MyList::insert(const std::string& name, int score, size_t index) {
    // TODO(student)
    return false;
}

MyList::MyList()
  : _size(0), _head(nullptr), _tail(nullptr) { }

MyList::~MyList() {
    clear();
}

size_t MyList::size() const {
    return _size;
}

bool MyList::empty() const {
    return _head == nullptr;
}

MyNode* MyList::head() const {
    return _head;
}

ostream& operator<<(ostream& os, const MyList& myList) {
    MyNode* _current = myList.head();
    if (_current == nullptr) {
        os << "<empty>" << endl;
        return os;
    }

    os << "[ " << _current->name << ", " << _current->score << " ]";
    _current = _current->next;
    while (_current != nullptr) {
        os << " --> [ " << _current->name << ", " << _current->score << " ]";
        _current = _current->next;
    }
    
    return os;
}

MyNode::MyNode(const std::string& name, int score)
    : name{name}, score{score}, next{nullptr}, prev{nullptr} {}
