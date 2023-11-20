#include <iostream>

class Vehicle
{
public:
    int num_wheels;
    int top_speed;

    Vehicle(int num_wheels, int top_speed) 
    : num_wheels(num_wheels), top_speed(top_speed)
    {
        limit_top_speed();
    }

    void drive()
    {
        std::cout << "Vrooom! (from A to B) going " << top_speed << "km/h" << std::endl;
    }

private:
    void limit_top_speed()
    {
        if(num_wheels > 6 && top_speed > 100)
        {
            top_speed = 100;
        }
    }
};

class Passenger_Vehicle : public Vehicle
{
public:
    int num_seats;

    Passenger_Vehicle(int num_wheels, int top_speed, int num_seats) 
    : Vehicle(num_wheels, top_speed), num_seats(num_seats)
    {}

    void exit_vehicle()
    {
        std::cout << "Exited vehicle" << std::endl;
    }
};

class Freight_Vehicle : public Vehicle
{
public:
    int max_load;

    Freight_Vehicle(int num_wheels, int top_speed, int max_load) 
    : Vehicle(num_wheels, top_speed), max_load(max_load)
    {}

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
    Passenger_Vehicle car(4, 240, 5);
    Freight_Vehicle truck(8, 130, 5000);

    car.drive();
    car.exit_vehicle();

    truck.drive();
    truck.load();
    truck.unload();

    return 0;
}