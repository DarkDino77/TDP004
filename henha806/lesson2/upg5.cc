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
    Element* first = new Element(nullptr, 5);
    (first -> next) = first;
    (first -> next) = new Element(nullptr,9);
    (first -> next) = new Element((first -> next), 8);

    Element* current = first;
    while ((current -> next) != nullptr)
    {
        current = (current -> next);
    }

    std::cout << "Sista elementets adress är: " << current << std::endl;
              
    return 0;
}