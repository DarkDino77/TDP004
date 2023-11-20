#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

float tax_amount(float value, float tax)
{
    tax = tax / 100;
    return value * tax;
}

float tax_sum(float value, float tax)
{
    return value + tax_amount(value, tax);
}

bool check_atleast(float min_value, float value, string message)
{
    if(value < min_value)
    {
        cerr << "FEL: " << message << endl;
        return false;
    }
    return true;
}

bool check_inbetween(float min_value, float max_value, float value, string message)
{
    if(value < min_value || value > max_value)
    {
        cerr << "FEL: " << message << endl;
        return false;
    }
    return true;
}

int main()
{
    cout << "INMATNINGSDEL\n" << setfill('=') << setw(12) << "" << endl;
    bool check{};

    float first_price{};
    do {
        cout << "Mata in första pris: ";
        cin >> first_price;
        check = check_atleast(0, first_price, "Första pris måste vara minst 0 (noll) kronor");
    }
    while(check == false);

    float last_price{};
    do
    {
        cout << "Mata in sista pris: ";
        cin >> last_price;
        check = check_atleast(first_price, last_price, "Sista pris måste vara större än första pris");
    }
    while(check == false);
    
    float increment{};
    do
    {
        cout << "Mata in steglängd: ";
        cin >> increment;
        check = check_inbetween(0.01f, last_price - first_price, increment, "Steglängd måste vara minst 0.01 och som mest sista pris - första pris");
    }
    while(check == false);

    float tax{};
    do
    {
        cout << "Mata in momsprocent: ";
        cin >> tax;
        check = check_inbetween(0, 100,tax, "Momsprocent måste vara mellan 0 till 100%");
    }
    while(check == false);

    cout << "\nMOMSTABELLEN\n" 
         << setfill('=') << setw(12) << "" << "\n" << setfill(' ')
         << right << setw(12) << "Pris"
         << right << setw(17) << "Moms"
         << right << setw(20) << "Pris med moms" << "\n"
         << setfill('-') << setw(49) << ""
         << setfill (' ') << endl;

    float steps{(last_price - first_price)/increment};
    for(int i{0}; i <= steps; i++)
    {
        float value{ (i*increment) + first_price };
        cout << right << fixed << setprecision(2) << setw(12) << value
             << right << fixed << setprecision(2) << setw(17) << tax_amount(value, tax)
             << right << fixed << setprecision(2) << setw(20) << tax_sum(value, tax)
             << endl;
    }

    return 0;
}