#ifndef CLASSIFICATION_H
#define CLASSIFICATION_H

#include <string>
#include <set>

class Life;
class Domain;
class Kingdom;
class Phylum;
class Class;
class Order;
class Family;
class Genus;
class Species;

struct Classification {
    Species*  species   = nullptr;
    Genus*    genus     = nullptr;
    Family*   family    = nullptr;
    Order*    order     = nullptr;
    Class*    cLass     = nullptr;
    Phylum*   phylum    = nullptr;
    Kingdom*  kingdom   = nullptr;
    Domain*   domain    = nullptr;
    Life*     life      = nullptr;

    virtual std::string fact() const { return "The Swedish botanist Carl Linnaeus is regarded as the founder of the current system of taxonomy, as he developed a ranked system known as Linnaean taxonomy for categorizing organisms and binominal nomenclature for naming organisms."; }  
    //VIRTUAL: can be overridden by subclass
    virtual ~Classification() = default;
};

class Named {
    std::string _name;

 public:
    Named(const std::string& name) : _name{name} {}
    virtual ~Named() = default;
    const std::string& name() const { return _name; }
          std::string& name()       { return _name; }
};

template <typename T>
class Aggregate {
    std::set<T*> Ts;

 public:
    Aggregate() : Ts{} {}
    virtual ~Aggregate() { for (T* t : Ts) delete t; }
    void add(T* t) { Ts.insert(t); }
};

class Organism : public Named {
    Classification classification;

 public:
    Organism(const std::string&, Species*);
    Organism(const Organism&) = default;
    Organism& operator=(const Organism&) = default;

    const Species*  species()   const { return classification.species; }
    const Genus*    genus()     const { return classification.genus; }
    const Family*   family()    const { return classification.family; }
    const Order*    order()     const { return classification.order; }
    const Class*    cLass()     const { return classification.cLass; }
    const Phylum*   phylum()    const { return classification.phylum; }
    const Kingdom*  kingdom()   const { return classification.kingdom; }
    const Domain*   domain()    const { return classification.domain; }
    const Life*     life()      const { return classification.life; }
};

class Species : public Classification, public Named, public Aggregate<Organism> {
 public:
    Species(const std::string&, Genus*);
    virtual std::string fact() const override;
};

class Genus : public Classification, public Named, public Aggregate<Species> {
 public:
    Genus(const std::string&, Family*);
    virtual std::string fact() const override;
};

class Family : public Classification, public Named, public Aggregate<Genus> {
 public:
    Family(const std::string&, Order*);
    virtual std::string fact() const override;
};

class Order : public Classification, public Named, public Aggregate<Family> {
 public:
    Order(const std::string&, Class*);
    virtual std::string fact() const override;
};

class Class : public Classification, public Named, public Aggregate<Order> {
 public:
    Class(const std::string&, Phylum*);
    virtual std::string fact() const override;
};

class Phylum : public Classification, public Named, public Aggregate<Class> {
 public:
    Phylum(const std::string&, Kingdom*);
    virtual std::string fact() const override;
};

class Kingdom : public Classification, public Named, public Aggregate<Phylum> {
 public:
    Kingdom(const std::string&, Domain*);
    virtual std::string fact() const override;
};

class Domain : public Classification, public Named, public Aggregate<Kingdom> {
 public:
    Domain(const std::string&, Life*);
    virtual std::string fact() const override;
};

class Life : public Classification, public Named, public Aggregate<Domain> {
 public:
    Life(const std::string&);
    virtual std::string fact() const override;
};

#endif  // CLASSIFICATION_H