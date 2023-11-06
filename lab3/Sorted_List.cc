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
        first = new Link_In_List(ins_value, nullptr);
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

    first -> remove_index(index);
}

//-----------------------Private------------------------------------------

//-----------------------Start Link_In_List klass -------------------------
//-----------------------Public--------------------------------------------
Sorted_List::Link_In_List::Link_In_List(int value, Link_In_List* next)
: value{value}, next{next}
{}

Sorted_List::Link_In_List::~Link_In_List()
{
    delete next;
}

void Sorted_List::Link_In_List::insert(int ins_value)
{
    if (next == nullptr)
    {
        next = new Link_In_List(ins_value, nullptr);
    }
    else if ((next -> value) > ins_value)
    {
        Link_In_List* temp = new Link_In_List(ins_value, next);
        next = temp;
    }
    else
    {
        next -> insert(ins_value);
    }
}

int Sorted_List::Link_In_List::size(int counter)
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


int Sorted_List::Link_In_List::get_value_at_index(int index)
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

void Sorted_List::Link_In_List::remove_index(int index)
{
    if (index == 0)
    {
        std::cout << "hej" << std::endl;
        Link_In_List* temp = (next); 
        std::cout << "hej3" << std::endl;
        delete next;
        std::cout << "hej2" << std::endl;
        next = temp;
    }
    else if (next == nullptr)
    {
        throw("Index out of bounds");
    }
    next -> remove_index(--index);
}
//-----------------------Slut Link_In_List klass ------------------------------
