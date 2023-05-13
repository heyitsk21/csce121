#include <iostream>
#include <string>
#include <sstream>
#include "LinkedList.h"
#include "Node.h"
using namespace std;

LinkedList::LinkedList() {
	// Implement this function
	head = nullptr;
   	tail = nullptr;
}

LinkedList::~LinkedList() {
	// Implement this function
	this->clear();
}

LinkedList::LinkedList(const LinkedList& source) {
	// Implement this function
	if (source.getHead() == nullptr){
		return;
	}
	if (source.getHead() != nullptr){
		Node* sourceNode = source.getHead();
		while (sourceNode != nullptr){
			insert(sourceNode->data.id,sourceNode->data.year,sourceNode->data.month,sourceNode->data.temperature);
			sourceNode = sourceNode->next;
			if(sourceNode->next == nullptr){
				tail = sourceNode;
			}
		}
	}
	// this->head = nullptr;
	// int count = 0;
	// if (sourceNode != nullptr){
	// 	Node* newNode = new Node();
	// 	Node* prevNode = this->head;
	// 	while (sourceNode != nullptr){
	// 		newNode->id = sourceNode->id;
	// 		newNode->year = sourceNode->year;
	// 		newNode->month = sourceNode->month;
	// 		newNode->temperature = sourceNode->temperature;
	// 		if (count == 0){
	// 			this->head = newNode;
	// 			prevNode = this->head;
	// 		}
	// 		prevNode->next = sourceNode;
	// 		prevNode = prevNode->next;
	// 		sourceNode = sourceNode->next;
	// 		count++;
	// 		newNode = new Node();
	// 	}
	// }
	// if (this == nullptr){
		
	// }
}

LinkedList& LinkedList::operator=(const LinkedList& source) {
	// Implement this function
	if (this == &source){
		return *this;
	}
	// if (source.getHead() == nullptr){
	// 	return;
	// }
	if (source.getHead() != nullptr){
		Node* sourceNode = source.getHead();
		while (sourceNode != nullptr){
			insert(sourceNode->data.id,sourceNode->data.year,sourceNode->data.month,sourceNode->data.temperature);
			sourceNode = sourceNode->next;
			if(sourceNode->next == nullptr){
				tail = sourceNode;
			}
		}
	}
	return *this;
}

void LinkedList::insert(string location, int year, int month, double temperature) {
	// Implement this function

	Node* newNode = new Node(location, year, month, temperature);
	if (head == nullptr) { // if its an empty list
		head = newNode;
		tail = newNode;
		return;
	}
	if (*newNode < *head) { // dereference in order to compare the nodes themselves, not the pointers
		newNode->next = head;
		head = newNode;
		return;
	}
	if (*tail < *newNode) { // insert at the tail
		tail->next = newNode;
		tail = newNode;
		return;
	}

	Node* current = head;
	Node* previous;
	while (current != nullptr){
		if (*newNode < *current) {
			previous->next = newNode;
			newNode->next = current;
			return;
		} 
		previous = current;
		current = current->next;
	}
}

void LinkedList::clear() {
	// Implement this function
			// Node* currNode = this->getHead();
			// while (currNode != nullptr){
			//     if (currNode->next == nullptr) {
			//         // If at the tail, break from the while loop
			//         break;
			//     }
			//     currNode = currNode->next;
			//     //delete currNode->prev;
			// }
			// 	//_size = 0;
			// //delete this->_head;
			// delete currNode;
			// return;
	if (this->head == nullptr){
		return;
	}
	Node* curr = this->head;
	Node* next;
	while (curr) {
		next = curr->next;
		delete curr;
		curr = next;
	}
	this->head = nullptr;
	this->tail = nullptr;
}

Node* LinkedList::getHead() const {
	// Implement this function it will be used to help grade other functions
	return this->head;
}

string LinkedList::print() const {
	// Implement this function
	// USE STRINGSTREAM
	// return sstream.str;
	// NO: return string();
	string outputString;
	std::ostringstream oss;
	Node* newNode = head;
	while(newNode != nullptr){
		oss << newNode->data.id << " " << newNode->data.year << " " << newNode->data.month << " " << newNode->data.temperature << "\n";
		newNode = newNode->next;
	}
	outputString = oss.str();
	return outputString;
}

ostream& operator<<(ostream& os, const LinkedList& ll) {
	/* Do not modify this function */
	os << ll.print();
	return os;
}
