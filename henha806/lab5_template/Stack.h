#ifndef STACK_H
#define STACK_H

#include <string>

template <typename T>
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
    Stack<T>& operator=(Stack<T> const& other);
    Stack<T>& operator=(Stack<T> && other);
    
    bool is_empty() const;
    int size() const;
    void push(T const ins_value);
    T get_value_at_index(int const index) const;
    T pop();
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
        T value;
        Element* next;

        // Constructors
        Element(T value, Element* next);
        ~Element(); 

        int size(int const counter = 1) const;
        T get_value_at_index(int const index) const;
        void copy_helper(Stack & copy_to);
    };
};

template <typename Value_Type, typename List_Type>
Stack<Value_Type> list_to_stack(List_Type const& other);

#include "Stack.tcc"

#endif // STACK_H
