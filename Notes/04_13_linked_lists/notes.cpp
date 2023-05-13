/*

target tasks for today:
    * get updated linked list ica starter code from https://github.tamu.edu/pcr/csce-12x-spring22
        + rename files to get rid of "_starter"
        + update #include statement in linkedlist.cpp
        + [update `remove` to use your own version from last time]
        + run `make run`

    * write unit tests and implement `at` operation
        + write some tests, then write some code to pass the tests
        + submit your remove method and tests to https://docs.google.com/forms/d/e/1FAIpQLSfIHdT-nzzJe-6uRfhmfGKpAVKl6-j5HEfr7ZrbIDdLzDA2cw/viewform?usp=sf_link

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
            3. set current node->next to to-be-deleted node->next 
                   delete_node->[b]---+
                     curr->           v
                head->...->[a]------>[c]->...->[]->nullptr
                           i-1        i
            4. delete the node
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

#define debug(x) cout << "[DEBUG] (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ") " << #x << " := " << (x) << endl;

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
    expect(node is nullptr);

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

bool test_remove_head() {
    // pre
    LinkedList list;
    list.insert(0, 3);
    list.insert(0, 2);
    list.insert(0, 1);
    assert(list.size() is 3);
    const LinkedList::Node* head = list.get_head();
    assert(head is_not nullptr);
    assert(head->value is 1);
    assert(head->next is_not nullptr);
    assert(head->next->value is 2);
    assert(head->next->next is_not nullptr);
    assert(head->next->next->value is 3);
    assert(head->next->next->next is nullptr);

    // action
    list.remove(0);

    // post
    expect(list.size() to_be 2);
    head = list.get_head();
    assert(head is_not nullptr);
    expect(head->value to_be 2);
    assert(head->next is_not nullptr);
    expect(head->next->value to_be 3);
    expect(head->next->next to_be nullptr);


    // pre
    assert(list.size() is 2);
    head = list.get_head();
    assert(head is_not nullptr);
    assert(head->value is 2);
    assert(head->next is_not nullptr);
    assert(head->next->value is 3);
    assert(head->next->next is nullptr);

    // action
    list.remove(0);

    // post
    expect(list.size() to_be 1);
    head = list.get_head();
    assert(head is_not nullptr);
    expect(head->value to_be 3);
    expect(head->next to_be nullptr);


    // pre
    assert(list.size() is 1);
    head = list.get_head();
    assert(head is_not nullptr);
    assert(head->value is 3);
    assert(head->next is nullptr);

    // action
    list.remove(0);

    // post
    expect(list.size() to_be 0);
    head = list.get_head();
    expect(head is nullptr);

    END_TEST
}

bool test_remove_tail() {
    // pre
    LinkedList list;
    list.insert(0, 3);
    list.insert(0, 2);
    list.insert(0, 1);
    assert(list.size() is 3);
    const LinkedList::Node* head = list.get_head();
    assert(head is_not nullptr);
    assert(head->value is 1);
    assert(head->next is_not nullptr);
    assert(head->next->value is 2);
    assert(head->next->next is_not nullptr);
    assert(head->next->next->value is 3);
    assert(head->next->next->next is nullptr);

    // action
    list.remove(2);

    // post
    expect(list.size() to_be 2);
    head = list.get_head();
    assert(head is_not nullptr);
    expect(head->value to_be 1);
    assert(head->next is_not nullptr);
    expect(head->next->value to_be 2);
    expect(head->next->next to_be nullptr);


    // pre
    assert(list.size() is 2);
    head = list.get_head();
    assert(head is_not nullptr);
    assert(head->value is 1);
    assert(head->next is_not nullptr);
    assert(head->next->value is 2);
    assert(head->next->next is nullptr);

    // action
    list.remove(1);

    // post
    expect(list.size() to_be 1);
    head = list.get_head();
    assert(head is_not nullptr);
    expect(head->value to_be 1);
    expect(head->next to_be nullptr);


    // pre
    assert(list.size() is 1);
    head = list.get_head();
    assert(head is_not nullptr);
    assert(head->value is 1);
    assert(head->next is nullptr);

    // action
    list.remove(0);

    // post
    expect(list.size() to_be 0);
    head = list.get_head();
    expect(head is nullptr);

    END_TEST
}

bool test_remove_from_middle() {
    // pre
    LinkedList list;
    list.insert(0, 5);
    list.insert(0, 4);
    list.insert(0, 3);
    list.insert(0, 2);
    list.insert(0, 1);
    assert(list.size() is 5);
    const LinkedList::Node* head = list.get_head();
    assert(head is_not nullptr);
    assert(head->value is 1);
    assert(head->next is_not nullptr);
    assert(head->next->value is 2);
    assert(head->next->next is_not nullptr);
    assert(head->next->next->value is 3);
    assert(head->next->next->next is_not nullptr);
    assert(head->next->next->next->value is 4);
    assert(head->next->next->next->next is_not nullptr);
    assert(head->next->next->next->next->value is 5);
    assert(head->next->next->next->next->next is nullptr);

    // action
    list.remove(2);

    // post
    expect(list.size() to_be 4);
    head = list.get_head();
    assert(head is_not nullptr);
    expect(head->value to_be 1);
    assert(head->next is_not nullptr);
    expect(head->next->value to_be 2);
    assert(head->next->next is_not nullptr);
    expect(head->next->next->value to_be 4);
    assert(head->next->next->next is_not nullptr);
    expect(head->next->next->next->value to_be 5);
    expect(head->next->next->next->next to_be nullptr);


    // pre
    assert(list.size() is 4);
    head = list.get_head();
    assert(head is_not nullptr);
    assert(head->value is 1);
    assert(head->next is_not nullptr);
    assert(head->next->value is 2);
    assert(head->next->next is_not nullptr);
    assert(head->next->next->value is 4);
    assert(head->next->next->next is_not nullptr);
    assert(head->next->next->next->value is 5);
    assert(head->next->next->next->next is nullptr);

    // action
    list.remove(2);

    // post
    expect(list.size() to_be 3);
    head = list.get_head();
    assert(head is_not nullptr);
    expect(head->value to_be 1);
    assert(head->next is_not nullptr);
    expect(head->next->value to_be 2);
    assert(head->next->next is_not nullptr);
    expect(head->next->next->value to_be 5);
    expect(head->next->next->next to_be nullptr);


    // pre
    assert(list.size() is 3);
    head = list.get_head();
    assert(head is_not nullptr);
    assert(head->value is 1);
    assert(head->next is_not nullptr);
    assert(head->next->value is 2);
    assert(head->next->next is_not nullptr);
    assert(head->next->next->value is 5);
    assert(head->next->next->next is nullptr);

    // action
    list.remove(1);

    // post
    expect(list.size() to_be 2);
    head = list.get_head();
    assert(head is_not nullptr);
    expect(head->value to_be 1);
    assert(head->next not_to_be nullptr);
    expect(head->next->value to_be 5);
    expect(head->next->next to_be nullptr);

    END_TEST
}

bool test_remove_out_of_bounds() {
    // pre
    LinkedList list;
    assert(list.size() is 0);
    assert(list.get_head() is nullptr);

    // action
    expect_throw(list.remove(0), std::out_of_range);

    // post
    expect(list.size() to_be 0);
    expect(list.get_head() to_be nullptr);


    // pre
    list.insert(0,3);
    assert(list.size() is 1);
    const LinkedList::Node* head = list.get_head();
    assert(list.get_head() is_not nullptr);
    assert(head->value is 3);
    assert(head->next is nullptr);

    // action
    expect_throw(list.remove(1), std::out_of_range);

    // post
    expect(list.size() is 1);
    head = list.get_head();
    assert(list.get_head() is_not nullptr);
    expect(head->value to_be 3);
    expect(head->next to_be nullptr);


    // pre
    list.insert(0,1);
    list.insert(2,4);
    list.insert(1,2);
    assert(list.size() is 4);
    head = list.get_head();
    assert(list.get_head() is_not nullptr);
    assert(head->value is 1);
    assert(head->next is_not nullptr);
    assert(head->next->value is 2);
    assert(head->next->next is_not nullptr);
    assert(head->next->next->value is 3);
    assert(head->next->next->next is_not nullptr);
    assert(head->next->next->next->value is 4);
    assert(head->next->next->next->next is nullptr);

    // action
    expect_throw(list.remove(4), std::out_of_range);
    expect_throw(list.remove(5), std::out_of_range);
    expect_throw(list.remove(-1), std::out_of_range);

    // post
    expect(list.size() to_be 4);
    head = list.get_head();
    expect(list.get_head() not_to_be nullptr);
    expect(head->value to_be 1);
    assert(head->next is_not nullptr);
    expect(head->next->value to_be 2);
    assert(head->next->next is_not nullptr);
    expect(head->next->next->value to_be 3);
    assert(head->next->next->next is_not nullptr);
    expect(head->next->next->next->value to_be 4);
    expect(head->next->next->next->next to_be nullptr);

    END_TEST
}

bool test_insert_and_remove_at_tail() {
    // pre
    LinkedList list;
    assert(list.size() is 0);

    // action
    list.insert(0, 1);  // [1]->X
    list.remove(0);     // X
    list.insert(0, 1);  // [1]->X
    list.insert(1, 2);  // [1]->[2]->X
    list.remove(1);     // [1]->X
    list.insert(1, 3);  // [1]->[3]->X
    list.insert(2, 4);  // [1]->[3]->[4]->X  
    list.remove(2);     // [1]->[3]->X
    list.insert(2, 5);  // [1]->[3]->[5]->X
    list.insert(3, 6);  // [1]->[3]->[5]->[6]->X
    list.remove(3);     // [1]->[3]->[5]->X
    list.insert(3, 7);  // [1]->[3]->[5]->[7]->X

    // post
    expect(list.size() to_be 4);
    const LinkedList::Node* head = list.get_head();
    assert(head is_not nullptr);
    expect(head->value to_be 1);
    assert(head->next is_not nullptr);
    expect(head->next->value to_be 3);
    assert(head->next->next is_not nullptr);
    expect(head->next->next->value to_be 5);
    assert(head->next->next->next is_not nullptr);
    expect(head->next->next->next->value to_be 7);
    expect(head->next->next->next->next to_be nullptr);

    END_TEST
}

bool test_at_in_bounds_get() {
    /*
    testing outline
    1. make an empty list
    do for each kind of insert (into empty, at head, at tail, in middle):
        2. insert a value
        3. make a const reference to the list (to force usage of the const version of at())
        do for each valid index:
            4. expect const_ref_to_list.at(index) to return the correct value
        end
    end
    do for each kind of remove (from middle, at head, at tail):
        5. remove a value
        6. make a const reference to the list (to force usage of the const version of at())
        do for each valid index:
            7. expect const_ref_to_list.at(index) to return the correct value
        end
    end
    */

    LinkedList list;
    // head->X
    list.insert(0, 1);
    // head->[1]->X

    {
        const LinkedList& c_list = list;
        expect(c_list.at(0) to_be 1);
    }

    list.insert(0, 2);
    // head->[2]->[1]->X

    {
        const LinkedList& c_list = list;
        expect(c_list.at(0) to_be 2);
        expect(c_list.at(1) to_be 1);
    }

    // TODO(student): do { write a test, then write the code to pass the test } until all expected behaviors have tests and are correctly implemented
    
    // pre
        // LinkedList list;
        // list.insert(0, 3);
        // list.insert(0, 2);
        // list.insert(0, 1);
        // assert(list.size() is 3);
        // const LinkedList::Node* head = list.get_head();
        // assert(head is_not nullptr);
        // assert(head->value is 1);
        // assert(head->next is_not nullptr);
        // assert(head->next->value is 2);
        // assert(head->next->next is_not nullptr);
        // assert(head->next->next->value is 3);
        // assert(head->next->next->next is nullptr);

    // action

    // post
        // expect(list.size() to_be 3);
        // head = list.get_head();
        // assert(head is_not nullptr);
        // expect(head->value to_be 1);
        // assert(head->next is_not nullptr);
        // expect(head->next->value to_be 2);
        // expect(head->next->next to_be nullptr);
        // assert(head->next->next->value is 3);
        // assert(head->next->next->next is nullptr);
    expect(list.at(2) is 3);
    expect(list.at(1) is 2);
    expect(list.at(0) is 1);
    

    list.remove(0);
    {
        const LinkedList& c_list = list;
        expect(c_list.at(1) to_be 3);
        expect(c_list.at(0) to_be 2);
    }

    list.remove(0);
    {
        const LinkedList& c_list = list;
        expect(c_list.at(0) to_be 3);
    }

    END_TEST;
}

