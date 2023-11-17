#include <string>
#include <vector>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <cmath>

#include "Circut.h"

//------------------------Wire----------------------------
Wire::Wire():volt(0){}

//--------------------- Component -----------------------
Component::Component(std::string name, Wire* positive, Wire* negative)
: name{name}, positive{positive}, negative{negative}
{}

double Component::get_voltage() const
{
    return std::abs((positive -> volt) - (negative -> volt));
}

std::string Component::to_string() const
{   
    std::ostringstream temp_volt, temp_curr;
    
    temp_volt << " " << std::fixed << std::setprecision(2) 
              << std::right << std::setw(5) << get_voltage();
    temp_curr << " " << std::fixed << std::setprecision(2) 
              << std::right << std::setw(5) << get_curret();

    return temp_volt.str()  +  temp_curr.str();
}

std::string Component::get_name() const
{
    return name;
}

void Component::change_voltage(Wire* const& positive, 
                               Wire* const& negative, 
                               double const transfer_voltage)
{
    Wire* more_volt;
    Wire* less_volt;
    
    if ((positive -> volt) > (negative -> volt))
    {
        more_volt = positive;
        less_volt = negative;
    }
    else
    {
        more_volt = negative;
        less_volt = positive;
    }
    
    (less_volt -> volt) += transfer_voltage;
    (more_volt -> volt) -= transfer_voltage;
}

//---------------------Battery------------------------------
Battery::Battery(std::string name, 
                 double volt, 
                 Wire* positive, 
                 Wire* negative)
: Component(name, positive, negative), volt{volt}
{}

void Battery::update(double const)
{
    (positive -> volt) = volt;
    (negative -> volt) = 0.0;
}

double Battery::get_curret() const
{
    return 0;
}

double Battery::get_voltage() const
{
    return volt;
}

//------------------------Resistor-------------------------------
Resistor::Resistor(std::string name, 
                   double resistance, 
                   Wire* positive, 
                   Wire* negative)
: Component(name, positive, negative), resistance{resistance}
{}

void Resistor::update(double const delta_time)
{
    double transfer_voltage{get_curret() * delta_time};

    change_voltage(positive, negative, transfer_voltage);
}

double Resistor::get_curret() const
{
    return get_voltage() / resistance;
}

//-------------------------Capacitor---------------------------------
Capacitor::Capacitor(std::string name, 
                     double capacitance, 
                     Wire* positive, 
                     Wire* negative)
: Component(name, positive, negative), capacitance{capacitance}, charge{0}
{}

void Capacitor::update(double const delta_time)
{
    double transfer_voltage{get_curret() * delta_time};

    charge += transfer_voltage;

    change_voltage(positive, negative, transfer_voltage);
}

double Capacitor::get_curret() const
{
    return capacitance * (get_voltage() - charge);
}