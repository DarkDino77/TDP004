/*Du har rätt i att göra basklassens `evaluate` till en ren virtuell funktion genom att sätta den till "pure virtual" med `= 0`. 
Dessutom måste du använda pekare eller referenser till objekt av de här klasserna för att uppnå polymorfism. 
Här är en korrektad version av ditt program:
*/

#include <iostream>
#include <vector>

using namespace std;

class Binary_Operator
{
public:
  virtual double evaluate(double a, double b) const = 0; // Pure virtual function
};

class Multiply : public Binary_Operator
{
public:
  double evaluate(double a, double b) const override { return a * b; }
};

class Add : public Binary_Operator
{
public:
  double evaluate(double a, double b) const override { return a + b; }
};

int main()
{
  vector<Binary_Operator*> v{ new Multiply{}, new Add{} };

  for (int i{0}; i < v.size(); ++i)
  {
    cout << v[i]->evaluate(5.0, 3.0) << endl;
    delete v[i]; // Free allocated memory
  }

  return 0;
}

/*
Här har jag använt vektor med pekare till Binary_Operator och använt new för att dynamiskt skapa objekt av Multiply och Add. 
Detta är nödvändigt eftersom vi har en vektor av Binary_Operator-pekare och 
behöver därför använda pekare för att behålla typinformationen. 
Vidare har jag använt delete för att frigöra den allokerade minnet när programmet är klart med varje objekt. 
Detta är viktigt för att undvika läckage av minne.

Om du använder C++11 eller senare kan du också använda smarta pekare som std::unique_ptr för att hantera minnet automatiskt,
vilket är en säkrare och bekvämare metod.
*/