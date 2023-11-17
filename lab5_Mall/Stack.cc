#include <iostream>

#include "Stack.h"
// --- Public ---

// Constructor.
Stack::Stack()
:top{nullptr}
{}

// Destructor.
Stack::~Stack()
{
    clear_list();
}

// Copy constructor.
Stack::Stack(Stack const& other)
:top{nullptr}
{   
    *this = other;
}

// Move constructor.
Stack::Stack(Stack && other)
:top{nullptr}
{
    *this = other;
}

// Copy operator.
Stack& Stack::operator=(Stack const& other) 
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
Stack& Stack::operator=(Stack && other)
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
bool Stack::is_empty() const
{
    return top == nullptr;
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
        return top -> size();
    }
}

// Inserts a int value into the beginning of the list.
void Stack::push(int const ins_value)
{
        top = new Element(ins_value, top);
}

// Returns the value of the element at the sent in index, if it does not exist, return -1.
int Stack::get_value_at_index(int const index) const
{
    if (is_empty())
    {
        // Instead of throwing an exception, we return -1.
        return -1;
    }

    return top -> get_value_at_index(index);
}

// Removes the element at the index sent in, if index does not exist- do nothing.
int Stack::pop()
{
    if (!is_empty())
    {
        if (is_next_empty(top))
        {
            int return_value{top->value};

            clear_list();

            return return_value;
        }
        else
        {
            // Removes the element after the element that the sent in pointer is pointing to. 
            // Redirect the current elements next pointer to the element after the one deleted.
            Element* temp_pointer{top -> next};
            int return_value{top->value};

            top -> next = nullptr;
            delete top;

            top = temp_pointer;
            return return_value;
        }
    }
    return -1;
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

// Clears the entire list and sets top as a nullptr.
void Stack::clear_list()
{
    delete top;
    top = nullptr;
}

// --- Private ---
// Checks if there is an element after the element that the sent in pointer is pointing to.
bool Stack::is_next_empty(Element* const& pointer) const
{
    return pointer -> next == nullptr;
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

// Function used to recursively count the number of elements in the list.
int Stack::Element::size(int const counter) const
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
int Stack::Element::get_value_at_index(int const index) const
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

    return next -> get_value_at_index(index - 1);
}

void Stack::Element::copy_helper(Stack & copy_to)
{
    if(next != nullptr)
    {
        next -> copy_helper(copy_to);
    }

    copy_to.push(value);
}
