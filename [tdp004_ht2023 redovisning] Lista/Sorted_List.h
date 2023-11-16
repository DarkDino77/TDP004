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
    void insert(int ins_value);
    int get_value_at_index(int index) const;
    void remove_index(int index);
    std::string to_string() const;
    void print_list() const;
    void clear_list();

private:
    // Variable for Sorted list class
    Element* first;
    
    bool is_next_empty(Element* pointer);
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

        void insert(int value);
        int size(int counter = 1);
        int get_value_at_index(int index);
    };
};

#endif // SORTED_LIST_H
