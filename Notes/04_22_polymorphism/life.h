#ifndef LIFE_H
#define LIFE_H

#include <set>
#include <string>
#include "classification.h"

class Prokaryota : public Domain {
 public:
    Prokaryota(const std::string& name, Life* life) : Domain(name, life) {}
};

class Archaea : public Kingdom {};
class Bacteria : public Kingdom {};

class Eukaryota : public Domain {
 public:
    Eukaryota(const std::string& name, Life* life) : Domain(name, life) {}
    virtual std::string fact() const override { return "Eukaryotes are organisms whose cells have a nucleus enclosed within a nuclear envelope."; }
};

class Protozoa : public Kingdom {};
class Chromista : public Kingdom {};
class Plantae : public Kingdom {};
class Fungi : public Kingdom {};

class Animalia : public Kingdom {
 public:
    Animalia(const std::string& name, Domain* domain) : Kingdom(name, domain) {}
    virtual std::string fact() const override { return "With few exceptions, animals consume organic material, breathe oxygen, are able to move, can reproduce sexually, and go through an ontogenetic stage in which their body consists of a hollow sphere of cells, the blastula, during embryonic development."; }
};

class Chordata : public Phylum {
 public:
    Chordata(const std::string& name, Kingdom* kingdom) : Phylum(name, kingdom) {}
    virtual std::string fact() const override { return "All chordates possess 5 primary characteristics at some point during their larval or adulthood stages that distinguish them from all other taxa: a notochord, dorsal hollow nerve cord, endostyle or thyroid, pharyngeal slits, and a post-anal tail."; }
};

class Mammalia : public Class {
 public:
    Mammalia(const std::string& name, Phylum* phylum) : Class(name, phylum) {}
    virtual std::string fact() const override { return "Mammals are a group of vertebrates characterized by the presence of mammary glands which, in females, produce milk for feeding their young, a neocortex, fur or hair, and three middle ear bones."; }
};

class Carnivora : public Order {
 public:
    Carnivora(const std::string& name, Class* _class) : Order(name, _class) {}
    virtual std::string fact() const override { return "Carnivora is an order of placental mammals that have specialized in primarily eating flesh"; }
};

class Canidae : public Family {
 public:
    Canidae(const std::string& name,  Order* order) : Family(name, order) {}
    virtual std::string fact() const override { return "Canidae is a biological family of dog-like carnivorans, colloquially referred to as dogs"; }
};

class Canis : public Genus {
 public:
    Canis(const std::string& name, Family* family) : Genus(name, family) {}
    virtual std::string fact() const override { return "Canis is a genus of the Caninae which includes multiple extant species, such as wolves, dogs, coyotes, and golden jackals."; }
};

class Familiaris : public Species {
 public:
    Familiaris(const std::string& name, Genus* genus) : Species(name, genus) {}
    virtual std::string fact() const override { return "The domestic dog is a domesticated descendant of the wolf and is characterized by an upturning tail."; }
};


/////////////BLUE WHALE//////////////////////

class Artiodactyla : public Order {
 public:
    Artiodactyla(const std::string& name, Class* _class) : Order(name, _class) {}
    virtual std::string fact() const override { return "aaasdf"; }
};

class Balaenopteridae : public Family {
 public:
    Balaenopteridae(const std::string& name,  Order* order) : Family(name, order) {}
    virtual std::string fact() const override { return "asdf"; }
};

class 	Balaenoptera : public Genus {
 public:
    	Balaenoptera(const std::string& name, Family* family) : Genus(name, family) {}
    virtual std::string fact() const override { return "2asdf"; }
};

class Balaenoptera_musculus : public Species {
 public:
    Balaenoptera_musculus(const std::string& name, Genus* genus) : Species(name, genus) {}
    virtual std::string fact() const override { return "Reaching a maximum confirmed length of 29.9 meters (98 ft) and weighing up to 199 metric tons (196 long tons; 219 short tons), the Blue Whale is the largest animal known to have ever existed."; }
};

#endif  // LIFE_H