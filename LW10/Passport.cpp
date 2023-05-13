// Class file for Passport class

#include "Passport.h"

using std::string, std::vector;

// Mandatory
// Constructor for Passport class
// TODO(student): implement constructor using member initializer list
Passport::Passport(string camperName, bool isJuniorPassport) : camperName(camperName), isJuniorPassport(isJuniorPassport), parksVisited(vector<StatePark*>()) {}

// Mandatory
// Getter function for data member camperName
string Passport::getCamperName() {
	// TODO(student): implement getter
	return this->camperName;
}

// Mandatory
// Getter function for data member isJuniorPassport
bool Passport::checkJuniorPassport() {
	// TODO(student): implement getter
	return this->isJuniorPassport;
}

// Mandatory
// Adds a park to the passport and adds the passport to the camperLog of the park visited
void Passport::addParkVisited(StatePark* park) {
	INFO(park)
	// TODO(student): implement function
	parksVisited.push_back(park);
	park->addCamper(this);
		//calling addCamper from StatePark class
		// but since "park" is a reference to a StatePark, it needs to use "->"
}

// Option B
// Calculates the total number of miles hiked by the camper
double Passport::getMilesHiked() {
	// TODO(student): implement function
	return 0.0;
}

// Option B
// Calculates the hiker level of the camper based on the number of miles hiked
int Passport::getHikerLevel() {
	// TODO(student): implement function
	return 0;
}