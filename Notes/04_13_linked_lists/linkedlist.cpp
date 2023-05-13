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

int& LinkedList::at(size_t index) { 
    // if (size() == 0) {
    //     throw std::out_of_range("at: index out of range");
    // }
    if (size() <= index) {
        throw std::out_of_range("at: index out of range");
    }
    if (index == 0) { 
        return head->value; 
    }
    //return head->next->value; // simplest code to pass the test
    // gotta do better this time
    Node* curr = head; // following the traverse recipe
    for (size_t i = 0; i < index; i++){
        curr = curr->next;
    }
    return curr->value; // test is passing, back to tests to see if we can break it with clever tests
}
/*              const\/       non-const/\          */
const int& LinkedList::at(size_t index) const { 
    // if (size() == 0) {
    //     throw std::out_of_range("at: index out of range");
    // }
    if (size() <= index) {
        throw std::out_of_range("at: index out of range");
    }
    if (index == 0) { 
        return head->value; 
    }
    //return head->next->value; // simplest code to pass the test
    // gotta do better this time
    Node* curr = head; // following the traverse recipe
    for (size_t i = 0; i < index; i++){
        curr = curr->next;
    }
    return curr->value; // test is passing, back to tests to see if we can break it with clever tests
}

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

void LinkedList::remove(size_t index) {
    if (index >= size()) {
        throw std::out_of_range("remove: index out of bounds");
    }

    if (index == 0) {
        // remove the head
        // 1. save pointer to head
        Node* old_head = head;
        // 2. set head to head->next
        head = head->next;
        // 3. delete old_head
        delete old_head;
    } else {
        // remove not head
        // 1. traverse to node at index-1
        Node* curr = head;
        for (size_t i = 0; i < index-1; i++) { curr = curr->next; }
        // 2. save pointer to node that will be deleted
        Node* node_to_be_deleted = curr->next;
        // 3. set current node->next to to-be-deleted node->next
        curr->next = node_to_be_deleted->next;
        // 4. delete the node
        delete node_to_be_deleted;
    }
}

// for testing only
const LinkedList::Node* LinkedList::get_head() const { return this->head; }
