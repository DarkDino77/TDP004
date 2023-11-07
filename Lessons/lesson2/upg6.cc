#include <iostream>

class Element {
public:

    Element(Element* next, int value) 
    : next(next), value(value) 
    {}

    Element* next;
    int value;

};

// Rekursiv funktion för att hitta det sista elementet
Element* findLastElement(Element* current) {
    // Basfall: Om det nuvarande elementet är nullptr, är det sista elementet
    if (current == nullptr) {
        return nullptr;
    }

    // Rekursivt steg: Gå vidare till nästa element
    if (current->next == nullptr) {
        // Om nästa element är nullptr, innebär det att det nuvarande elementet är det sista
        return current;
    }

    // Annars, fortsätt rekursionen till nästa element
    return findLastElement(current->next);
}

int main() {
    // Skapa elementen som pekar på sig själv
    Element* first = new Element(nullptr, 5);
    //Skapa pekare som pekar på det första elementet
    (first -> next) = first;
    //[first] -> [5 | *this]
    (first -> next) = new Element(nullptr,9);
    //[first] -> [5] -> [9 | nullptr]
    //----------------UPG4-------------------
    Element* temp = (first -> next);
    first -> next = new Element(temp, 8);
     //[first] -> [5] -> [8] -> [9 | nullptr]

    Element* last = findLastElement(first);

    // "last" kommer nu att peka på det sista elementet

    // Skriv ut värdet på det sista elementet
    if (last != nullptr) {
        std::cout << "Det sista elementet har value: " << last->value << std::endl;
    } else {
        std::cout << "Listan är tom." << std::endl;
    }
    
    return 0;
}

/*#include <iostream>

class Element {
public:
    Element* next;
    int value;

    Element(Element* next, int value) : next(next), value(value) {}
};

// Rekursiv funktion för att hitta det sista elementet
Element* findLastElement(Element* current) {
    // Basfall: Om det nuvarande elementet är nullptr, är det sista elementet
    if (current == nullptr) {
        return nullptr;
    }

    // Rekursivt steg: Gå vidare till nästa element
    if (current->next == nullptr) {
        // Om nästa element är nullptr, innebär det att det nuvarande elementet är det sista
        return current;
    }

    // Annars, fortsätt rekursionen till nästa element
    return findLastElement(current->next);
}

int main() {
    // Skapa elementen
    Element* element1 = new Element(nullptr, 3);
    Element* element2 = new Element(element1, 5);
    Element* element3 = new Element(element2, 8);

    // Peka på det första elementet
    Element* first = element3;  // "first" pekar på elementet med "value" 8

    // Använd den rekursiva funktionen för att hitta det sista elementet
    Element* last = findLastElement(first);

    // "last" kommer nu att peka på det sista elementet

    // Skriv ut värdet på det sista elementet
    if (last != nullptr) {
        std::cout << "Det sista elementet har value: " << last->value << std::endl;
    } else {
        std::cout << "Listan är tom." << std::endl;
    }

    // Deallokera minnet när du inte längre behöver elementen
    delete element1;
    delete element2;
    delete element3;

    return 0;
}
*/


/*
I den här koden används en rekursiv funktion findLastElement för att hitta det sista elementet i listan. 
Funktionen kontrollerar om det nuvarande elementet är det sista genom att titta på dess next-pekare. 
Om det nuvarande elementet är det sista, returneras dess adress; 
annars fortsätter rekursionen till nästa element tills det sista elementet hittas.
*/