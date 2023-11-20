// En vanlig variabel tar upp en egen plats i minnet och är tillgänglig för alla funktioner i samma scope.
int x{10}; // Tar upp varsin plats
int y{20}; // Tar upp varsin plats

int z{x + y}; // Kan läsas och ändras i aktuella scopet.


// En medlemsvariabel tar upp en egen variabel i minnet och skapas som en kopia när en instans av ett objekt skapas.
// Den är tillgänglig för alla objektets funktioner.
class Dog
{
public:
    Dog(){};

    void set_legs(int legs)
    {
        num_legs = legs;
    }

private:
    int num_legs;
};

int main()
{
    Dog dofus{};
    dofus.set_legs(4); // Ändrar enbart variabeln för specifika instansen.

}

// En statisk medlemsvariabel delas med alla intanser av en klass. Alla instancer pekar på samma adress i minnet.
class Person
{
public:
    Person(){};
    int static max_age; // Du dör när du är gammal nog:(
};

int main()
{
    Person::max_age = 99; // Definition.
}