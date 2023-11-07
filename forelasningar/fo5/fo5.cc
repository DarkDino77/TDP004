#include <string>
#include <iostream>

using namespace std;

char x{'A'}; // x['A']
char y{'B'}; // y['B']

// char* ptr{}; // ptr[\]  Pekare - En variabel som innehåller en address.

// 32-bit system: pekare är 4 bytes.
// 64-bit system: pekare är 8 bytes. <--

char* ptr{&x}; // ptr == 0x4 <-- adress för variabeln x
// ptr[]--------> x['A']

ptr = &y;
// ptr[]--------> y['B']

int first_main()
{
    string text{"Hi"};
    string* pointer{&text};
    std::cout << "Address: "
         << pointer << "\n";
    std::cout << "Data: "
         << *pointer << endl; // Används för att komma åt datan som variabeln pekar på. *pointer = "Hello";
         return 0;
}

// string [begin][end][capacity] pekare på sträng-innehållet, end pekar på första adressen efter innehållet.
// string är 24 bytes stor. (3*8 bytes). Capacity pekar på sista adressen på utrymmet som strängen kan fyllas ut till.

/*
-------
[ x=5 ] <- Stacken, Automatiska variabler - skapas och läggs på ett specifikt ställe i minnet, och förstörs automatiskt.
[ x=7 ]
[ x=3 ]
-------
[ 'A' ] <- Heap:en, Måste hanteras manuellt - Måste skapa och ta bort själv.
-------
[\\\\\] <- Reserverat för OS, 0x0.
-------
*/

char* pointer{}; // nullptr <- pekar på ingeting.
char* poiinter{new char{'A'}}; // Lägger till en variabel i heap:en.
// pointer[]---------> ['A']

{ // [Minnesläcka]
    char* pointer{new char{'A'}}
} // variabeln 'pointer' försvinner då den hanterades i stacken. Men 'A' ligger kvar i heap:en = Minnesläcka.
std::cout << "slut";

{ // [Ingen minnesläcka]
    char* pointer{new char{'A'}}
    delete pointer; // Tar bort 'A' från heap:en. Pekaren pekar fortfarande på adressen
    pointer = nullptr; // Tar bort pointern.
}
std::cout << "slut";

// För varje new, ska enbart en delete finnas.

int main()
{
    string* pointer{ new string{"A string"} };
    std::cout << (*pointer).substr(0,3) << "\n";
    std::cout << pointer -> substr(0,3) << endl; // 'pointer ->' = '(*pointer)'
    delete pointer;
}