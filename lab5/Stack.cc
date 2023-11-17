#include <iostream>

#include "Stack.h"

// --- Public ---

// Constructor.
Stack::Stack()
:first{nullptr}
{}

// Destructor.
Stack::~Stack()
{
    clear_list();
}

// Copy constructor.
Stack::Stack(Stack const& other)
:first{nullptr}
{   
    *this = other;
}

// Move constructor.
Stack::Stack(Stack && other)
:first{nullptr}
{
    *this = other;
}

// Copy operator.
Stack& Stack::operator=(Stack const& other) 
{
    if (this != &other)
    {
        clear_list();
        
        Element* current{other.first};
        while (current != nullptr)
        {
            insert(current->value);
            current = current->next;
        }  
    }
    
    return *this;
}

// Move operator.
Stack& Stack::operator=(Stack && other)
{
    if (this != &other)
    {
        clear_list();
        
        first = other.first;
        other.first = nullptr;
    }

    return *this;
}

// Check if Sorted List instance is empty.
bool Stack::is_empty() const
{
    return first == nullptr;
}

// Recursively counts each element in the list and returns the size.
int Stack::size() const
{
    if (is_empty())
    {
        return 0;
    }
    else
    {
        return first -> size();
    }
}

// Inserts a int value into the beginning of the list.
void Stack::insert(int ins_value)
{
    if (is_empty() || first->value > ins_value)
    {
        first = new Element(ins_value, first);
    }
    else
    {
        first->insert(ins_value);
    }
}

// Returns the value of the element at the sent in index, if it does not exist, return -1.
int Stack::get_value_at_index(int index) const
{
    if (is_empty())
    {
        // Instead of throwing an exception, we return -1.
        return -1;
    }

    return first -> get_value_at_index(index);
}

// Removes the element at the index sent in, if index does not exist- do nothing.
void Stack::remove_index(int index)
{
    if (!is_empty() && index >= 0 && index < size())
    {
        Element* current{first};
        
        for (int counter = 0; (counter < index - 1) && !is_next_empty(current); counter++)
        {
           current = current -> next;
        }
        
        if (is_next_empty(current))
        {
            clear_list();
        }
        else if (index == 0)
        {
            remove_and_join(first);
        }
        else
        {
            remove_and_join(current->next);
        }  
    } 
}

// Returns the list as a string in the format: '[element_1_value, element_2_value, ...]'
std::string Stack::to_string() const
{
    std::string output{"List: ["};
    if(size() > 0)
    {
        for(int i = 0; i < size() ; i++){
            if(i != size()-1)
            {
                output += std::to_string(get_value_at_index(i)) += ", ";
            }
            else
            {
                output += std::to_string(get_value_at_index(i)) += "";
            }
        }
    }

    output += "]";
    return output;
}

// Uses to_string function to print the list to the cout.
void Stack::print_list() const
{
    std::cout << to_string() << std::endl;
}

// Clears the entire list and sets first as a nullptr.
void Stack::clear_list()
{
    delete first;
    first = nullptr;
}

// --- Private ---
// Checks if there is an element after the element that the sent in pointer is pointing to.
bool Stack::is_next_empty(Element* pointer)
{
    return pointer -> next == nullptr;
}

// Removes the element after the element that the sent in pointer is pointing to. 
// Redirect the current elements next pointer to the element after the one deleted.
void Stack::remove_and_join(Element* &from)
{
    Element* temp_pointer{from -> next};
    from -> next = nullptr;
    delete from;
    from = temp_pointer;
}

// --- private --
// ╰> --- Element ---
//    ╰> --- public ---

// Element constructor.
Stack::Element::Element(int value, Element* next)
: value{value}, next{next}
{}

// Element destructor.
Stack::Element::~Element()
{
    delete next;
}

// Function used to recursively insert a new element at the correct position.
void Stack::Element::insert(int ins_value)
{
    if (next == nullptr || next -> value > ins_value)
    {
        next = new Element(ins_value, next);
    }
    else
    {
        next -> insert(ins_value);
    }
}

// Function used to recursively count the number of elements in the list.
int Stack::Element::size(int counter)
{
    if (next == nullptr)
    {
        return counter;
    }
    else
    {
        return next -> size(++counter);
    }
}

// Function used to recursively return the value at the sent in index.
int Stack::Element::get_value_at_index(int index)
{
    if (index == 0)
    {
        return value;
    }

    if (next == nullptr)
    {
        // Insted of throwing we return -1
        return -1;
    }

    return next -> get_value_at_index(--index);
}
