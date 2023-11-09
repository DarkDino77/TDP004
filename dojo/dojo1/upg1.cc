#ifndef STACK_H
#define STACK_H
class Stack
{
public:

    //Konstruktor för att skapa en tom stack
    Stack() = default;

    // Destructor
    ~Stack();

    // Funktion för att lägga till ett heltal överst på stacken
    void push(int i);

    // Funktion för att ta bort det översta heltalet från stacken
    int pop();

    // Skriver ut hela stacken
    void print() const;

    // Funktion för att hämta värdet som är överst på stacken utan att ta bort det
    int top() const;

    // Funktion för att kontrollera om stacken är tom
    bool is_empty() const;

    // Funktion för att hämta antalet element i stacken
    int size() const;

    // Funktion för att tömma hela stacken
    void clear();

private:
    struct Node;
    Node* first{nullptr};
};

#endif // STACK_H