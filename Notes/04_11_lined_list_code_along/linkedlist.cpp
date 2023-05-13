#include <stdexcept>
#include "linkedlist.h"

LinkedList::Node::Node() : value{}, next{nullptr} {}

LinkedList::LinkedList() : head{nullptr} {}

size_t LinkedList::size() const { 
    Node* node = head;
    size_t sz = 0;
    while (node) {
        sz++;
        node = node->next;
    }
    return sz;
 }

int& LinkedList::at(size_t) { return head->value; }

const int& LinkedList::at(size_t) const { return head->value; }

void LinkedList::insert(size_t index, const int& value) {
    if (index > size()) {
        throw std::out_of_range("insert: index out of bounds");
    }
    if (head == nullptr) {
        head = new Node;
        head->value = value;
    } else {
        if (index == 0) {
            // insert at head
            Node* node = new Node;
            node->value = value;
            node->next = head;
            head = node;
        } else {
            // insert at not head
            Node* curr = head;
            for (size_t i = 0; i < index-1; i++) { curr = curr->next; }
            Node* node = new Node;
            node->value = value;
            node->next = curr->next;
            curr->next = node;
        }
    }
}

void LinkedList::remove(size_t) {
    // TODO(student): AFTER writing some tests, implement just enough to get whatever tests are written to pass
        if (index >= size()){
            throw std::out_of_range("remove: index out of bounds")
        }
        if(index == 0){
            // remove the head
            // 1. save pointer to head
            Node* old_head = head;
            // 2. set head to head->next
            head = head->next;
            // 3. delete old_head
            delete old_head;
        } else {
            
        }
     
}

// for testing only
const LinkedList::Node* LinkedList::get_head() const { return this->head; }


