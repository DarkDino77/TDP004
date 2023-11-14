#include <vector>

// Basklass:
class Component
{
public:
    Wire* n;
    Wire* p;
    int get_curr();
    int get_volt();
    void update();
};

class Battery: public Component
{
public:
    Battery(int volt, Wire & volt_p, Wire & volt_n)
    : volt{volt}, volt_p{volt_p} 
    {}
private:
    int volt;
    Wire volt_p;
    Wire volt_n;

};

class Resistor: public Component
{
private:
    int resistance;
};

class Capacitor: public Component
{

};

struct Wire
{
    int volt;
};

/*
      [W1]
     / |  \
[Bat] [R1] [R3]
   |   |    |
   |  [W3]  |
    \  |   /
      [R2]


*/

int main()
{
    Wire w1, w2, w3;
    std::vector<Component*> c{};
    c.push_back(new Battery(24, w1, w2));

    for(Component* comp: c)
    {
        comp -> update();
    }


    return 0;
}

