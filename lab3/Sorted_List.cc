#include <iostream>

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
//
bool Sorted_List::is_empty()
{
    if (first == nullptr)
    {
        return true;
    }
    
    return false;
}

int Sorted_List::size()
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
    else
    {
        first -> insert(ins_value);
    }
}

int Sorted_List::get_value_at_index(int index)
{
    if (is_empty())
    {
        throw ("This value does not exist");
    }

    return first -> get_value_at_index(index);
}

void Sorted_List::remove_index(int index)
{
    if (is_empty())
    {
        throw ("This value does not exist");
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
        throw("Index out of bounds");
    }
    return next -> get_value_at_index(--index);
}

//void Sorted_List::Element::remove_index(int index)
//{
    
//}
//-----------------------Slut Link_In_List klass ------------------------------
