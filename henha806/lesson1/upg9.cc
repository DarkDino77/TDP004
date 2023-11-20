// Det skiljs i sin tillhörighet till en klass och hur de anropas. 
// En vanlig "fri" funktion är oberoende av en specifik klass och kan användas utanför någon 
// klassdefinition. En medlemsfunktion tillhör en specifik klass och har tillgång till klassens medlemsvariabler.

#include <iostream>
using namespace std;

class Person {
public:
    int name = "";
    void print_name() {
        cout << name << endl;
    }
};

void hello(std::string name) {
    cout << "Hej "<< name << endl;
}

int main() {
    Person person;

    // Medlemsfunktion
    person.memberFunction();

    // Fri funktion
    hello(person.);

    return 0;
}

// För att anropa en medlemsfunktion krävs en instans av klassen, medan en "fri" funktion kan anropas direkt utan att 
// vara associerad med någon specifik instans eller klass.