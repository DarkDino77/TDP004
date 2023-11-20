#include <iostream>


class Race
{
public:
    virtual void eat()
    {
        std::cout << "Nom" << std::endl;
    }
};

// Trait classes
class Sun_Insensitive
{
public:
    void ignore_sun()
    {
        std::cout << "Sun go boom" << std::endl;
    }
};

class Strong
{
public:
    void be_strong()
    {
        std::cout << "No weak" << std::endl;
    }
};

class Intelligent
{
public:
    void be_intelligent()
    {
        std::cout << "Me smart" << std::endl;
    }
};

class Repulsive
{
public:
    void be_repulsive()
    {
        std::cout << "Me lonely" << std::endl;
    }
};

// Race classes
class Human : public Race, public Sun_Insensitive, public Intelligent
{};

class Orc: public Race, public Strong, public Repulsive
{};

class Uruk_Hai: public Race, public Sun_Insensitive, public Strong, public Repulsive
{};

int eat_dinner(Race* dinner_guest)
{
    if(dynamic_cast<Repulsive*>(dinner_guest) != nullptr)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


