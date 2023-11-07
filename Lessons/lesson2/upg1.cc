/*
För att skapa den beskrivna figuren i C++ med en klass som heter "Element" och konstruktorn "Element(Element* next, int value)",
kan du göra följande:
*/


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
    //[first] -> [10 | *this]
    
    return 0;
}