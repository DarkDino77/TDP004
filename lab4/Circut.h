#ifndef CIRCUT_H
#define CIRCUT_H
class Wire
{
public:
    Wire();

    double get_voltage();
    void set_voltage(double voltage);

private:
    double voltage;
}

class Component
{
public:
    Component(std::string name, Wire* positive, Wire* negative);
    virtual ~Component();

    virtual void update() = 0;

private:
    std::string name;
    Wire* positive;
    Wire* negative;
};

class Battery: public Component
{
public:
    Battery(std::string name, double volt, Wire* positive, Wire* negative);

private:
    double volt;
};

class Resistor: public Component
{
public:
    Resistor(std::string name, double resistance, Wire* positive, Wire* negative);

private:
    double resistance
};

class Capacitor: public Component
{
public:
    Capacitor(std::string name, double capacitance, Wire* positive, Wire* negative);

private:
    double capacitance;
    double charge;
};
#endif