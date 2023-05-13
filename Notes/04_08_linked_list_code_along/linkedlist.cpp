#include <stdexcept>
#include "linkedlist.h"

LinkedList::Node::Node() : value{}, next{nullptr} {}

LinkedList::LinkedList() : head{nullptr} {}

size_t LinkedList::size() const { 
    Node* node = head;
    size_t sz= 0;
    while (node) {
        sz++;
        node = node->next;
    }
    return sz;
    }

int& LinkedList::at(size_t) { 
    
    return head->value; 
}

const int& LinkedList::at(size_t) const { return head->value; }

void LinkedList::insert(size_t index, const int& value) {
    //traverse through the linked list until the current node at that "index"
    //make a node out of that new value
    //point from the current node to the new node
    //point from the new node to the next node (current but 1 additional index)
    //delete the original pointer that went from current to current+1

    if (index > size()){
        throw std::out_of_range("Selected index to be inserted at is invalid");
    }

    //empty list
    if (head == nullptr){
        head = new Node;
        head-> value = value;
    } else {
        if (index == 0){
            Node* node = new Node;
            node->value = value;
            node->next = head;
            head = node;

            //delete node;
        } else {
            Node* node = new Node;
            node->value = value;
            
            // for (size_t i = 0; i<index+1; i++){
            //     node->next = 
            // }

            node->next = head;
            head = node;
            //head shouldn't change

            //delete node;
        }
    }
    
    
    // for (size_t i = 0; i < index-1; i++){
    //     List.at(i)
    // }
    
    
    // if (index != 0){
    //     Node* curr = List.at(index-1);
    //     Node toBeInserted = new Node;
    //     toBeInserted.value = value;
    //     toBeInserted->next = *List.at(index+1);
    // } else {
    //     Node curr = List.at(0);
    //     Node toBeInserted;
    //     toBeInserted.value = value;
    //     toBeInserted.next = *List.at(0);
    // }
    


}

void LinkedList::remove(size_t) {}

// for testing only
const LinkedList::Node* LinkedList::get_head() const { return this->head; }
