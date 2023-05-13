#ifndef NODE
#define NODE

#include "TemperatureData.h"

struct Node {
	Node* next;
	TemperatureData data;
	// std::string id;
	// int year;
	// int month;
	// double temperature;

	// Default constructor
	Node()/* : next(nullptr), data(id=string(), year=0, month=0, temperature=0.0) {}*/; // remember to initialize next to nullptr
	Node(std::string id, int year, int month, double temperature)/* : next(nullptr), data(TemperatureData(id, year, month, temperature)){}*/; // remember to initialize next to nullptr

	// This operator will allow you to just ask if a node is smaller than another
	//  rather than looking at all of the location, temperature and date information
	bool operator<(const Node& b);

  // The function below is written. Do not modify it
	virtual ~Node() {}
};

#endif
