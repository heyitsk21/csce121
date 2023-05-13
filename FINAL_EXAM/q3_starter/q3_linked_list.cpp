#include <stdexcept>
#include "linked_list.h"

int LinkedList::at(size_t index) const {
  // TODO(student): return the value at the index

  //bounds checking
  if (size() <= index) {
    throw std::out_of_range("at: index out of range");
  }

  //edge case: if trying to access index 0
  if (index == 0) { 
    return head->value; 
  }

  //access at other indexes
  Node* curr = head;
  for (size_t i = 0; i < index; i++){
    curr = curr->next;
  }

  return curr->value;
}

void LinkedList::insert(size_t index, int value) {
  // TODO(student): insert the value at the index

  //bounds checking
  if (index > this->size()){
    throw std::out_of_range("insert: index is out of bounds");
  }

  //if inserting into an empty linked list
  if (head == nullptr){
    head = new Node;
    head->value = value;
  } else {
    if (index == 0){

      //inserting at head
      Node* node = new Node;
      node->value = value;
      node->next = head;
      head = node;

    } else {

      //inserting not at head
      Node* curr = head;
      for (size_t i = 0; i < index-1; i++) { 
        curr = curr->next; 
      }
      Node* node = new Node;
      node->value = value;
      node->next = curr->next;
      curr->next = node;

    }
  }
}

void LinkedList::merge(const LinkedList& other) {
  // TODO(student): merge the other list into this list

  //quick return if the other's head is a nullptr
  if (other.head == nullptr){
    return;
  }


  //let original list = [1,2,3]
  //other list = [9,8,7]
  //the original list should be updated to be [9,1,2,8,3,7]
  
  Node* Koriginal = head;
  Node* Kother = other.head;
  Node* Knew = other.head;//start with other's head! [9,1,2,3]
  Node* curr = head; //original list's head: 1

  size_t oldSize = 0;
  size_t otherSize = 0;
  size_t newSize = 0;

  //count the sizes of each list
    //count original's size
    while(Koriginal != nullptr){
      Koriginal = Koriginal->next;
      oldSize++;
    }
    //count other's size
    while(Kother != nullptr){
      Kother = Kother->next;
      otherSize++;
    }

  size_t counter = 1; //since we already got the new list's head node
  Knew->next = head;
  while(curr !=nullptr){
    if(counter%2 == 0){
      for (size_t index = 0; index < counter; index++){
        Knew->value = curr->value;
        Knew->next = curr->next;
      }
    }
    Knew = Knew->next;
    curr = curr->next;
  }

  //while ()

  //delete ;

  //check to see if correct number of nodes at the end
  while(Knew != nullptr){
    Knew = Knew->next;
    newSize++;
  }
  if (newSize == oldSize + otherSize){
    //std::cout<<"correct num of nodes"<<endl;
  }







  // //iterate through the other linked list
  // unsigned int counter = 0;
  // Node* curr = head;
  // for (size_t otherIndex = 0; otherIndex < other.size(); otherIndex++){

  //   //only insert a new node whenever the counter is even
  //   if (counter %2 == 0 && counter < size()){
  //     for (size_t thisIndex = 0; thisIndex < size(); thisIndex++){
  //       //Node* otherNode = 
  //     }
  //     counter++;
  //   } 
    
  //   //insert to remaining other nodes to the this list
  //   else if (counter >= size()){
  //     //for (size_t i = )
  //   }

  //   //go to the next node
  //   curr = curr->next;
  // }
}
