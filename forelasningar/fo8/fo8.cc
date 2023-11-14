#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
/*
int main(int argc, char* argv[])
{
    cout << "nr of arguments: " << argc << endl;
    cout << argv[0] << " : " << argv[1] << endl;
}
*/

/* Saknar felhantering
int main(int argc, char* argv[])
{
    cout << "nr of arguments: " << argc << endl;

    istringstream iss{argv[1]};
    double argument1{};
    iss >> argument1;
    cout << argument1 << endl;

    int argument2{ stoi(argv[2]) };
    cout << argument2 << endl;
}
*/

int main(int argc, char* argv[])
{
    cout << "nr of arguments: " << argc << endl;
    int argument1{};
    try
    {
        argument1 = stoi(argv[1]);
    }
    catch (invalid_argument const& ia_error)
    {
        cerr << "Error: " << ia_error.what() << endl;
        return 1;
    }
    cout << argument1 << endl;
    return 0;
}

class My_Error : std::logic_error
{
public:
    using logic_error::logic_error;

    //Överlagra lämpliga delar
    const char* what () const noexcept override {
        return "My_Error: ";
    }
};

class Character
{
public:
    virtual ~Character(){}; // <- Om vi har minst en virtuell funktion, ska en virtuell destruktor finnas. !VIKTIGT!
    virtual void update() = 0;
};

class Fighter: public Character
{
public:
    ~Fighter()
    {
        delete health;
    }
    void update() override;

private:
    int* health{};
};

void fun()
{
    // För TDP005
    vector<Character*> v{new Fighter{}};
    delete v.at(0); // Kallar på destruktor för Fighter
    // inte delete v[0]; Då detta kan vara out of bounds
}
