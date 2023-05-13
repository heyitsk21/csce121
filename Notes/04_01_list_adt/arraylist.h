#ifndef ARRAYLIST_H
#define ARRAYLIST_H

// implements the List ADT using an array

#include <string>
#include "list.h"

class ArrayList : public List {
    int* _data;
    size_t _capacity;
    size_t _size;

 public:
    ArrayList();
    ArrayList(const ArrayList&);
    ~ArrayList();
    ArrayList& operator=(const ArrayList&);
    size_t size() const override;
    const int& at(size_t) const override;
    int& at(size_t) override;
    void insert(size_t, const int&) override;
    void remove(size_t) override;
};

#endif  // ARRAYLIST_H
