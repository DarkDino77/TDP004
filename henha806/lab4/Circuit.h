#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <string>

// ==============================[ Wire ]==============================
class Wire
{
public:
    Wire();
    double volt;
};

// ==============================[ Component ]==============================
class Component
{
public:
    Component(std::string name, Wire* positive, Wire* negative);
    virtual ~Component() = default;

    virtual void update(double const delta_time) = 0;
    virtual double get_current() const = 0;

    virtual double get_voltage() const;
    std::string to_string() const;
    std::string get_name() const;
    void adjust_polarity();

protected:
    std::string name;
    Wire* positive;
    Wire* negative;
};

// ==============================[ Battery ]==============================
class Battery: public Component
{
public:
    Battery(std::string name, double volt, Wire* positive, Wire* negative);
    ~Battery() = default;

    void update(double) override;
    double get_current() const override;
    double get_voltage() const override;

private:
    double volt;
};

// ==============================[ Resistor ]==============================
class Resistor: public Component
{
public:
    Resistor(std::string name, double resistance, Wire* positive, Wire* negative);
    ~Resistor() = default;

    void update(double delta_time) override;
    double get_current() const override;

private:
    double resistance;
};

// ==============================[ Capacitor ]==============================
class Capacitor: public Component
{
public:
    Capacitor(std::string name, double capacitance, Wire* positive, Wire* negative);
    ~Capacitor() = default;

    void update(double delta_time) override;
    double get_current() const override;

private:
    double capacitance;
    double charge;
};

#endif