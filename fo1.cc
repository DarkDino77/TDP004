#include <iostream>
#include <string>

using namespace std;

int main()
{
    // int i; // Skapa
    // i = 3; // Tilldelning

    // float f(1.2); // Initiering
    // double d = 2.3; // Initiering
    // char c{'d'}; // Initiering FÖREDRAGET

    // string msg{"Ett litet c++ program"};
    // int const y{7}; // FÖREDRAGET
    // const int z{9};

    // cout << "message: " << msg << ", length: " << msg.size() << ", first char: " << msg.front() << endl;

    /*cout << "Enter a word, a number and a letter: " << flush;

    string word{};
    int number{};
    char letter{};
    cin >> word; // Kontrollerar om det finns något i buffern
    cin >> number;
    cin >> letter;

    cout << "You entered: " << word << ", " << number << ", " << letter << endl;
    */

    string line{};
    cout << "Skriv: ";
    getline(cin, line);
    // cin.ignore(1000, '\n')

    cout << "Din rad var: " << line << endl;

    return 0;
}