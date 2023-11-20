#include <vector>
#include <iostream>
#include <system_error>
#include <iomanip>
#include "Circuit.h"

void print_labels(std::vector<Component*>const& circuit)
{
    for(Component* component: circuit)
    {
        std::cout << std::right << std::setw(12) << (component -> get_name());
    }

    std::cout << std::endl;
    int const circuit_size{static_cast<int>(circuit.size())};

    for(int i = 0; i < circuit_size; i++)
    {
        std::cout << " " << std::right << std::setw(5) << "Volt"
                  << " " << std::right << std::setw(5) << "Curr";
    }
    std::cout << std::endl;
}

void simulate(std::vector<Component*>const& circuit, 
         int const num_iterations, 
         int const num_prints, 
         double const delta_time)
{
    print_labels(circuit);
    for(int i = 0; i <= num_iterations; i++)
    {
        std::string output;

        if(i != 0 && i% (num_iterations/num_prints) == 0)
        {
            for(Component* component: circuit)
            {
                output += component -> to_string();
            }
            std::cout << output <<  std::endl;
        }
        for(Component* component: circuit)
        {
            component -> update(delta_time);
        }
    }
    std::cout << std::endl;
}

void clear_circuit(std::vector<Component*>& circuit)
{
    for(Component* component: circuit)
    {
        delete component;
    }
}

int main(int argc, char* argv[])
{
    if(argc != 5)
    {
        std::cerr << "Error: Invalid amount of arguments, you entered " << argc << " arguments. 5 arguments is expected." << std::endl;
        return 1;
        // Throw?
    }

    int num_iterations;
    try
    {
        num_iterations = std::stoi(argv[1]);
    }
    catch(std::exception const& e)
    {
        std::cerr << "Error: Argument 2 needs to be of type int" << std::endl;
        return 2;
    }
    // static_cast<int const>(num_iterations); ??

    int num_prints;
    try
    {
        num_prints = std::stoi(argv[2]);
    }
    catch(std::exception const& e)
    {
        std::cerr << "Error: Argument 3 needs to be of type int" << std::endl;
        return 3;
    }

    double delta_time;
    try
    {
        delta_time = std::stoi(argv[3]);
    }
    catch(std::exception const& e)
    {
        std::cerr << "Error: Argument 4 needs to be of type double" << std::endl;
        return 4;
    }

    double bat_volt;
    try
    {
        bat_volt = std::stoi(argv[4]);
    }
    catch(std::exception const& e)
    {
        std::cerr << "Error: Argument 5 needs to be of type double" << std::endl;
        return 5;
    }

    // ==============================[ First Circuit ]==============================
    Wire* first_wire{new Wire};
    Wire* second_wire{new Wire};
    Wire* third_wire{new Wire};
    Wire* fourth_wire{new Wire};
    std::vector<Component*> first_circuit;

    first_circuit.push_back(new Battery("Bat", bat_volt, first_wire, fourth_wire));
    first_circuit.push_back(new Resistor("R1", 6.0, second_wire, first_wire));
    first_circuit.push_back(new Resistor("R2", 4.0, third_wire, second_wire));
    first_circuit.push_back(new Resistor("R3", 8.0, fourth_wire, third_wire));
    first_circuit.push_back(new Resistor("R4", 12.0, fourth_wire, second_wire));

    simulate(first_circuit, num_iterations, num_prints, delta_time);

    delete first_wire;
    delete second_wire;
    delete third_wire;
    delete fourth_wire;

    clear_circuit(first_circuit);

    // ==============================[ Second Circuit ]==============================
    first_wire = new Wire;
    second_wire = new Wire;
    third_wire = new Wire;
    fourth_wire = new Wire;
    std::vector<Component*> second_circuit;

    second_circuit.push_back(new Battery("Bat", bat_volt, first_wire, fourth_wire));
    second_circuit.push_back(new Resistor("R1", 150.0, second_wire, first_wire));
    second_circuit.push_back(new Resistor("R2", 50.0, third_wire, first_wire));
    second_circuit.push_back(new Resistor("R3", 100.0, second_wire, third_wire));
    second_circuit.push_back(new Resistor("R4", 300.0, fourth_wire, second_wire));
    second_circuit.push_back(new Resistor("R5", 250.0, fourth_wire, third_wire));

    simulate(second_circuit, num_iterations, num_prints, delta_time);

    delete first_wire;
    delete second_wire;
    delete third_wire;
    delete fourth_wire;

    clear_circuit(second_circuit);

    // ==============================[ Third Circuit ]==============================

    first_wire = new Wire;
    second_wire = new Wire;
    third_wire = new Wire;
    fourth_wire = new Wire;
    std::vector<Component*> third_circuit;

    third_circuit.push_back(new Battery("Bat", bat_volt, first_wire, fourth_wire));
    third_circuit.push_back(new Resistor("R1", 150.0, second_wire, first_wire));
    third_circuit.push_back(new Resistor("R2", 50.0, third_wire, first_wire));
    third_circuit.push_back(new Capacitor("C3", 1.0, second_wire, third_wire));
    third_circuit.push_back(new Resistor("R4", 300.0, fourth_wire, second_wire));
    third_circuit.push_back(new Capacitor("C5", 0.75, fourth_wire, third_wire));

    simulate(third_circuit, num_iterations, num_prints, delta_time);

    delete first_wire;
    delete second_wire;
    delete third_wire;
    delete fourth_wire;

    clear_circuit(third_circuit);

    return 0;
}