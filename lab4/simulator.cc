#include <vector>
#include <iostream>
#include <iomanip>

#include "Circut.h"

void print_labes(std::vector<Component*>& circuit)
{
    for(Component* component: circuit)
    {
       std::cout << std::right << std::setw(12) << component -> get_name();    
    }

    std::cout << std::endl;

    for(int i = 0; i < static_cast<int>(circuit.size()); i++) // ska static vara utanför for loopen
    {
        std::cout << " " << std::right << std::setw(5) << "Volt" 
                  << " " << std::right << std::setw(5) << "Curr";    
    }
    std::cout << std::endl;
}

void simulate(std::vector<Component*>& circuit, 
         int num_iterations, 
         int num_prints, 
         long double delta_time)
{
    print_labes(circuit);
    for(int i = 0; i <= num_iterations; i++)
    {
        std::string output;
        for(Component* component: circuit)
        {
            component -> update(delta_time);
            if((i % (num_iterations/num_prints) == 0) and i != 0)
            {
                output += component -> to_string();
            }
        }

        if((i % (num_iterations/num_prints) == 0) and i != 0)
        {
            std::cout << output << std::endl;
        }
    }
    
    std::cout << std::endl;
}

void clear_circuit(std::vector<Component*> &circuit)
{
    for(Component* component: circuit)
    {
        delete component;
    }
}

int main(int, char* argv[])
{
    // Read varible sent to program
    int num_iterations {std::stoi(argv[1])};
    int num_prints {std::stoi(argv[2])};
    double delta_time{std::stod(argv[3])};
    double bat_volt {std::stod(argv[4])};

    // First circuit
    Wire* first_wire {new Wire};
    Wire* second_wire {new Wire};
    Wire* third_wire {new Wire};
    Wire* fourth_wire {new Wire};
    
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

    // Second circuit 
    first_wire = new Wire;
    second_wire = new Wire;
    third_wire = new Wire;
    fourth_wire = new Wire;
    
    std::vector<Component*> second_circuit;
    second_circuit.push_back(new Battery("Bat", bat_volt, first_wire, fourth_wire));
    second_circuit.push_back(new Resistor("R1", 150.0, second_wire, first_wire));
    second_circuit.push_back(new Resistor("R2", 50, third_wire, first_wire));
    second_circuit.push_back(new Resistor("R3", 100, third_wire, second_wire));
    second_circuit.push_back(new Resistor("R4", 300, fourth_wire, second_wire));
    second_circuit.push_back(new Resistor("R5", 250, fourth_wire, third_wire));

    simulate(second_circuit, num_iterations, num_prints, delta_time);

    delete first_wire;
    delete second_wire;
    delete third_wire;
    delete fourth_wire;

    clear_circuit(second_circuit);

    //Third circuit
    first_wire = new Wire;
    second_wire = new Wire;
    third_wire = new Wire;
    fourth_wire = new Wire;
    
    std::vector<Component*> third_circuit;
    third_circuit.push_back(new Battery("Bat", bat_volt, first_wire, fourth_wire));
    third_circuit.push_back(new Resistor("R1", 150.0, second_wire, first_wire));
    third_circuit.push_back(new Resistor("R2", 50, third_wire, first_wire));
    third_circuit.push_back(new Capacitor("C3", 1, third_wire, second_wire));
    third_circuit.push_back(new Resistor("R4", 300, fourth_wire, second_wire));
    third_circuit.push_back(new Capacitor("C5", 0.75, fourth_wire, third_wire));

    simulate(third_circuit, num_iterations, num_prints, delta_time);

    delete first_wire;
    delete second_wire;
    delete third_wire;
    delete fourth_wire;

    clear_circuit(third_circuit);

    return 0;
}
