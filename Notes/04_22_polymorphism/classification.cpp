#include "classification.h"

Organism::Organism(const std::string& name, Species* species) : Named(name), classification{} {
    classification.species = species;
    classification.genus = this->species()->genus;
    classification.family = genus()->family;
    classification.order = family()->order;
    classification.cLass = order()->cLass;
    classification.phylum = cLass()->phylum;
    classification.kingdom = phylum()->kingdom;
    classification.domain = kingdom()->domain;
    classification.life = domain()->life;
    classification.species->add(this);
}

Species::Species(const std::string& name, Genus* genus) : Named(name) {
    species = this;
    this->genus = genus;
    family = genus->family;
    order = family->order;
    cLass = order->cLass;
    phylum = cLass->phylum;
    kingdom = phylum->kingdom;
    domain = kingdom->domain;
    life = domain->life;
    this->genus->add(this);
}

Genus::Genus(const std::string& name, Family* family) : Named(name) {
    genus = this;
    this->family = family;
    order = family->order;
    cLass = order->cLass;
    phylum = cLass->phylum;
    kingdom = phylum->kingdom;
    domain = kingdom->domain;
    life = domain->life;
    this->family->add(this);
}

Family::Family(const std::string& name, Order* order) : Named(name) {
    family = this;
    this->order = order;
    cLass = order->cLass;
    phylum = cLass->phylum;
    kingdom = phylum->kingdom;
    domain = kingdom->domain;
    life = domain->life;
    this->order->add(this);
}

Order::Order(const std::string& name, Class* the_class) : Named(name) {
    order = this;
    this->cLass = the_class;
    phylum = the_class->phylum;
    kingdom = phylum->kingdom;
    domain = kingdom->domain;
    life = domain->life;
    this->cLass->add(this);
}

Class::Class(const std::string& name, Phylum* phylum) : Named(name) {
    cLass = this;
    this->phylum = phylum;
    kingdom = phylum->kingdom;
    domain = kingdom->domain;
    life = domain->life;
    this->phylum->add(this);
}

Phylum::Phylum(const std::string& name, Kingdom* kingdom) : Named(name) {
    phylum = this;
    this->kingdom = kingdom;
    domain = kingdom->domain;
    life = domain->life;
    this->kingdom->add(this);
}

Kingdom::Kingdom(const std::string& name, Domain* domain) : Named(name) {
    kingdom = this;
    this->domain = domain;
    life = domain->life;
    this->domain->add(this);
}

Domain::Domain(const std::string& name, Life* life) : Named(name) {
    domain = this;
    this->life = life;
    this->life->add(this);
}

Life::Life(const std::string& name) : Named(name) {}

std::string Life::fact() const { return "There is currently no consensus regarding the definition of life."; }
std::string Domain::fact() const { return "The tree of life consists of three domains: Archaea, Bacteria, and Eukarya."; }
std::string Kingdom::fact() const { return "Kingdoms are divided into smaller groups called phyla"; }
std::string Phylum::fact() const { return "Depending on definitions, the animal kingdom Animalia contains about 31 phyla, the plant kingdom Plantae contains about 14 phyla, and the fungus kingdom Fungi contains about 8 phyla"; }
std::string Class::fact() const { return "Insofar as a general definition of a class is available, it has historically been conceived as embracing taxa that combine a distinct grade of organization -— i.e. a 'level of complexity', measured in terms of how differentiated their organ systems are into distinct regions or sub-organs —- with a distinct type of construction, which is to say a particular layout of organ systems."; }
std::string Order::fact() const { return "What does and does not belong to each order is determined by a taxonomist, as is whether a particular order should be recognized at all."; }
std::string Family::fact() const { return "There are no hard rules for describing or recognizing a family, but in plants, they can be characterized on the basis of both vegetative and reproductive feature of plant species."; }
std::string Genus::fact() const { return "The 2018 annual edition of the Catalogue of Life contains 175,363 \"accepted\" genus names for 1,744,204 living and 59,284 extinct species."; }
std::string Species::fact() const { return "A species is often defined as the largest group of organisms in which any two individuals of the appropriate sexes or mating types can produce fertile offspring, typically by sexual reproduction."; }