#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "LinkedList.h"
#include "Node.h"
#include <cmath>

using std::cout;
using std::string;
using std::ostream;

LinkedList::LinkedList(): head(nullptr), tail(nullptr) {
	// Implement this function

}

LinkedList::~LinkedList() {
	// Implement this function
    clear();
}

LinkedList::LinkedList(const LinkedList& source): head(nullptr), tail(nullptr){
    Node* s_current = source.head ->next;
    head = new Node();
    head->data = source.head->data; //copy from source

    Node* t_current = head;
    Node* t_next = t_current->next;
    while(s_current != nullptr){
        t_next = new Node();
        t_next->data = s_current->data; //copy from source
        t_current->next = t_next;

        s_current = s_current->next;
        t_current = t_next;
        t_next = t_current->next;
    }

}

LinkedList& LinkedList::operator=(const LinkedList& source) {
    LinkedList list(source);
    std::swap(list.head,head);
    return *this;
}

void LinkedList::insert(std::string id, int fov, double volume, double center_x, double center_y, double min_x, double max_x, double min_y, double max_y)
{
    //node.data
    //cout<< "make node" << std::endl;
    Node* node1 = new Node(id,fov,volume,center_x,center_y,min_x,max_x,min_y,max_y);
    //if list is empty
    //cout << "add node" << std::endl;
    if(head == nullptr){
        head = node1;
        node1->next = nullptr;
        tail = nullptr;
        return;
    }
    //insert at head
    if(node1->data < head->data){
        //cout << "point node next" << std::endl;
        node1->next = head;
        //cout << "new head" << std::endl;
        head = node1;
        //cout << "before return" << std::endl;
        if(tail == nullptr){
            tail = head->next;
        }
        
        return;
    }

    //loop current
    Node* current = head;
    while(current != nullptr){
        //insert at tail
        if(current->next == nullptr){
            node1->next = nullptr;
            current->next = node1;
            return;
        }
        //insert when not head or tail
        
        if(node1->data < current->next->data){
            node1->next = current->next;
            current->next = node1;
            return;
        }

        current = current->next;
        //cout << "start" << std::endl;
    }

}

void LinkedList::remove(std::string id, int fov, double volume, double center_x, double center_y, double min_x, double max_x, double min_y, double max_y)
{
    // loop through 
    // find when the values/data are the same
    // change pointer
    // remove the data
    //diferent head and tail remove bc update head and tail
    //head

    Node* remove_node = new Node(id, fov, volume, center_x, center_y, min_x, max_x, min_y, max_y );
    Node* current = head;
    if(head->data == remove_node->data){
        head = current->next;
        delete current;

        delete remove_node;
        return;
    }

    Node* Next = head->next;
    while (current != nullptr){

        //middle
        std::cout << "start" << std::endl;
        if(current->next->data == remove_node->data){
            //point current next to  current's next next
            //std::cout << "in loop" << std::endl;
            current->next = Next->next;
            //std::cout << "change pointer" << std::endl;
            delete Next;
            //std::cout << "delete" << std::endl;
            //Next = current->next;
            delete remove_node;
            return;
        }
        //tail
        if(Next->data == remove_node->data && Next == tail){
            tail = current;
            delete current->next;
            tail->next = nullptr;
            delete remove_node;
            return;
        }

        //std::cout << "move current" << std::endl;
        current = Next;
        Next = current->next;
    }

}

void LinkedList::clear() 
{	
    // Implement this function
    //loop throguh
    //delete current
    //make current equal next
    //make next node = current-> next
    //loop til next is null
    //delete current after (outside of loop?)
    //set head tail = null
    
    if (head == nullptr){
        return;
    }
    // else if(head != nullptr && tail == nullptr){
    //     delete head;
    //     head = nullptr;
    //     return;
    // }

    Node* next = head->next;
    Node* current = head;
    
    while(next != nullptr){
        delete current;
        current = next;
        next = current->next;
    }
    delete current;
    head = nullptr;
    tail = nullptr;

}

string LinkedList::print() const 
{
   	// Implement this function
    std::stringstream output;
    output << "fov,volume,center_x,center_y,min_x,max_x,min_y,max_y";
    output << "\n";

    Node* current = head;
    while(current != nullptr){
        output << current->data.id;
        output << ",";
        output << current->data.fov;
        output << ",";
        output << current->data.volume;
        output << ",";
        output << current->data.center_x;
        output << ",";
        output << current->data.center_y;
        output << ",";
        output << current->data.min_x;
        output << ",";
        output << current->data.max_x;
        output << ",";
        output << current->data.min_y;
        output << ",";
        output << current->data.max_y;
        output << "\n";
        current = current->next;

    }
    return output.str();
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}

// given a fov number, count the cells observed in that fov
int LinkedList::countN(int fov)
{
	/* Do not modify this function */
    int count = 0;
    Node* cur = head;
    while (cur)
    {
        if (cur->data.fov == fov)
            count++;
        cur = cur->next;
    }
    return count;
}

/* given a fov number, compute the average volume of all the cells observed in
 * that fov
 */
double LinkedList::average(int fov)
{
    //m = k count -- countN()
    //vol = volume
    //avg = (sum of vol from i to m)/m

    //loop 
    //check if current data fov = fov
    double m = countN(fov);
    double vol = 0;
    double avg;

    Node* current = head;
    while(current != nullptr){
        if(current->data.fov == fov){
            vol += current->data.volume;
        }
        current = current->next;
    }

    avg = vol/m;
    return avg;
}

/* given a fov number, compute the variance volume of all the cells observed in
 * that fov
 */
double LinkedList::variance(int fov)
{
	/* Do not modify this function */
    double sum = 0;
    double avg = average(fov);
    int count = countN(fov);

    if (count == 0)
        return -1;

    Node* cur = head;
    while (cur)
    {
        if (fov == cur->data.fov)
            sum += (cur->data.volume - avg) * (cur->data.volume - avg);
        cur = cur->next;
    }

    return sum/count;
}

/* given a fov number, remove outliers
 */


string LinkedList::outliers(int fov, int k, int N){

    Node* current = head;
    double vol = current->data.volume;
    double delta = sqrt(variance(fov));
    double upper = average(fov) + k * delta;
    double lower = average(fov) - k * delta;
    int count = 0;
    string output;

    if(countN(fov) < N){
            return "Less than N cells in fov k";
        }
    else{
        while (current != nullptr){    
            if(vol > upper || vol < lower){
                remove(current->data.id,current->data.fov, current->data.volume,current->data.center_x,current->data.center_y,current->data.min_x,
                current->data.max_x, current->data.min_y, current->data.max_y);
                count += 1;
            } 
            current = current->next;
        }
        output = std::to_string(count) + " cells are removed";
        return output;
    }
}

