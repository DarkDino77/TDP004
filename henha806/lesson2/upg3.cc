#include <iostream>

class Element 
{
public:
    Element(Element* next, int value) 
    : next(next), value(value)
    {}

    Element* next;
    int value;
};

int main()
{
    // Skapa en pekare "first" som pekar på elementet.
    Element* first = new Element(nullptr, 5);
    (first -> next) = first;

    // --- UPG3 ---
    // Sätt första elementets pekare till ett nytt element med värdet 9.
    first -> next = new Element(nullptr,9);

    return 0;
}