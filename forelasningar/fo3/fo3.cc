#include <iostream>
#include <string>
#include "fo3_hello.h"

using namespace std;

class Person
{
    public:
        Person(string const&fn)
        :   first_name{fn}
        { /*Felkontroll*/ }

        string get_first_name()
        {
            return first_name;
        }

        void set_first_name(string const& first_name)
        {
            //first_name = fn;
            this->first_name = first_name;
        }

        void print() const // Om du ska kunna kalla på en funktion hos en konst Const av Person måste funktionen ha "Const"
        {
            cout << "First name: " << first_name << endl;
        }
        
    private:
        string first_name;

};

int main(){
    /*

    Variable name | Adress       Adress | Value
    -------------------------------------------
    first_name    | 0x0...01     0x0..01| "Pontus"
    surname       | 0x0...02     0x0..02| "Haglund"
                                 0x0..03| "Pontus"
                                 0x0..04| "Haglund"

    ---[Ingen referens]---
    Variable name | Adress       Adress | Value
    -------------------------------------------
    fn            | 0x0...03     0x0..01| "Pontus"
    sn            | 0x0...04     0x0..02| "Haglund"
                                 0x0..03| "Pontus"
                                 0x0..04| "Haglund"

    ---[En referens]---
    Variable name | Adress       Adress | Value
    -------------------------------------------
    fn            | 0x0...01     0x0..01| "Pontus"
    sn            | 0x0...04     0x0..02| "Haglund"
                                 0x0..04| "Haglund"

    ---[Båda referens]---
    Variable name | Adress       Adress | Value
    -------------------------------------------
    fn            | 0x0...01     0x0..01| "Pontus"
    sn            | 0x0...02     0x0..02| "Haglund"

    Alla icke- primitiva typer (De som importeras och som är samansatta typer) bör överföras som referenser / const referenser
    Alla primitiva bör skickas som kopior

    */

    Person p{"Henke"};
    Person const p2{"Nisse"};
    //p.set_first_name("Henke");
    p.print();
    p2.print();

    hello();
    
    return 0;
}