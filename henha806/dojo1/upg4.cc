// first:[ ]->[5| ]->[9| ]->[30|\]

// first:[\]

class List
{
public: 
    List();
    void insert(int value);
    void clear()
    {
        if(first -> next != nullptr)
        {
            Node* temp_pointer{first->next};
            delete first;
            first = temp_pointer;
        }
        
        if(first->next == nullptr)
        {
            delete first;
            first = nullptr;
        }
        else
        {
            clear();
        }
    };

private:
    class Node
    {
    public:
        Node();
        int value;
        Node* next;
        void clear();
    };
    Node* first{nullptr};
};



int main()
{
    List first_list{};
    first_list.insert(5);
    first_list.insert(9);
    first_list.insert(30);

    first_list.clear();

    return 0;
}