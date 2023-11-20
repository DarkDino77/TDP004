// first:[ ]->[5| ]->[9| ]->[30|\]

// first:[\]

class List
{
public: 
    List();
    void insert(int value);
    void clear()
    {
        while(first -> next != nullptr)
        {
            Node* temp_pointer{first->next};
            delete first;
            first = temp_pointer;
        }
        delete first;
        first = nullptr;
    };

private:
    class Node
    {
    public:
        Node();
        int value;
        Node* next;
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