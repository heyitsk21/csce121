/*
Linked List Concept

its a list (sequential collection of data, operations: {size, at, insert, remove})

array looks like this: [][][][][][][][]
    data in contiguous block of memory
    each element "touching" neighbors

linked list looks like this: []->[]->[]->[]->[]->[]->[]->[]
    data NOT in contiguous block of memory
    each element points to neighbor, but may not actually be physically near it 

linked list is like a chain
    elements are linked together to form a linear sequence
    each element ("node") has a value and a pointer to the next element
    a special pointer keeps track of the first element ("head")
        similar to how array's "value" is address of first element

struct Node { //the elements in a linked list; the fundamental building block of a linked list
    int value;
    Node* next;
};

class LinkedList {
    Node* head; //the first element in the linked list
};

linked lists do not support random access
    arrays do - array[index] "jumps" to the element and returns it (e.g. by reference or by value)
        this is possible because arrays are stored in contiguous memory
        recall: array[index] == *(array + index), where the value of array if the base address of the array (offset and dereference)
    to access an element by index in a linked list requires traversal
        follow the chain, counting links, until you reach the element you want
        // make head represent element at index 0



Linked List Algorithms

    Insert at head

        if empty list   head -> nullptr
            1. make a new node
                new_node->[value]->nullptr
            2. set head to new node
                head->[value]->nullptr

        else    head->[]->...->[]->nullptr
            1. make a new node
                new_node->[value]->nullptr
            2. connect new node to head of list
                             head->
                new_node->[value]->[]->...->[]->nullptr
            3. set head to new_node
                new_node->
                    head->[value]->[]->...->[]->nullptr

    Remove at head

        if empty list   head->nullptr
            1. return failure value OR throw exception

        else    head->[a]->[b]->...->[]->nullptr
            1. save pointer to head
                old_head->
                    head->[a]->[b]->...->[]->nullptr
            2. set head to head->next
                         head->
                old_head->[a]->[b]->...->[]->nullptr
            3. delete old_head
                head->[b]->...->[]->nullptr

    Insert at not head (index >= 1)

        if index out of bounds (index > size())  //if index = size(), this is the same as inserting at the end
            throw exception
        
        else
            1. traverse to node at index-1
                     curr->
                head->...->[a]->[b]->...->[]->nullptr
                           i-1   i
            2. make a new node
                new_node->[value]->nullptr
            3. attach new node to list after current node
             new_node->[value]---+
                     curr->      v
                head->...->[a]->[b]->...->[]->nullptr
                           i-1   i
            4. set current node->next to new node
                      new_node---+
                     curr->      v
                head->...->[a]->[value]->[b]->...->[]->nullptr
                        i-2        i     i+1

    Remove at not head

        if index out of bounds
            throw exception

        else
            1. traverse to node at index-1
                     curr->
                head->...->[a]->[b]->[c]->...->[]->nullptr
                           i-1   i   i+1
            2. save pointer to node that will be deleted
                  delete_node----+
                     curr->      v
                head->...->[a]->[b]->[c]->...->[]->nullptr
                           i-1   i
            4. set current node->next to to-be-deleted node->next       //deallocate b, which deallocates the pointer to c
                   delete_node->[b]---+
                     curr->           v
                head->...->[a]------>[c]->...->[]->nullptr
                           i-1        i
            5. delete the node
                     curr->
                head->...->[a]->[c]->...->[]->nullptr
                           i-1   i

    Traversal

        1. start at head (i=0)
            curr->
            head->[]->...->[a]->...->[]->nullptr
                 i=0      index
        2. until i = index or current node is nullptr, set curr to curr->next and increment i
                     curr->
            head->[]->...->[a]->...->[]->nullptr
                          i=index
            if current node is nullptr
                throw exception (index out of bounds)

    Access (at)
    
        1. traverse to index
        2. return (const) reference to value of current node
                      curr->
            head->...->[a]->[b]->[c]->...->[]->nullptr
                       i-1   i   i+1

    Size

        1. traverse to end of list, counting along the way
            curr-> ...           curr->
            head->[]->[]->...->[]->[]->nullptr
                  0   1        n-1 n
        2. return count
*/

#define debug(x) cout << "[DEBUG] (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ") " << #x << " := " << x << endl;

#include <iostream>

using std::cout, std::endl;

struct Node {
    int value;
    Node* next;

    Node();
};

Node::Node() : value{}, next{nullptr} {}

class LinkedList {
    Node* head;

 public:
    LinkedList();
    size_t size() const;
    int& at(size_t index);
    const int& at(size_t in) const;
    void insert(size_t index, int value);
    void remove(size_t index);
};

LinkedList::LinkedList() : head{nullptr} {}

int main() {
    LinkedList list;

    return 0;
}