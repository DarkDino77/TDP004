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
    delete first;
}

// kopiering konstruktor
Sorted_List::Sorted_List(Sorted_List const& other)
{   
    first = nullptr;
    *this = other;
}

// flyttkonstruktor
Sorted_List::Sorted_List(Sorted_List && other)
{
    first = nullptr;
    *this = other;

}

// koperings operator
Sorted_List& Sorted_List::operator=(Sorted_List const& other) 
{
    
    if (this != &other)
    {
        if (first)
        {
            delete first;
        }
        first = nullptr;

        Element* current {other.first};

        if (current != nullptr)
        {
            do
            {
                insert(current -> value);
                current = current -> next;
            }
            while ((current != nullptr) && ((current -> next) != nullptr));

            // This if-statement makes sure that the last element inserts its value into target 
            // if the list is larger than size 1
            if ((current != nullptr) && ((current -> next) == nullptr))
            {
                insert(current -> value);
            }
        }   
    }
    
    return *this;
}

// Flyttoperator
Sorted_List& Sorted_List::operator=(Sorted_List && other)
{
    if (this != &other)
    {
        if (first != nullptr)
        {
            delete first;
        }
        
        first = other.first;
        other.first = nullptr;
    }

    return *this;
}

//
bool Sorted_List::is_empty() const
{
    if (first == nullptr)
    {
        return true;
    }
    
    return false;
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
    if (is_empty())
    {
        first = new Element(ins_value, nullptr);
    }
    else if((first -> value) > ins_value)
    {
        first = new Element(ins_value, first);
    }
    else if (first -> next == nullptr)
    {
        first -> next = new Element(ins_value, nullptr);
    }    
    else
    {
        first -> insert(ins_value);
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
                delete first;
                first = nullptr;
            }
            else
            {
                Element* temp_pointer{first -> next};
                first -> next = nullptr;
                delete first;
                first = temp_pointer;
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
                delete current;
            }
            else
            {
                Element* temp{(current -> next) -> next};
                ((current -> next) -> next) = nullptr;
                delete (current -> next);
                (current -> next) = temp;
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

//-----------------------Private------------------------------------------

//-----------------------Start Element klass -------------------------
//-----------------------Public--------------------------------------------
Sorted_List::Element::Element(int value, Element* next)
: value{value}, next{next}
{}

Sorted_List::Element::~Element()
{
    delete next;
}

void Sorted_List::Element::insert(int ins_value)
{
    if (next == nullptr)
    {
        next = new Element(ins_value, nullptr);
    }
    else if ((next -> value) > ins_value)
    {
        Element* temp = new Element(ins_value, next);
        next = temp;
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

//-----------------------Slut Link_In_List klass ------------------------------
