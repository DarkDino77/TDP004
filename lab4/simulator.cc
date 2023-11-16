#include <string>
#include <vector>
#include <iosteam>

#include "Circut.h"

simulate(std::vector<Componen*> net, int num_iteration)
{

}
int main(int argc, char* argv[])
{
    Connection p, n;
    std::vector<Component*> net;
    net.push_back(new Battery("Bat", 24.0, p, n));
    net.push_back(new Resistor("R1", 6.0, p, n));
    net.push_back(new Resistor("R2", 8.0, p, n));
    simulate(net, 10000, 10, 0.1);
    return 0;
}
