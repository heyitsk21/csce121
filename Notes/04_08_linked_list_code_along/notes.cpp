/*

target tasks for today:
* draw pictures of linked list operations
* students implement `insert` operation
* if time permits, we start writing tests for `at` or `remove`


target tasks for 04/11:
    * get updated linked list ica starter code from https://github.tamu.edu/pcr/csce-12x-spring22
        + rename files to get rid of "_starter"
        + update #include statements in notes.cpp and linkedlist.cpp
        + update `insert` to use your version from last time
        + run `make run`
    * students finish writing unit tests for `remove` and implement `remove` operation
        + write some tests, then write some code to pass the tests
        + submit your remove method and tests to https://docs.google.com/forms/d/e/1FAIpQLSdPs2CXRcvuaASBhuTjiRZd3PKglsK7JSL-B2BV_zaRsAexfw/viewform?usp=sf_link

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
            1. return failure value or throw exception

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

        if index out of bounds (index > size())
            return failure value or throw exception
        
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
                           i-1     i     i+1

    Remove at not head

        if index out of bounds (index >= size())
            retrn failure value or throw exception

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
            4. set current node->next to to-be-deleted node->next 
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
                  i=0     index
        2. until i = index or current node is nullptr, set curr to curr->next and increment i (-> means derefernce and access: ptr->member === (*ptr).member)
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
#include "linkedlist.h"
#include "tests.h"

using std::cout, std::endl;

namespace {
    bool test_passed = true;
}

bool test_create() {
    // pre
    // N/A

    // action
    LinkedList list;

    // post
    expect(list.get_head() to_be nullptr);
    expect(list.size() to_be 0);

    END_TEST;
}

bool test_insert_at_head() {
    // pre
    LinkedList list;
    assert(list.size() is 0);

    // action
    list.insert(0, 1);

    // post
    expect(list.size() to_be 1);
    const LinkedList::Node* node = list.get_head();
    assert(node is_not nullptr);
    expect(node->value to_be 1);

    // pre
    assert(list.size() is 1);

    // action
    list.insert(0, 2);

    // post
    expect(list.size() to_be 2);
    assert(node is_not nullptr);
    expect(node->value to_be 1);
    node = list.get_head();
    assert(node is_not nullptr);
    expect(node->value to_be 2);
    assert(node->next is_not nullptr);
    expect(node->next->value to_be 1);

    END_TEST;
}

bool test_insert_at_tail() {
    // pre
    LinkedList list;
    assert(list.size() is 0);

    // action
    list.insert(0, 1);

    // post
    expect(list.size() to_be 1);
    const LinkedList::Node* node = list.get_head();
    assert(node is_not nullptr);
    expect(node->value to_be 1);

    // pre
    assert(list.size() is 1);

    // action
    list.insert(1, 2);

    // post
    expect(list.size() to_be 2);
    assert(node is_not nullptr);
    expect(node->value to_be 1);
    assert(list.get_head() is node);
    assert(node is_not nullptr);
    expect(node->value to_be 1);
    assert(node->next is_not nullptr);
    expect(node->next->value to_be 2);

    // pre
    assert(list.size() to_be 2);

    // action
    list.insert(2, 3);

    // post
    expect(list.size() to_be 3);
    assert(node is_not nullptr);
    expect(node->value to_be 1);
    node = list.get_head();
    assert(node is_not nullptr);
    expect(node->value to_be 1);
    assert(node->next is_not nullptr);
    expect(node->next->value to_be 2);
    assert(node->next->next is_not nullptr);
    expect(node->next->next->value to_be 3);

    END_TEST;
}

bool test_insert_in_middle() {
    // pre
    LinkedList list;
    assert(list.size() is 0);

    // action
    list.insert(0, 1);

    // post
    expect(list.size() to_be 1);
    const LinkedList::Node* node = list.get_head();
    assert(node is_not nullptr);
    expect(node->value to_be 1);

    // pre
    assert(list.size() is 1);

    // action
    list.insert(1, 2);

    // post
    expect(list.size() to_be 2);
    assert(node is_not nullptr);
    expect(node->value to_be 1);
    assert(list.get_head() is node);
    assert(node is_not nullptr);
    expect(node->value to_be 1);
    assert(node->next is_not nullptr);
    expect(node->next->value to_be 2);

    // pre
    assert(list.size() is 2);

    // action
    list.insert(1, 3);

    // post
    expect(list.size() to_be 3);
    assert(node is_not nullptr);
    expect(node->value to_be 1);
    node = list.get_head();
    assert(node is_not nullptr);
    expect(node->value to_be 1);
    assert(node->next is_not nullptr);
    expect(node->next->value to_be 3);
    assert(node->next->next is_not nullptr);
    expect(node->next->next->value to_be 2);

    END_TEST;
}

bool test_insert_out_of_bounds() {
    // pre
    LinkedList list;
    assert(list.size() is 0);

    // action
    expect_throw(list.insert(1, 1), std::out_of_range);

    // post
    expect(list.size() to_be 0);
    const LinkedList::Node* node = list.get_head();
    assert(node is nullptr);

    // pre
    assert(list.size() is 0);
    list.insert(0, 1);

    // action
    expect_throw(list.insert(2, 2), std::out_of_range);

    // post
    expect(list.size() to_be 1);
    node = list.get_head();
    assert(node is_not nullptr);
    expect(node->value to_be 1);

    // pre
    assert(list.size() is 1);
    list.insert(0, 2);

    // action
    expect_throw(list.insert(3, 3), std::out_of_range);

    // post
    expect(list.size() to_be 2);
    assert(node is_not nullptr);
    expect(node->value to_be 1);
    node = list.get_head();
    assert(node is_not nullptr);
    expect(node->value to_be 2);
    assert(node->next is_not nullptr);
    expect(node->next->value to_be 1);

    END_TEST;
}

int main() {
    unsigned pass_cnt = 0, fail_cnt = 0, skip_cnt = 0;

    test(create);
    test(insert_at_head);
    test(insert_at_tail);
    test(insert_in_middle);
    test(insert_out_of_bounds);

    cout << endl;
    cout << magenta << "summary:" << reset << endl;
    cout << green << pass_cnt << " tests passing." << reset << endl;
    cout << red << fail_cnt << " tests failing" << reset << endl;
    cout << yellow << skip_cnt << " tests skipped" << reset << endl;

    return 0;
}