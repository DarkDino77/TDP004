#include <iostream>

class Element 
{
public:
    Element(Element* next, int value) 
    : next{next}, value{value}
    {}

    Element* next;
    int value;
};

int main()
{
    // Skapa en pekare "first" som pekar på elementet.
    Element* first = new Element(nullptr, 5);
    (first -> next) = first;

    // --- UPG2 ---
    (*first -> next).next -> value = 10;
    (*first -> next).next -> next = nullptr;

    // Koden ovan sätter värdet i elementet till 10 och sätter pekaren som pekar på elementet självt till en "nullptr".
    first -> value = 10;
    first -> next = nullptr;
    
    return 0;
}