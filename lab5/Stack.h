#ifndef STACK_H
#define STACK_H

#include <string>

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
    void insert(int ins_value);
    int get_value_at_index(int index) const;
    void remove_index(int index);
    std::string to_string() const;
    void print_list() const;
    void clear_list();

private:
    // Variable for Sorted list class
    Element* first;
    
    bool is_next_empty(Element* pointer);
    void remove_and_join(Element* &from);

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

        void insert(int value);
        int size(int counter = 1);
        int get_value_at_index(int index);
    };
};

#endif // STACK_H
