#ifndef SORTED_LIST_H
#define SORTED_LIST_H

class Sorted_List
{
private:
    class Link_In_List;
public:
    Sorted_List();
    ~Sorted_List();

    bool is_empty();
    int size();
    void insert(int ins_value);
    int get_value_at_index(int index);

    void remove_index(int index);

private:
    Link_In_List* first;

    class Link_In_List
    {
        public:

        int value;
        Link_In_List* next;

        Link_In_List(int value, Link_In_List* next);
        ~Link_In_List();

        void insert(int value);

        int size(int counter = 1);

        int get_value_at_index(int index);

        void remove_index(int index);

    };

};

#endif // SORTED_LIST_H
