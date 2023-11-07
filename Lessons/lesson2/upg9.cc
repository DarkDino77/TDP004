/*
När satsen "delete first" körs på strukturen i uppgift 4, 
kommer det att ske en rekursiv borttagning av alla element i den länkade listan. 
Här är stegen som beskriver vad som händer:

Antag att ursprunglig länkad lista är:


[first] --> [5] --> [8] --> [9] --> [nullptr]


1. "delete first" kommer först att anropa destruktorn för det första elementet (det som "first" pekar på), 
vilket är elementet med värdet 3.

2. Inuti destruktorn kommer delete next att anropa destruktorn för nästa element, vilket är elementet med värdet 5.

3. Samma process upprepas för nästa element, vilket är elementet med värdet 8. Den destruktorn anropar också delete next, 
men eftersom det inte finns något element efter det, kommer det inte att hända något mer.

4. När destruktorerna har kallats för alla element i listan, 
kommer minnet som allokerades för varje element att frigöras, 
och hela listan kommer att rensas.

Efter att "delete first" har körts, 
kommer hela den länkade listan att ha blivit borttagen, 
och minnet som allokerades för elementen kommer att ha frigjorts. 
Listan kommer att vara tom och "first" kommer att vara en ogiltig pekare (dvs. peka någonstans slumpmässigt).
*/

class Element {
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

    delete first;
    
    /*
                 [First] -> [5| ] -> [8| ] -> [9|\]
    Delete order:             3        2        1
    
    Note: First pointer is never deleted.
    */
    
    return 0;
}