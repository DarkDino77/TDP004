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

    return 0;
}