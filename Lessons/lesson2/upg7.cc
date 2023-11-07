

class Element {
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

    insert(first, 2);
    
    /*
    [First] -> [5| ] -> [8| ] -> [9|\]
                          ^
                          |
                        [2| ]
    */
    
    return 0;
}