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

    bool is_empty() const;
    int size() const;
    void insert(int ins_value);
    int get_value_at_index(int index) const;

    void remove_index(int index);

    Sorted_List& operator=(Sorted_List const& l);
    
    void print_list() const;


private:
    Element* first;

    class Element
    {
        public:

        int value;
        Element* next;

        Element(int value, Element* next);
        ~Element(); 

        void insert(int value);

        int size(int counter = 1);

        int get_value_at_index(int index);
    };
};

#endif // SORTED_LIST_H
