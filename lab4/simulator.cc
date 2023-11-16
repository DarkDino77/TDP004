#include <vector>
#include <iostream>
#include <iomanip>

#include "Circut.h"

void print_labes(std::vector<Component*>& net)
{
    for(Component* component: net)
    {
       std::cout << std::right << std::setw(12) << component -> get_name();    
    }

    std::cout << std::endl;

    for(int i = 0; i < static_cast<int>(net.size()); i++)
    {
        std::cout << " " << std::right << std::setw(5) << "Volt" 
                  << " " << std::right << std::setw(5) << "Curr";    
    }
    std::cout << std::endl;
}

void simulate(std::vector<Component*>& net, 
         int num_iterations, 
         int num_prints, 
         long double delta_time)
{
    print_labes(net);
    for(int i = 0; i <= num_iterations; i++)
    {
        std::string output;
        for(Component* component: net)
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

void clear_net(std::vector<Component*> &net)
{
    for(Component* component: net)
    {
        delete component;
    }
}

int main(int, char* argv[])
{
    int num_iterations {std::stoi(argv[1])};
    int num_prints {std::stoi(argv[2])};
    double delta_time{std::stod(argv[3])};
    double bat_volt {std::stod(argv[4])};

    Wire* w1 = new Wire;
    Wire* w2 = new Wire;
    Wire* w3 = new Wire;
    Wire* w4 = new Wire;
    
    std::vector<Component*> net;
    net.push_back(new Battery("Bat", bat_volt, w1, w4));
    net.push_back(new Resistor("R1", 6.0, w2, w1));
    net.push_back(new Resistor("R2", 4.0, w3, w2));
    net.push_back(new Resistor("R3", 8.0, w4, w3));
    net.push_back(new Resistor("R4", 12.0, w4, w2));
    simulate(net, num_iterations, num_prints, delta_time);

    Wire* p1 = new Wire;
    Wire* p2 = new Wire;
    Wire* p3 = new Wire;
    Wire* p4 = new Wire;
    
    std::vector<Component*> netp;
    netp.push_back(new Battery("Bat", bat_volt, p1, p4));
    netp.push_back(new Resistor("R1", 150.0, p2, p1));
    netp.push_back(new Resistor("R2", 50, p3, p1));
    netp.push_back(new Resistor("R3", 100, p3, p2));
    netp.push_back(new Resistor("R4", 300, p4, p2));
    netp.push_back(new Resistor("R5", 250, p4, p3));

    simulate(netp, num_iterations, num_prints, delta_time);

    Wire* c1 = new Wire;
    Wire* c2 = new Wire;
    Wire* c3 = new Wire;
    Wire* c4 = new Wire;
    
    std::vector<Component*> netc;
    netc.push_back(new Battery("Bat", bat_volt, c1, c4));
    netc.push_back(new Resistor("R1", 150.0, c2, c1));
    netc.push_back(new Resistor("R2", 50, c3, c1));
    netc.push_back(new Capacitor("C3", 1, c3, c2));
    netc.push_back(new Resistor("R4", 300, c4, c2));
    netc.push_back(new Capacitor("C5", 0.75, c4, c3));

    simulate(netc, num_iterations, num_prints, delta_time);

    delete w1;
    delete w2;
    delete w3;
    delete w4;

    clear_net(net);

    delete p1;
    delete p2;
    delete p3;
    delete p4;


    clear_net(netp);

    delete c1;
    delete c2;
    delete c3;
    delete c4;


    clear_net(netc);

    return 0;
}
