#ifndef LIST_H
#define LIST_H

#include <cstddef>

// abstract (pure virtual) class List
// a sequential collection
// with operations size, at, insert, remove

class List {
 public:
    virtual size_t size() const = 0;
    virtual const int& at(size_t) const = 0; //GETTER
    virtual int& at(size_t) = 0;             //SETTER
    virtual void insert(size_t, const int&) = 0;
    virtual void remove(size_t) = 0;
    virtual ~List() {}
    // VIRTUAL: the method can be overridden by the subclass
};

#endif  // LIST_H