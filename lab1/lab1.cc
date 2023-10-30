#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

float tax_amount(float value, float tax)
{
    tax = tax / 100;
    return value * tax;
}

float total(float value, float tax)
{
    return value + tax_amount(value, tax);
}

bool check_less(float value, float check_value, string massage)
{
    if (value < check_value)
    {
        cout << massage << endl;
        return true;
    }
    return false;
}

int main()
{
    cout << "INMATNINGSDEL" << "\n" 
         << setfill('=') << setw(12) << "" 
         << endl;

    bool checker{false};

    float starting_value{};
    do{
        cout << "Mata in första pris: ";
        cin >> starting_value;
        checker = check_less(starting_value, 0 , "FEL: Första pris måste vara minst 0 (noll) kronor");        
    }
    while(checker == true);

    float end_value{};
    do
    {
        cout << "Mata in sista pris: ";
        
        cin >> end_value;
        checker = check_less(end_value, starting_value , "FEL: Sista pris måste vara större än Första pris");
    } 
    while(checker == true);
    
    float increment{};
    do
    {
        cout << "Mata in steglängd: ";  
        cin >> increment;
        checker = check_less(increment, 0.01 , "FEL: steglängd måste vara minst 0.01");
    } 
    while (checker == true);
    
    float tax{};
    do
    {
        cout << "Mata in momsprocent: ";
        cin >> tax;
        checker = check_less(increment, 0, "FEL: momsprocent måste vara minst 0 ");
    } while (checker == true);
    


    cout << "\nMOMSTABELLEN\n" 
         << setfill('=') << setw(12) << "" << "\n" << setfill(' ') 
         << right << setw(12) << "Pris"
         << right << setw(17) << "Moms"
         << right << setw(20) << "Pris med moms" << "\n"
         << setfill('-') << setw(49) << "" 
         << setfill(' ') << endl;
    
    for(float i = starting_value; i <= end_value; i = i + increment)
    {
        cout << right << fixed << setprecision(2) << setw(12) << i
             << right << fixed << setprecision(2) << setw(17) << tax_amount(i, tax)
             << right << fixed << setprecision(2) << setw(20) << total(i, tax) 
             << endl;
    }
    

    
    
    return 0;
}