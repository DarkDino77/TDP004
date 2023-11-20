#include <iostream>

class Element 
{
public:
    Element(Element* next, int value) 
    : next(next), value(value)
    {}

    ~Element()
    {
        delete next;
    }

    Element* next;
    int value;
};

int main()
{
    Element* first = new Element(nullptr, 5);
    (first -> next) = first;
    (first -> next) = new Element(nullptr,9);
    (first -> next) = new Element((first -> next), 8);

    delete first;

    /*
                 [First] -> [5| ] -> [8| ] -> [9|\]
    Delete order:             3        2        1
    
    Note: First pointer is never deleted.
    */

    std::cout << first << std::endl;

    return 0;
}