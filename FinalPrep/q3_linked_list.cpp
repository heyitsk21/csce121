#include <stdexcept>
#include "linked_list.h"
#include <iostream>

int LinkedList::at(size_t index) const {
  Node *curr = head;
  size_t size = 0;
  Node *temp = head;
  
  while(curr != nullptr){
    ++size;
    curr = curr->next;
  }

  if(index > size){
    throw std::out_of_bounds_error("Out of bounds");
  }

  //test index 2
  // [1 , 2 , 3, 4]
  size_t count = 0;
  while(count < index){
    temp=temp->next;
    ++count;
  }
  
  if(index == 0){
    return head->value;
  }
  
  return temp->value;
}

void LinkedList::insert(size_t index, int value) {
  int i = 0;
  Node *prev = nullptr;
  Node *marker = head;
  Node *curr = head;
  int size = 0;


  while(curr!=nullptr){
  ++size;
  curr = curr->next;
  }

  if(size < index){
    throw std::out_of_range("Not in bounds");
  }

  while(marker != nullptr && i < index){
    prev = marker;
    marker = marker->next;
    ++i;
  }

  if((marker==nullptr) && i < index){
  //  return false;
    std::cout << "False";
  }

  Node *insert = new Node(value);

  if(prev != nullptr){
    prev->next = insert;
  }
  else{
    head = insert;
  }

  insert->next = marker;
  if(insert->next == nullptr){
    tail = insert;
  }
 // return true;
}




void LinkedList::merge(const LinkedList& other) {
  // TODO(student): merge the other list into this list

  // OG [1,2,3,4]
  // Other [5,7,6,8]
  // New [5, 1, 2, 3, 7, 4, 6, 8]
  Node *sizeList = head;
  Node *sizeOther = other->head;
  Node *sizeNew = head;
  Node *marker = head; //1
  Node *curr = head;  //1
  Node *oldHead = head; // 1
  Node *temp = other->head; // 5
  Node *prev = nullptr;

  int size_before = 0;
  int size_other = 0;
  int size_merged = 0;

  while(sizeList != nullptr){
    sizeList = sizeList->next;
    ++size_before;
  }

while(sizeOther != nullptr){
    sizeOther = sizeOther->next;
    ++size_Other;
  }
  
  head = temp;
  head->next = oldHead; // [5, 1, 2, 3, 4]

  size_t count = 1;
  size_t i = 0;
  
  while(curr != nullptr){
    
    if(count % 3 == 0){
      
      while(marker != nullptr && i < count){
      prev = marker;
      marker = marker->next;
      ++i;
  }

  Node *insert = temp->next;

  prev->next = insert;
      
  insert->next = marker;
  if(insert->next == nullptr){
      tail = insert;
    }
  }
    curr = curr->next;
    ++count;
}  


  while(sizeNew != nullptr){
    sizeNew = sizeNew->next;
    ++size_merged;
  }

  //This means the other list was bigger
  // OG [1,2,3,4]
  // Other [5,7,6,8,9,10]
  // New [5, 1, 2, 3, 7, 4, 6]
  // Should be [5,1,2,3,7,4,6,8,9,10]
  Node *prev2 = tail;
  while(size_merged != (size_other + size_before)){
    tail = insert->next;
    prev2->next = tail;
    ++size_merged;
  }
}