bool test_at_out_of_bounds_get() {
    /*
    testing outline
    1. make an empty list
    2. make a const reference to the list (to force usage of the const version of at())
    3. expect const_ref_to_list.at(0) to throw std::out_of_range
    do for each kind of insert (into empty, at head, at tail, in middle):
        4. insert a value
        5. make a const reference to the list (to force usage of the const version of at())
        6. expect const_ref_to_list.at(list.size()) to throw std::out_of_range 
    end
    do for each kind of remove (from middle, at head, at tail, from singleton):
        7. remove a value(s)
        8. make a const reference to the list (to force usage of the const version of at())
        9. expect const_ref_to_list.at(list.size()) to throw std::out_of_range 
    end
    */
    
    // TODO(student): do { write a test, then write the code to pass the test } until all expected behaviors have tests and are correctly implemented
    {
        // // pre
        // LinkedList list;
        // list.insert(0, 3);
        // list.insert(0, 2);
        // list.insert(0, 1);
        // assert(list.size() is 3);
        // const LinkedList::Node* head = list.get_head();
        // assert(head is_not nullptr);
        // assert(head->value is 1);
        // assert(head->next is_not nullptr);
        // assert(head->next->value is 2);
        // assert(head->next->next is_not nullptr);
        // assert(head->next->next->value is 3);
        // assert(head->next->next->next is nullptr);

        // // action
        // list.at(2);

        // // post
        // expect(list.size() to_be 3);
        // head = list.get_head();
        // assert(head is_not nullptr);
        // expect(head->value to_be 1);
        // assert(head->next is_not nullptr);
        // expect(head->next->value to_be 2);
        // expect(head->next->next to_be nullptr);
        // assert(head->next->next->value is 3);
        // assert(head->next->next->next is nullptr);
        // END_TEST;
    }


    LinkedList list;
    {
        const LinkedList& const_ref_to_list; // const ref to force usage of const version of LinkedList::at
        expect_throw(const_ref_to_list.at(0), std::out_of_range);
    }

    expect(false);

    END_TEST;
}

