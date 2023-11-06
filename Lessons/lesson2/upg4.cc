/*
För att skapa den nya figuren där "first" pekar på elementet med "value" 5,
och det elementets "next" pekar på det nya elementet med "value" 8, som i sin tur har "next" till 9, 
och slutligen "next" till nullptr, kan du göra följande ändringar i koden:
*/

#include <iostream>

class Element {
public:
    Element* next;
    int value;

    Element(Element* next, int value) : next(next), value(value) {}
};

int main() {
    // Skapa elementen
    Element* element4 = new Element(nullptr, 9);  // Det nya elementet
    Element* element3 = new Element(element4, 8);  // Det nya elementet
    Element* element2 = new Element(element3, 5);
    Element* element1 = new Element(element2, 3);

    // Peka på det första elementet
    Element* first = element2;  // "first" pekar nu på elementet med "value" 5

    // Nu pekar "first" på elementet med "value" 5,
    // som i sin tur pekar på det nya elementet med "value" 8,
    // som i sin tur pekar på elementet med "value" 9,
    // och det sista elementet har "next" som är nullptr.

    // Använd elementen eller gå igenom listan som du behöver.

    // Kom ihåg att deallokera minnet när du inte längre behöver elementen:
    delete element1;
    delete element2;
    delete element3;
    delete element4;

    return 0;
}
/*
I denna kod har vi lagt till två nya element (8 och 9) i listan, precis som du beskrev det. 
Nu pekar "first" på elementet med "value" 5, och listan är uppdaterad med de nya elementen.
*/