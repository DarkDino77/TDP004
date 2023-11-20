#include <iostream>
#include <string>

#include "Sorted_List.h"

// --- Public ---

// Constructor.
Sorted_List::Sorted_List()
:   first{nullptr}
{}

// Destructor.
Sorted_List::~Sorted_List()
{
    clear_list();
}

// Copy constructor.
Sorted_List::Sorted_List(Sorted_List const& other)
:   first{nullptr}
{
    *this = other;
}

// Move constructor.
Sorted_List::Sorted_List(Sorted_List && other)
:   first{nullptr}
{
    *this = other;
}

// Move operator.
Sorted_List& Sorted_List::operator=(Sorted_List && other)
{
    if (this != &other)
    {
        clear_list();

        first = other.first;
        other.first = nullptr;
    }

    return *this;
}

// Copy operator.
Sorted_List& Sorted_List::operator=(Sorted_List const& other)
{
    if(this != &other)
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

// Check if Sorted List instance is empty.
bool Sorted_List::is_empty() const
{
    if(first == nullptr)
    {
        return true;
    }
    return false;
}

// Recursively counts each element in the list and returns the size.
int Sorted_List::size() const
{
    if(is_empty())
    {
        return 0;
    }
    else
    {
        return first -> size();
    }
} 

// Inserts a int value into the beginning of the list.
void Sorted_List::insert(int ins_value)
{
    // [\] or [ ]->[5|\]
    if(is_empty() || (first -> value) > ins_value)
    {
        first = new Element(ins_value, first);
    }

    // [ ]->[1| ]->[8|\] 
    else 
    {
        first -> insert(ins_value);
    }
}

// Returns the value of the element at the sent in index, if it does not exist, return -1.
int Sorted_List::get_value_at_index(int index) const
{
    // Instead of throwing an error, return a default value of -1.
    if(is_empty())
    {
        return -1;
    }
    return first -> get_value_at_index(index);
}

// Removes the element at the index sent in, if index does not exist- do nothing.
void Sorted_List::remove_index(int index)
{
    if(!is_empty() && index >= 0 && index < size())
    {
        if(index == 0)
        {
            remove_and_join(first);
        }

        else
        {
            Element* current{first};
            int counter{0};

            while (counter < (index-1))
            {
                current = current -> next;
                counter++;
            }

            if (is_next_empty(current))
            {
                clear_list();
            }
            else
            {
                remove_and_join(current->next);
            }
        }
    }
}

// Returns the list as a string in the format: '[element_1_value, element_2_value, ...]'
void Sorted_List::clear_list()
{
    delete first;
    first = nullptr;
}

// Uses to_string function to print the list to the cout.
std::string Sorted_List::to_string() const
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

// Clears the entire list and sets first as a nullptr.
void Sorted_List::print_list() const
{
    std::cout << to_string() << std::endl;
}

// --- Private --- 
// Checks if there is an element after the element that the sent in pointer is pointing to.
bool Sorted_List::is_next_empty(Element* pointer)
{
    return pointer -> next == nullptr;
}

// Removes the element after the element that the sent in pointer is pointing to. 
// Redirect the current elements next pointer to the element after the one deleted.
void Sorted_List::remove_and_join(Element* &from)
{
    Element* temp_pointer{from -> next};
    from -> next = nullptr;
    delete from;
    from = temp_pointer;
}

// --- Private --- 
// ╰> --- Element ---
//    ╰> --- public ---

// Element constructor.
Sorted_List::Element::Element(int value, Element* next)
: value{value}, next{next}
{}

// Element destructor.
Sorted_List::Element::~Element()
{
    delete next;
}

// Function used to recursively insert a new element at the correct position.
void Sorted_List::Element::insert(int ins_value)
{
    if(next == nullptr || next -> value > ins_value)
    {
        next = new Element(ins_value, next);
    }

    else
    {
        next -> insert(ins_value);
    }
}

// Function used to recursively count the number of elements in the list.
int Sorted_List::Element::size(int counter)
{
    counter++;
    if (next == nullptr)
    {
        return counter;
    }
    else
    {
        return next -> size(counter);
    }
}

// Function used to recursively return the value at the sent in index.
int Sorted_List::Element::get_value_at_index(int index)
{
    if (index == 0)
    {
        return value;
    }
    // Instead of throwing an error, return a default value of -1.
    else if(next == nullptr)
    {
        return -1;
    }
    index--;
    return next -> get_value_at_index(index);
}