bool test_at_set() {
    /*
    testing outline
    1. make a list with at least 3 elements (head, middle, tail)
    do for each type of index (head=0, tail=size-1, 0<middle<size-1):
        2. set the value of the element at <index of specified type> to a different value
        3. expect the node at that index to have the new value
        4. expect all other nodes to have unchanged values
    end
    expect attempt to set the value of an element with index >= list.size() to throw std::out_of_range
    */
    
    // TODO(student): do { write a test, then write the code to pass the test } until all expected behaviors have tests and are correctly implemented
    LinkedList list;
    list.insert(0,1);
    list.insert(0,2);
    list.insert(0,3);
    list.insert(0,4);
    // 4, 3, 2, 1

    list.at(0) = 9;
    // 9 3 2 1
    assert(list.get_head() is_not nullptr);
    assert(list.get_head()->value to_be 9);

    list.at(1) = 8;
    // 9 8 2 1
    assert(list.get_head() is_not nullptr);
    assert(list.get_head()->value to_be 9);
    assert(list.get_head()->next is_not nullptr);
    assert(list.get_head()->next->value to_be 8);


    expect(false);

    END_TEST;
}

int main() {
    unsigned pass_cnt = 0, fail_cnt = 0, skip_cnt = 0;

    test(create);

    test(insert_at_head);
    test(insert_at_tail);
    test(insert_in_middle);
    test(insert_out_of_bounds);

    test(remove_head);
    test(remove_tail);
    test(remove_from_middle);
    test(remove_out_of_bounds);
    
    test(insert_and_remove_at_tail);

    test(at_in_bounds_get);
    test(at_out_of_bounds_get);
    test(at_set);
    

    cout << endl;
    cout << magenta << "summary:" << reset << endl;
    cout << green << pass_cnt << " tests passing." << reset << endl;
    cout << red << fail_cnt << " tests failing." << reset << endl;
    cout << yellow << skip_cnt << " tests skipped." << reset << endl;

    return 0;
}