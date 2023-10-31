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
        cerr << massage << endl;
        return true;
    }
    return false;
}

bool check_in_between(float value, float min_value, float max_value, string massage)
{
    if (value < min_value || value > max_value)
    {
        cerr << massage << endl;
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
        checker = check_in_between(increment, 0.01f, 
                                   end_value - starting_value, 
                                   "FEL: steglängd måste vara minst 0.01 och som mest skillnaden mellan sista och första pris");
    } 
    while (checker == true);
    
    float tax{};
    do
    {
        cout << "Mata in momsprocent: ";
        cin >> tax;
        checker = check_in_between(tax, 0, 100, "FEL: momsprocent måste vara minst mellan 0 till 100 % ");
    } while (checker == true);

    cout << "\nMOMSTABELLEN\n" 
         << setfill('=') << setw(12) << "" << "\n" << setfill(' ') 
         << right << setw(12) << "Pris"
         << right << setw(17) << "Moms"
         << right << setw(20) << "Pris med moms" << "\n"
         << setfill('-') << setw(49) << "" 
         << setfill(' ') << endl;

    float steps{(end_value - starting_value)/increment};
    for(int i = 0; i <= steps; i++)
    {
        float value{i*increment + starting_value};
        cout << right << fixed << setprecision(2) << setw(12) << value
             << right << fixed << setprecision(2) << setw(17) << tax_amount(value, tax)
             << right << fixed << setprecision(2) << setw(20) << total(value, tax) 
             << endl;
    }
    

    
    
    return 0;
}