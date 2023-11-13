#include <iostream>

class Vehicle
{
public:
    int num_wheels;
    int top_speed;

    void drive()
    {
        std::cout << "Vrooom! (from A to B)" << std::endl;
    }
};

class Passenger_Vehicle : public Vehicle
{
public:
    int num_seats;

    void exit_vehicle()
    {
        std::cout << "Exited vehicle" << std::endl;
    }
};

class Freight_Vehicle : public Vehicle
{
public:
    int max_load;

    void load()
    {
        std::cout << "Loaded truck" << std::endl;
    }

    void unload()
    {
        std::cout << "Unloaded truck" << std::endl;
    }
};

int main()
{
    Passenger_Vehicle car;
    Freight_Vehicle truck;

    car.drive();
    car.exit_vehicle();

    truck.drive();
    truck.load();
    truck.unload();

    return 0;
}