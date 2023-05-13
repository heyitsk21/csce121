#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "list.h"

template <typename T>
class LinkedList : public List<T> {
 // public for testing only
 public:
    struct Node {
        T value;
        Node* next;

        Node();
        ~Node() = default;
        Node(const Node&) = default;
        Node& operator=(const Node&) = default;
    };

 private:
    Node* head;

    void clear();
    void copy(const LinkedList&);

 public:
    LinkedList();

   // rule of three
   // TODO(student): declare rule of three methods here
   ~LinkedList();
   LinkedList(const LinkedList&);
   LinkedList& operator=(const LinkedList&);

   virtual size_t size() const override;
   virtual T& at(size_t index) override;
   virtual const T& at(size_t in) const override;
   virtual void insert(size_t index, const T& value) override;
   virtual void remove(size_t index) override;

   // helpers
   bool empty() const;

   // for testing only
   const Node* get_head() const;
};

// the lamest part of defining template methods outside the class
//   is the gratuitous use of the template <> declaration

template <typename T>
LinkedList<T>::Node::Node() : value{}, next{nullptr} {}

template <typename T>
LinkedList<T>::LinkedList() : head{nullptr} {}

// rule of three
// TODO(student): define rule of three methods here
template <typename T>
LinkedList<T>::~LinkedList() { clear(); }

template <typename T>
LinkedList<T>::LinkedList(const LinkedList& rhs) : LinkedList() { copy(rhs); }

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList& rhs) {
    if (this != &rhs) {
        clear();
        copy(rhs);
    }
    return *this;
}

template <typename T>
void LinkedList<T>::clear() { while (!empty()) { remove(0); } }

template <typename T>
void LinkedList<T>::copy(const LinkedList& rhs) {
    // safety check
    if (head != nullptr) {
        clear();
    }
    const Node* curr = rhs.head;
    while (curr != nullptr) {
        this->insert(this->size(), curr->value);
        curr = curr->next;
    }
}
template <typename T>
bool LinkedList<T>::empty() const { return size() == 0; }

template <typename T>
size_t LinkedList<T>::size() const { 
    Node* node = head;
    size_t sz = 0;
    while (node) {
        sz++;
        node = node->next;
    }
    return sz;
 }

template <typename T>
T& LinkedList<T>::at(size_t index) { 
    // sneaky c++ trick to reduce code duplication: use const version then cast to non-const reference
    const LinkedList& _this = *this;
    return const_cast<T&>(_this.at(index));
}

template <typename T>
const T& LinkedList<T>::at(size_t index) const {
    //if (size() == 0) { throw std::out_of_range("at: index out of range"); } // simple code to pass _a_ test (let's break it!)
    if (index >= size()) { throw std::out_of_range("at: index out of range"); } // more general/correct code
    if (index == 0) { return head->value; }
    //return head->next->value; // simplest code to pass the test
    // gotta do better this time.
    Node* curr = head; // folowing the traverse recipe
    for (size_t i = 0; i < index; i++) { curr = curr->next; }
    return curr->value; // test is passing, back to tests to see if we can break it with clever tests
}

template <typename T>
void LinkedList<T>::insert(size_t index, const T& value) {
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

template <typename T>
void LinkedList<T>::remove(size_t index) {
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
template <typename T>
const typename LinkedList<T>::Node* LinkedList<T>::get_head() const { return this->head; }


#endif  // LINKEDLIST_H