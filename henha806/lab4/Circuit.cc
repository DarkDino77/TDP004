#include <string>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <sstream>
#include "Circuit.h"

// ==============================[ Wire ]==============================
Wire::Wire()
: volt{0.0}
{}

// ==============================[ Component ]==============================
Component::Component(std::string name, Wire* positive, Wire* negative)
:   name{name}, positive{positive}, negative{negative}
{}

double Component::get_voltage() const
{
    return std::abs((positive -> volt)-(negative -> volt)); 
}

std::string Component::to_string() const
{
    std::ostringstream temp_volt, temp_curr;
    temp_volt << " " << std::fixed 
              << std::setprecision(2) << std::right 
              << std::setw(5) << get_voltage();
    temp_curr << " " << std::fixed 
              << std::setprecision(2) << std::right 
              << std::setw(5) << get_current();

    return temp_volt.str() + temp_curr.str();
}

std::string Component::get_name() const
{
    return name;
}

// Make sure the wire connected to the negative pole is always the wire with the most voltage.
void Component::adjust_polarity()
{
    if((positive -> volt) > (negative -> volt))
    {
        Wire* temp_pointer = positive;
        positive = negative;
        negative = temp_pointer;
    }
}

// ==============================[ Battery ]==============================
Battery::Battery(std::string name, double volt, Wire* positive, Wire* negative)
:  Component(name, positive, negative), volt{volt} 
{}

void Battery::update(double const)
{
    (positive -> volt) = volt;
    (negative -> volt) = 0;
}

double Battery::get_current() const
{
    return 0;
}

double Battery::get_voltage() const
{
    return volt;
}

// ==============================[ Resistor ]==============================
Resistor::Resistor(std::string name, double resistance, Wire* positive, Wire* negative)
:  Component(name, positive, negative), resistance{resistance} 
{}

void Resistor::update(double const delta_time)
{
    adjust_polarity();

    // Calculate and transfer the voltage.
    double transfer_voltage = ( get_current()*delta_time );
    (negative -> volt) -= transfer_voltage;
    (positive -> volt) += transfer_voltage;
}

double Resistor::get_current() const
{
    return get_voltage()/resistance;
}

// ==============================[ Capacitor ]==============================
Capacitor::Capacitor(std::string name, double capacitance, Wire* positive, Wire* negative)
:  Component(name, positive, negative), capacitance{capacitance}, charge{0.0}
{}

void Capacitor::update(double const delta_time)
{
    adjust_polarity();

    // Calculate and transfer the voltage and charge the capacitor with the same amount.
    double transfer_voltage{get_current() * delta_time};
    charge += transfer_voltage;
    (negative -> volt) -= transfer_voltage;
    (positive -> volt) += transfer_voltage;
}

double Capacitor::get_current() const
{
    return capacitance*(get_voltage()-charge);
}