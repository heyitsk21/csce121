#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "list.h"

class LinkedList : public List {
 // public for testing only
 public:
    struct Node {
        int value;
        Node* next;

        Node();
    };

 private:
    Node* head;

 public:
    LinkedList();
    virtual size_t size() const override;
    virtual int& at(size_t index) override;
    virtual const int& at(size_t in) const override;
    virtual void insert(size_t index, const int& value) override;
    virtual void remove(size_t index) override;

    // for testing only
    const Node* get_head() const;
};

#endif  // LINKEDLIST_H