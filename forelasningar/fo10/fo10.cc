// ==============================[ Kompilatorns steg ]==============================

// 1. Preprocessing, hanterar alla #
// 2. Kompilering
// 3. Länkning 

/*
   fil.h 
   ^   ^  
   |    \        preprocessor (g++)
fil.cc  main.cc
   ^     ^
   |     |       Kompilering (g++)
fil.o   main.o
   ^     ^
    \   /        Länkning (ld) Vet inte hur man genererar mallafunktioner
    a.out
*/

int main()
{
    max(5,6);
    max(5.0, 6.0);
    max("hej", "då")
}

// Lösning - Funktionsmall, används för att generera funktioner med T
template <typename T>
T max(T a, T b)
{
    if( a < b )
    {
    return b;
    }
    else
    {
    return a;
    }
}

// Olika sätt att anropa mallen.
int main()
{
    int i{2};
    int j{3};
    max(i, j); // Autmatisk deducering, listar själv ut vilken datatyp som T bör vara. Implicit instanciering
    max<int>(i, j); // Explicit instanciering - Vi säger vad datatypen ska vara.
}

// Klassmallar 
int main()
{
    Stack my_int_stack{1, 2, 3};
    Stack my_float_stack{1.0, 2.0, 3.0};
}

template <typename T>
class Stack
{
    public:
    //...
    private:
    struct Node
    {
    Node* next;
    T data;
    };
    //...
};

/*
   fil.h 
   |   ^  
   v    \        preprocessor (g++)
fil.tcc main.cc
         ^
         |       Kompilering (g++)
        main.o
         ^
        /        Länkning (ld) Vet inte hur man genererar mallafunktioner
    a.out
*/

// ==============================[ tcc filer ]==============================
//h-fil
template <typename T>
class Stack
{
    Stack();
    void push(T data);
    T pop();
    //...
};
#include "Stack.tcc"

//tcc-fil
template <typename T>
void Stack<T>::push(T data)
{
    //...
}
template <typename T>
T Stack<T>::pop()
{
    //...
}

// ==============================[ Fler mallparametrar ]==============================
template <typename Value_type, typename Key_type = int> // Default blir int. Default ska bara finnas i h-filen.
class Stack
{
public:
    //...
private:
    //...
    class Node
    {
        Node(Node* n, Key_type k, Value_type v);
        Node* next;
        Key_type key;
        Value_type value;
    };
};

// ==============================[ Deducera typer ]==============================
// Ett sätt att beräkna typen av ett objekt.
template<typename T>
typename T::value_type first(T const& container) // typename säger att T::value_type ska tolkas som en datatyp, inte en variabel.
{
    return *begin(container); //iterator. 
}

int main()
{
    vector<int> vi{1, 2, 3};
    vector<string> vs{"hej", "svej"};
    int i{first(vi)};
    int s{first(vs)};


    vector<int> v{1,2,3}
    first(v); // T = vector<int>

    return 0;
}

using positive_int = unsigned; // Sätter mer specifika namn på datatyper.
using id_type = int; // Går att ändra till double om det skulle behövas i framtiden.

get_data(id_type id)

// ==============================[ Smartpekare ]==============================
int main()
{
    unique_ptr<int> my_uptr{ new int{5} }; // När pekaren går sönder går även objektet sönder.
}

class list
{
    // ~List(){delete first;};

    // Node* first;
    struct Node
    {
        unique_ptr<Node> next;
        int value;
    }
    unique_ptr<Node> first;

    // First = nullptr; 
    // other_ptr = first.get(), men får inte ta bort objektet.
};

// Ritas som: [ | ]+>[ | ]+>[ | ]

// En stor begränsning är att unique_ptr inte får kopieras. Men man får flytta dem!

void print(unique_ptr<int> up)
{
    cout << *up << endl;
}

int main()
{
    unique_ptr<int> uptr{ new int{5} };
    print( move(uptr) );
}

// ==============================[ Delad pekare ]==============================
int main()
{
    shared_ptr<int> my_sptr1{ new int{5} };
    {
        shared_ptr<int> my_sptr2{ my_sptr1 };
    }
}

// s>[ | ]<s Bra för att flera objekt i ett spel pekar på samma sprite.
// Går att kopiera. När den sista shared_ptr faller ur scope så försvinner objektet som pekarna pekade på.

//      v----    v----
// [\| | ]s>[ | | ]s>[ | | ]

// ==============================[ Funktioner som parametrar ]==============================
template<typename T, typename F>
bool compare(T a, T b, F fun)
{
    return fun(a, b);
}

bool less(a, b)
{
    return a < b;
}

int main()
{
    int a{1};
    int b{3};
    compare(a, b, less);
}
