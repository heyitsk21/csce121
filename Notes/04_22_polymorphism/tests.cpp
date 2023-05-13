#include <iostream>
#include "life.h"
#include "tests.h"

#ifndef debug
#define debug(x) cout << "[DEBUG] (" << __FILE__ << ":" << __FUNCTION__ << ":" << __LINE__ << ") " << #x << " := " << (x) << endl;
#endif

using std::cout, std::endl;

namespace {
    bool test_passed = true;
}

bool test_Reveille() {
    Life* life = new Life("Life");
    Domain* eukaryota = new Eukaryota("Eukaryota", life);
    Kingdom* animalia = new Animalia("Animalia", eukaryota);
    Phylum* chordata = new Chordata("Chordata", animalia);
    Class* mammalia = new Mammalia("Mammalia", chordata);
    Order* carnivora = new Carnivora("Carnivora", mammalia);
    Family* canidae = new Canidae("Canidae", carnivora);
    Genus* canis = new Canis("Canis", canidae);
    Species* c_familiaris = new Familiaris("familiaris", canis);
    
    Organism* Reveille = new Organism("Reveille", c_familiaris);

    expect(Reveille->name() to_be "Reveille");
    expect(Reveille->species()->name() to_be "familiaris");
    expect(Reveille->genus()->name() to_be "Canis");
    expect(Reveille->family()->name() to_be "Canidae");
    expect(Reveille->order()->name() to_be "Carnivora");
    expect(Reveille->cLass()->name() to_be "Mammalia");
    expect(Reveille->phylum()->name() to_be "Chordata");
    expect(Reveille->kingdom()->name() to_be "Animalia");
    expect(Reveille->domain()->name() to_be "Eukaryota");
    expect(Reveille->life()->name() to_be "Life");

    expect(Reveille->species()->fact() to_be "The domestic dog is a domesticated descendant of the wolf and is characterized by an upturning tail.");
    expect(Reveille->species()->Species::fact() to_be "A species is often defined as the largest group of organisms in which any two individuals of the appropriate sexes or mating types can produce fertile offspring, typically by sexual reproduction.");
    expect(Reveille->species()->Classification::fact() to_be "The Swedish botanist Carl Linnaeus is regarded as the founder of the current system of taxonomy, as he developed a ranked system known as Linnaean taxonomy for categorizing organisms and binominal nomenclature for naming organisms.");

    delete life;

    END_TEST;
}

bool test_BlueWhale() {
    {
        Life* life = new Life("Life");
        Domain* eukaryota = new Eukaryota("Eukaryota", life);
        Kingdom* animalia = new Animalia("Animalia", eukaryota);
        Phylum* chordata = new Chordata("Chordata", animalia);
        Class* mammalia = new Mammalia("Mammalia", chordata);
        Order* artiodactyla = new Carnivora("Artiodactyla", mammalia);
        Family* balaenopteridae = new Canidae("Balaenopteridae", artiodactyla);
        Genus* balaenoptera = new Canis("Balaenoptera", balaenopteridae);
        Species* balaenoptera_musculus = new Familiaris("Balaenoptera Musculus", balaenoptera);
        
        Organism* BlueWhale = new Organism("Blue Whale", balaenoptera_musculus);

        expect(BlueWhale->name() to_be "Blue Whale");
        expect(BlueWhale->species()->name() to_be "Balaenoptera Musculus");
        expect(BlueWhale->genus()->name() to_be "Balaenoptera");
        expect(BlueWhale->family()->name() to_be "Balaenopteridae");
        expect(BlueWhale->order()->name() to_be "Artiodactyla");
        expect(BlueWhale->cLass()->name() to_be "Mammalia");
        expect(BlueWhale->phylum()->name() to_be "Chordata");
        expect(BlueWhale->kingdom()->name() to_be "Animalia");
        expect(BlueWhale->domain()->name() to_be "Eukaryota");
        expect(BlueWhale->life()->name() to_be "Life");

        expect(BlueWhale->species()->fact() to_be "Reaching a maximum confirmed length of 29.9 meters (98 ft) and weighing up to 199 metric tons (196 long tons; 219 short tons), the Blue Whale is the largest animal known to have ever existed.");
        expect(BlueWhale->species()->Species::fact() to_be "A species is often defined as the largest group of organisms in which any two individuals of the appropriate sexes or mating types can produce fertile offspring, typically by sexual reproduction.");
        expect(BlueWhale->species()->Classification::fact() to_be "The Swedish botanist Carl Linnaeus is regarded as the founder of the current system of taxonomy, as he developed a ranked system known as Linnaean taxonomy for categorizing organisms and binominal nomenclature for naming organisms.");

        delete life;
    }

    {
        // TODO(student): define another test case here
    }

    // TODO(student): and so on...

    END_TEST;
}

int main() {
    unsigned pass_cnt = 0, fail_cnt = 0, skip_cnt = 0;

    test(Reveille);
    test(BlueWhale);

    cout << endl;
    cout << magenta << "summary:" << reset << endl;
    cout << green << pass_cnt << " tests passing." << reset << endl;
    cout << red << fail_cnt << " tests failing." << reset << endl;
    cout << yellow << skip_cnt << " tests skipped." << reset << endl;

    return 0;
}