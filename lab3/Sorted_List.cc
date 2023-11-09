#include <iostream>
#include <string>

#include "Sorted_List.h"

//-----------------------Public-------------------------------------------

// Construtor
Sorted_List::Sorted_List()
:first{nullptr}
{}

//Destructor
Sorted_List::~Sorted_List()
{
    clear_list();
}

// kopiering konstruktor
Sorted_List::Sorted_List(Sorted_List const& other)
:first{nullptr}
{   
    *this = other;
}

// flyttkonstruktor
Sorted_List::Sorted_List(Sorted_List && other)
:first{nullptr}
{
    *this = other;
}

// koperings operator
Sorted_List& Sorted_List::operator=(Sorted_List const& other) 
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

// Flyttoperator
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

//
bool Sorted_List::is_empty() const
{
    return first == nullptr;
}

int Sorted_List::size() const
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

void Sorted_List::insert(int ins_value)
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

int Sorted_List::get_value_at_index(int index) const
{
    if (is_empty())
    {
        // Insted of throwing we return -1
        return -1;
    }

    return first -> get_value_at_index(index);
}

void Sorted_List::remove_index(int index)
{
    if (!is_empty())
    {
        if (index == 0)
        {
            if (first -> next == nullptr)
            {
                clear_list();
            }
            else
            {
               remove_and_join(first);
            }
        }
        else
        {
            Element* current{first};
            int counter{0};
            while ((counter < index - 1) && (current -> next != nullptr))
            {
                current = current -> next;
                counter++;
            }

            if ((current -> next) == nullptr)
            {
                if(size() == 1)
                {
                    delete (current -> next);
                    first = nullptr;
                }
                else
                {
                    delete (current -> next);
                    (current -> next) = nullptr;
                }
            }
            else
            {
               remove_and_join(current->next);
            }
        }
    } 
}


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

void Sorted_List::print_list() const
{
    std::cout << to_string() << std::endl;
}

void Sorted_List::clear_list()
{
    delete first;
    first = nullptr;
}

// --- Private ---

void Sorted_List::remove_and_join(Element* &from)
{
    Element* temp_pointer{from -> next};
    from -> next = nullptr;
    delete from;
    from = temp_pointer;
}

// ╰> --- Element ---
//    ╰> --- public ---

Sorted_List::Element::Element(int value, Element* next)
: value{value}, next{next}
{}

Sorted_List::Element::~Element()
{
    delete next;
}

void Sorted_List::Element::insert(int ins_value)
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

int Sorted_List::Element::size(int counter)
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


int Sorted_List::Element::get_value_at_index(int index)
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
