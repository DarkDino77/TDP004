#include <iostream>

class Element {
public:

    Element(Element* next, int value) 
    : next(next), value(value) 
    {}

    Element* next;
    int value;

};

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
    //-------------------- UPG5----------------------
    Element* current = first;
    while (current->next != nullptr) {
        current = current->next;
    }

    // Onödig utskrift
    std::cout << "Det sista elementet har value: " << current->value << std::endl;

    return 0;
}


/*#include <iostream>

class Element {
public:
    Element* next;
    int value;

    Element(Element* next, int value) : next(next), value(value) {}
};

int main() {
    // Skapa elementen
    Element* element1 = new Element(nullptr, 3);
    Element* element2 = new Element(element1, 5);
    Element* element3 = new Element(element2, 8);

    // Peka på det första elementet
    Element* first = element3;  // "first" pekar på elementet med "value" 8

    // Hitta det sista elementet
    Element* current = first;
    while (current->next != nullptr) {
        current = current->next;
    }

    // "current" kommer nu att peka på det sista elementet

    // Skriv ut värdet på det sista elementet
    std::cout << "Det sista elementet har value: " << current->value << std::endl;

    // Deallokera minnet när du inte längre behöver elementen
    delete element1;
    delete element2;
    delete element3;

    return 0;
}
*/
/*
I den här koden används en while-loop för att iterera genom elementen i listan tills vi når det sista elementet, 
vilket har next som nullptr. När loopen är klar, kommer current att peka på det sista elementet i listan. 
Du kan sedan använda current för att komma åt eller utföra åtgärder på det sista elemente
*/