#ifndef STACK_H
#define STACK_H

#include <string>

// Komplettering: Använd const för parametrar som ej bör ändras i ett funktionsanrop. 

class Stack
{
private:
    class Element;
public:
    // Constructors
    Stack();
    ~Stack();
    Stack(Stack const& other);
    Stack(Stack && other);

    // Operator overloads
    Stack& operator=(Stack const& other);
    Stack& operator=(Stack && other);
    
    bool is_empty() const;
    int size() const;
    void push(int const ins_value);
    int get_value_at_index(int const index) const;
    int pop();
    std::string to_string() const;
    void print_list() const;
    void clear_list();

private:
    // Variable for Sorted list class
    Element* top;
    
    bool is_next_empty(Element* const& pointer) const;

    // Inner class used to represent each link in the list as an element object.
    class Element
    {
    public:
        // Variables for Element class
        int value;
        Element* next;

        // Constructors
        Element(int value, Element* next);
        ~Element(); 

        int size(int const counter = 1) const;
        int get_value_at_index(int const index) const;
        void copy_helper(Stack & copy_to);
    };
};

#endif // STACK_H
