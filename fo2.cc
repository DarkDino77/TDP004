#include <iostream>

using namespace std;
int main(){

    while(true) // Oändlig loop
    {
        if(5 == 5)
        {
            continue; // Skippar break;
        }
        break;
    }


    int i{5};
    cout << ++i; // "6" i = 6
    cout << i++; // "6" i = 7


    while(true) 
    {
        // ...
        if (5 == 5)
        {
            break;
        }
        // ...
    }


    { // Början av ett block

      // Blockets kropp

    } // Slutet av blocket


    int x{0};
    {
        int x{1};
        {
            cout << x << endl; // "1"
        }
    }
    cout << x << endl; // "0"


    cerr << "Something went wrong" << endl;


    float f{0.01f};
    float & dumma_tal{f}; // Referens till f

    return 0;
}

void hello(string & name) // & tecken innbär att variabeln är en referens till den som skickas in.
{
    name = "New name";
    cout << "Hello " << name << endl;
}

void hello(string const& name) // const& innebär att man inte kan ändra variabeln som refereras till. Bra om man ska hantera stor mängd data.
{
    cout << "Hello " << name << endl;
}