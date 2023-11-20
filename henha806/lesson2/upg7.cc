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

void insert(Element* e, int i)
{
  e = new Element(e->next, i);
  std::cout << "Insert pointer value: " << (e->next)->value << std::endl;
}

int main()
{
    Element* first = new Element(nullptr, 5);
    (first -> next) = first;
    (first -> next) = new Element(nullptr,9);
    (first -> next) = new Element((first -> next), 8);

    insert(first, 2);

    /*
    [First] -> [5| ] -> [8| ] -> [9|\]
                         ^
                  [2| ]--┘          
    */
   
              
    return 0;
}