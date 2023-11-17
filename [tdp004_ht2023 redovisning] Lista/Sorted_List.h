#ifndef SORTED_LIST_H
#define SORTED_LIST_H

#include <string>

// Komplettering: Använd const för parametrar som ej bör ändras i ett funktionsanrop. 

class Sorted_List
{
private:
    class Element;
public:
    // Constructors
    Sorted_List();
    ~Sorted_List();
    Sorted_List(Sorted_List const& other);
    Sorted_List(Sorted_List && other);

    // Operator overloads
    Sorted_List& operator=(Sorted_List const& other);
    Sorted_List& operator=(Sorted_List && other);
    
    bool is_empty() const;
    int size() const;
    void insert(int const ins_value);
    int get_value_at_index(int const index) const;
    void remove_index(int const index);
    std::string to_string() const;
    void print_list() const;
    void clear_list();

private:
    // Variable for Sorted list class
    Element* first;
    
    bool is_next_empty(Element* const& pointer) const;
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

        void insert(int const value);
        int size(int const counter = 1) const;
        int get_value_at_index(int const index) const;
    };
};

#endif // SORTED_LIST_H
