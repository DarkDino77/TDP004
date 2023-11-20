#ifndef SORTED_LIST_H
#define SORTED_LIST_H

class Sorted_List
{
private:
    class Element;

public:
    Sorted_List();
    ~Sorted_List();
    Sorted_List(Sorted_List const& other);
    Sorted_List(Sorted_List && other);

    Sorted_List& operator=(Sorted_List && other);
    Sorted_List& operator=(Sorted_List const& other) ;

    bool is_empty() const;
    int size() const;
    void insert(int value);
    int get_value_at_index(int index) const;
    void remove_index(int index);
    void clear_list();

    std::string to_string() const;
    void print_list() const; // Only for debugging :)

private:
    Element* first;
    bool is_next_empty(Element* pointer);
    void remove_and_join(Element* &from);

    class Element
    {
    public:
        int value;
        Element* next;

        Element(int value, Element* next);
        ~Element();

        void insert(int value); 
        int size(int counter = 0);

        int get_value_at_index(int index);
    };
        
};

#endif