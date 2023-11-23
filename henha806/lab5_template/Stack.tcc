#include <iostream>

#include <string>
#include "Stack.h"

// --- Public ---

// Constructor.
template <typename T>
Stack<T>::Stack()
:top{nullptr}
{}

// Destructor.
template <typename T>
Stack<T>::~Stack()
{
    clear_list();
}

// Copy constructor.
template <typename T>
Stack<T>::Stack(Stack const& other)
:top{nullptr}
{   
    *this = other;
}

// Move constructor.
template <typename T>
Stack<T>::Stack(Stack && other)
:top{nullptr}
{
    *this = other;
}

// Copy operator.
template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T> const& other) // (Stack<T> && other) ?
{
    if (this != &other)
    {
        clear_list();
        
        if(!other.is_empty())
        {
            other.top -> copy_helper(*this);
        }
    }
    
    return *this;
}

// Move operator.
template <typename T>
Stack<T>& Stack<T>::operator=(Stack<T> && other) // (Stack<T> && other) ?
{
    if (this != &other)
    {
        clear_list();
        
        top = other.top;
        other.top = nullptr;
    }

    return *this;
}

// Check if Sorted List instance is empty.
template <typename T>
bool Stack<T>::is_empty() const
{
    return top == nullptr;
}

// Recursively counts each element in the list and returns the size.
template <typename T>
int Stack<T>::size() const
{
    if (is_empty())
    {
        return 0;
    }
    else
    {
        return top -> size();
    }
}

// push a int value into the beginning of the list.
template <typename T>
void Stack<T>::push(T const ins_value)
{
    top = new Element(ins_value, top);
}

// Returns the value of the element at the sent in index.
template <typename T>
T Stack<T>::get_value_at_index(int const index) const
{
    if (is_empty())
    {
        throw std::out_of_range("Error: Invalid index");
    }

    return top -> get_value_at_index(index);
}

template <typename T>
T Stack<T>::pop()
{
    if(!is_empty())
    {
        if(is_next_empty(top))
        {
            T return_value{top->value};
            clear_list();

            return return_value;
        }
        else
        {
            Element* temp_pointer{top -> next};
            top -> next = nullptr;
            T return_value{top->value};
            delete top;
            top = temp_pointer;

            return return_value;
        }
    }
    throw std::out_of_range("Error: The stack is empty");
}

// Clears the entire list and sets top as a nullptr.
template <typename T>
void Stack<T>::clear_list()
{
    delete top;
    top = nullptr;
}

// --- Private ---
// Checks if there is an element after the element that the sent in pointer is pointing to.
template <typename T>
bool Stack<T>::is_next_empty(Element* const& pointer) const
{
    return pointer -> next == nullptr;
}

// --- private --
// ╰> --- Element ---
//    ╰> --- public ---

// Element constructor.
template <typename T>
Stack<T>::Element::Element(T value, Element* next)
: value{value}, next{next}
{}

// Element destructor.
template <typename T>
Stack<T>::Element::~Element()
{
    delete next;
}

// Function used to recursively count the number of elements in the list.
template <typename T>
int Stack<T>::Element::size(int const counter) const
{
    if (next == nullptr)
    {
        return counter;
    }
    else
    {
        return next -> size(counter + 1);
    }
}
// Function used to recursively return the value at the sent in index.
template <typename T>
T Stack<T>::Element::get_value_at_index(int const index) const
{
    if (index == 0)
    {
        return value;
    }

    if (next == nullptr)
    {
        throw std::out_of_range("Error: Invalid index");
    }

    return next -> get_value_at_index(index - 1);
}

template <typename T>
void Stack<T>::Element::copy_helper(Stack & copy_to)
{
    if(next != nullptr)
    {
        next -> copy_helper(copy_to); 
    }

    copy_to.push(value);
}

template <typename Value_Type, typename List_Type>
Stack<Value_Type> list_to_stack(List_Type const& other)
{
    Stack<Value_Type> new_stack{};
    for(Value_Type item: other)
    {
        new_stack.push(item);
    }

    return new_stack;
}
