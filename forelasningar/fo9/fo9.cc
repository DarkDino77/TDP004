#include <iostream>

// ==============================[ Typkonvertering ]==============================
class Cls
{
public:
    explicit Cls(int j) // Explicit gör att det inte går att skriva 'Cls c1{10};' då den inte längre gör en implicit typkonvertering.
    : i{j}
    {}

    Cls(std::string s)
    : i{stoi(s)}
    {}

    void add(Cls const& other)
    {
        i+=other.i;
    }

    // Operator type() const;
    Operator bool() const; 
    /*
        • De måste vara medlemsfunktioner.
        • De får inte specifiera en returtyp.
        • De måste ha en tom parameterlista.
        • De är i de flesta fall const.
    */

    explicit Operator bool()
    {
        return i!=0;
    }
    

    int i;
}

int main()
{
    Cls c1{10};
    Cls c2{"10"}; // Gör en implicit typkonvertering.

    c1.add(10); // Gör en implicit typkonvertering.
    c1.add("10"); // Går ej då man inte får göra två implicita typkonverteringar i rad.

    c1.add(Cls{"10"}); // En lösning
    c1.add({"10"}); // En annan lösning

    if(c1)
    {
        std::cout << "Yay!" << std::endl;
    }

    return 0;
}

// ==============================[ Const Cast ]==============================
int main()
{
    int const x{5};

    const_cast<int&>(x) = 3; // Undefined behaviour. Använd inte.
    std::cout << x << std::endl;
    return 0;
}

// ==============================[ Dynamic Cast ]==============================
int main()
{
    char c{'i'};
    int i{static_cast<int> (c)};
    double d{};
    d = static_cast<double> (c);
    cout << "c: " << c << '\n'
         << "i: " << i << '\n'
         << "d: " << d << endl;
}

int main()
{
    Time t{3665};
    string s{static_cast<string> (t)};
    cout << s << endl;
    // Hur är denna konvertering känd?
}

// ==============================[ C Style Cast ]==============================
int main()
{
    char c{'i'}; //105e ascii
    int i = c; //implicit
    double d = (double) c; //explicit
    cout << "c: " << c << '\n'
         << "i: " << i << '\n'
         << "d: " << d << endl;
}

// ==============================[ Maxa optimering ]==============================

// $ g++ -o3 fil.cc
