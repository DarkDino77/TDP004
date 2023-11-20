// 'Encapsulation' innebär att man buntar samman data och de funktioner som manipulerar dem.
// Detta är för att skydda datan från att manipuleras på ett oväntat sätt, men också gömma information som
// inte ska kunna kommas åt.

// Ett dåligt exempel på en enkapsulering är
class Car
{
public:
    double speed;

    Car() 
    : speed(0.0)
    {};

};

// Ett bättre exempel på detta hade kunnat sett ut på följande vis:
class Car
{
public:
    Car() 
    : speed(0.0)
    {};
    void change_speed(double speed);

private:
    double speed;
};