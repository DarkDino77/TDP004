#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/* Komplettering: Upprepa inte cin statements i onödan. Man kan läsa in till flera variabler i rad genom att 
   “chaina” cin strömmar. Detta för att operatorn utvärderas och returnerar strömmer i sig.   

   Tex:  

     int i;  

     float f;  

     cin >> i;  

     cin >> f;  

   Kan skrivas som:  

     cin >> i>> f;  

*/ 

int main()
{   

    cout << "Skriv in ett heltal: ";
    int natural_number{};
    cin >> natural_number;
    cout << "Du skrev in talet: " << natural_number 
         << "\n" << endl;
    cin.ignore(1000, '\n');

    cout << "Skriv in fem heltal: " << flush;
    cin >> natural_number;
    cout << "Du skrev in talen: " << natural_number << ", ";
    cin >> natural_number;
    cout << natural_number << ", ";
    cin >> natural_number;
    cout << natural_number << ", ";
    cin >> natural_number;
    cout << natural_number << ", ";
    cin >> natural_number;
    cout << natural_number << "\n" << endl;
    cin.ignore(1000, '\n');

    cout << "Skriv in ett flyttal: ";
    float real_number{};
    cin >> real_number;
    cout << "Du skrev in flyttalet: " 
         << fixed << setprecision(3) 
         << real_number << "\n" << endl;
    cin.ignore(1000, '\n');

    cout << "Skriv in ett heltal och ett flyttal: ";
    cin >> natural_number >> real_number;
    cout << "Du skrev in heltalet:" 
         << right << setw(10) 
         << natural_number << endl; 
    cout << "Du skrev in flyttalet:" 
         << right << setw(9) 
         << real_number << "\n" << endl;
    cin.ignore(1000, '\n');

    cout << "Skriv in ett flyttal och ett heltal: ";
    cin >> real_number >> natural_number;
    cout << "Du skrev in heltalet:" 
         << right << setfill('-') << setw(10) 
         << natural_number << endl; 
    cout << "Du skrev in flyttalet:" 
         << right << setfill('-') << setw(9) 
         << real_number << "\n" << endl;
    cin.ignore(1000, '\n');

    cout << "Skriv in ett tecken: ";
    char character{};
    cin >> character;
    cout << "Du skrev in tecknet: " 
         << character << "\n" << endl;
    cin.ignore(1000, '\n');

    cout << "Skriv in en sträng: ";
    string text{};
    cin >> text;
    cout << "Strängen '" 
         << text << "' har " 
         << text.size() << " tecken." 
         << "\n" << endl;
    cin.ignore(1000, '\n');

    cout << "Skriv in ett heltal och en sträng: ";
    cin >> natural_number >> text;
    cout << "Du skrev in talet |" << natural_number 
         << "| och strängen |" << text << "|." 
         << "\n" << endl;
    cin.ignore(1000, '\n');

    cout << "Skriv in en sträng och ett flyttal: ";
    cin >> text >> real_number;
    cout << "Du skrev in talet \"" 
         << fixed << setprecision(3) << real_number 
         << "\" och strängen \"" << text << "\"." 
         << "\n" << endl;
    cin.ignore(1000, '\n');

    cout << "Skriv in en hel rad med text: ";
    getline(cin, text);
    cout << "Du skrev in textraden: '" 
         << text << "'" << "\n" << endl;

    cout << "Skriv in en textrad som slutar med ett negativt heltal: ";
    getline(cin, text, '-');
    cin >> natural_number;
    cout << "Du skrev in textraden: '" 
         << text << "' och heltalet '-" << natural_number << "'." << "\n" << endl;

    return 0;
}