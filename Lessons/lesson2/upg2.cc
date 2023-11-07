
class Element {
public:

    Element(Element* next, int value) : next(next), value(value) {}

    Element* next;
    int value;

};

int main() {
    // Skapa elementen som pekar på sig själv
    Element* first = new Element(nullptr, 5);

    //Skapa pekare som pekar på det första elementet
    (first -> next) = first;
    //[first] -> [10 | *this]

    //----UPG 2------------
    //Uppdaterar element med värdet 10 och nullptr
    //[first] -> [10 | nullptr]
    (*first->next).next->value = 10;
    (*first->next).next->next = nullptr;
    
    // Det övre kan skrivas om som detta 
    first -> value = 10;
    first -> next = nullptr;

    return 0;
}