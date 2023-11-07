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
    //UPG3
    (first -> next) = new Element(nullptr,9);
    //[first] -> [5] -> [9 | nullptr]
    
    
    return 0;
}
/*
För att skapa den beskrivna figuren i C++ med en klass som heter "Element" och konstruktorn "Element(Element* next, int value)",
kan du göra följande:
*/
/*
#include <iostream>

class Element {
public:
    Element* next;
    int value;

    Element(Element* next, int value) : next(next), value(value) {}
};

int main() {
    // Skapa elementen
    Element* element3 = new Element(nullptr, 9);
    Element* element2 = new Element(element3, 5);
    Element* element1 = new Element(element2, 3);

    // Peka på det första elementet
    Element* first = element1;

    // Nu pekar "first" på elementet med "value"=3,
    // som i sin tur pekar på elementet med "value"=5,
    // som i sin tur pekar på elementet med "value"=9,
    // och det sista elementet har "next" som är nullptr.

    // Använd elementen eller gå igenom listan som du behöver.
    
    // Kom ihåg att deallokera minnet när du inte längre behöver elementen:
    delete element1;
    delete element2;
    delete element3;

    return 0;
}
*/
/*
Här skapar vi en kedja av element där varje element har ett "next" som pekar på nästa element och ett "value" som lagrar värdet.
I "main" funktionen skapas elementen i omvänd ordning (9 -> 5 -> 3), och "first" pekar på det första elementet med "value" 3, 
precis som du beskrev det.
*/

