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

Element* find_last_element(Element* current)
{
    if((current -> next) == nullptr)
    {
        return current;
    }
    return find_last_element(current -> next);
}

int main()
{
    Element* first = new Element(nullptr, 5);
    (first -> next) = first;
    (first -> next) = new Element(nullptr,9);
    (first -> next) = new Element((first -> next), 8);

    std::cout << "Sista elementets adress är: " << find_last_element(first) << std::endl;
              
    return 0;
}