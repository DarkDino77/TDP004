// De speciella medlemsfunktionerna.
// -Destructor

class List
{
public:
    // --- Speciella medlemsfunktioner ---
    // Dessa behövs när en klass innehåller en pekare till ett objekt utanför klassen.

    // Konstruktor.
    List();

    // Destruktor.
    ~List()
    {
        // Frigör alla noder.
        // Kallas även för automatiskt minneshanterade listor.
    };

    // Kopierings konstruktor.
    List(List const& other)
    {

    };

    // Kopieringstilldelsningsoperator.
    List& operator=(List const& l)
    {
        // Behöver ta bort sitt gamla innehåll innan kopiering. Deep copy
    };

    // Flyttkonstruktor.
    List(List && other)
    {
        // Ta bort gammalt innehåll -> Flytta pekaren.
    }

    // Flytttilldelningsoperatorn.
    List& operator=(List && other)
    {

    }


    // --- Övriga funktioner ---
    void insert(int ins)
    {}
};

void fun(List l) // Kopiering gör en "shallow" kopia som standard.
{
    l.insert(5);
}

int main()
{
    List list1;
    fun(list1);
    return 0;

    List list2;
    list2 = list1;



} // Här tas alla noder bort i orginal listan då kopian går ut scope.

// Rekursion
int main2()
{
    /*
    
    [ ]->[1][ ]->[3][ ]->[4][\]

    Iterativt: current och to_current kopia

    Rekursivt: to = from -> copy();
                    node* copy()
                    {
                        if (next != nullptr)
                        {
                            Node* tmp{new Node{value, next -> copy()}}
                            return tmp;
                        }
                        else
                        {
                            tmp{new Node{value,nullptr}};
                            return tmp;
                        }
                      
    }
    */
}
