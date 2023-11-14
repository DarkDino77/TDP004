#include <string>
#include <vector>
#include <iosteam>

#include "Circut.h"

//Wire
Wire::Wire():voltage(0){}

double Wire::get_voltage() const
{
    return voltage
}

void Wire::set_voltage(double voltage)
{
    voltage = voltage;
}
// Component
Component::Component(std::string name, Wire* positive, Wire* negative)
: name{name}, positive{positive}, negative{negative}
{}
virtual Component::~Component();

virtual void Component::update() = 0;

//Battery
Battery::Battery(std::string name, double volt, Wire* positive, Wire* negative)
: Component(name, positive, negative), volt{volt}
{}

//Resistor
Resistor::Resistor(std::string name, double resistance, Wire* positive, Wire* negative)
: Component(name, positive, negative), resistance{resistance}
{}

//Capacitor
Capacitor::Capacitor(std::string name, double capacitance, Wire* positive, Wire* negative)
: Component(name, positive, negative), capacitance{capacitance}, charge{0}
{}
