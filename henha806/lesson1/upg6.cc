// Abstraction har som syfte att dölja onödig information för användaren. Detta innebär att endast väsentlig information
// är synlig och allt som är onödigt döljs.

// Abstraction i c++ kan implementeras dels med klasser

// Klassen grupperar all data och tillhörande funktioner och avgör vilken data som ska vara synlig utifrån.

// Detta görs via "access specifiers" där public betyder att funktioner/variabler kan kommas åt överalltifrån. 
// private betyder att den inte kan visas.

class Car
{
public:
    Car() 
    : speed(0.0)
    {};
    void change_speed(double speed);

private:
    double speed;
};

// Man kan också implementera Abstraction via header files. Detta ger användaren möjlighet att inkludera funktionalitet från
// Andra bibliotek eller klasser utan att behöva se dess uppbyggnad eller detaljer.

#include<math.h>  // <---

int main()  
{    
    int n = 4;  
    int power = 3;  
    int result = pow(n,power);

    return 0;  
} 

// Dåliga exempel
#include <string>

class Person
{
public:
    Person(){};
    std::string name;
    std::string name2;
    int age;
};

int main()
{
    Person person{};
    person.name = "Henke";
    person.name2 = "Efternamn";
    person.age = -1;
    std::string person_full_name = person.name + " " + person.name2;
}
