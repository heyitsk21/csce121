/*
Class Zoo {
  Attributes {
	- name : Text 
	- address : Location
      - menagerie : Collection { aggregation of Animal }
  }
  Methods {
	+ Zoo(name : Text)
      + getName() : Text
	+ getAddress() : Location
	+ getAnimal( name : Text ) : Animal
	+ addAnimal(newAnimal : Animal)
  }
}

Class Animal {
  Attributes {
	- name : Text 
	- genus : Text
      - species : Text
	- weight : Text
	- height : Text
	- isNocturnal : Boolean
  }
  Methods {
	+ Animal( name : Text, genus : Text, species: Text, nocturnal : Boolean )
      + getName() : Text
	+ getGenus() : Text
	+ getSpecies() : Text
	+ getWeight() : Number
	+ getHeight() : Number
	+ getNocturnal() : Boolean
	+ setWeight() : Number
	+ setHeight() : Number
  }
}

Class Location {
  Attributes {
	- name : Text 
	- streetNumber : Number
      - streetName : Text
	- city : Text
	- state : Text
	- isNocturnal : Boolean
  }
  Methods {
	+ Location ( name : Text )
      + getName() : Text
	+ getStreetNumber() : Number
	+ getStreetName() : Text
	+ getCity() : Text
	+ getState() : Text
	+ getZip() : Text
	+ setStreetNumber( number : Number )
	+ setStreetName( street : Text )
	+ setCity( city : Text )
	+ setState( state: Text )
	+ setZip( zip : Text )
  }
}
*/
#include <iostream>
#include <string>
#include <vector>
using std::string, std::vector;

class Location {
//asdf
public:
    //asdf
};

class Animal {
    string name;
public:
    Animal() : name{"bob"} {};
    string getName() const /*!!!const method!!!*/{return name;}
};

class Zoo {
    string name;
    Location address;
    vector<Animal> menagerie;

public:
    Zoo(string name);
    const string& getName();
    const Location& getAddress();
    const Animal& getAnimal(const string& name); //if passing a string parameter, good idea to pass as a const reference
    void addAnimal(const Animal& newAnimal);

    Zoo& operator<<(const Animal& bob){
        addAnimal(bob);
    }
};

Zoo::Zoo(string name) /*constructor*/: name/*member*/{the_name/*the actual value*/}, address{}, menagerie{} {}
const string& Zoo::getName() const /*!!!!!!*/ { return name; }
const Location& Zoo::getAddress() const /*!!!!!!*/ { return address; }
const Animal& Zoo::getAnimal(const string& name) {
    for (const Animal& a : menagerie){
        if (a.getName() == name){
            return a;
        }
    }
    throw std::runtime_error("animal with name "+name+" not found.");
}
void Zoo::addAnimal(const Animal& newAnimal) {
    menagerie.push_back(newAnimal);
}

std::ostream& operator<<(std::ostream& os, const Zoo& zoo){
    return os << zoo.getName(); // << " has " << ;
}

int main() {
    Zoo z("College Station Zoo");
    std::cout << z << std::endl;

    Animal bob;
    z << bob;

    //z.getName() = "San Diego Zoo"; <-- invalid; 'operator=' goes to a const string
}