#include <iostream> // <--
#include <vector> // <--

using namespace std; // <--

class Binary_Operator
{
public:
    virtual double evaluate(double a, double b) const = 0; // <-- pure virtual
};

class Multiply : public Binary_Operator
{
public:
    double evaluate(double a, double b) const override 
    { 
        return a * b; 
    }  
};

class Add : public Binary_Operator
{
public:
    double evaluate(double a, double b) const override 
    { 
        return a + b; 
    }  
};

int main()
{
    // Vektorn måste bestå av pekare till nya instanser av objekten på heap:en.
    // vector<Binary_Operator> v{ Multiply{}, Add{} };
    vector <Binary_Operator*> v{ new Multiply{}, new Add{}};

    for ( int i{0}; i < v.size(); ++i )
    {
        // cout << v[i].evaluate(5.0, 3.0) << endl;
        cout << v[i] -> evaluate(5.0, 3.0) << endl;
    }
    return 0;
}