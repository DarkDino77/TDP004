// first:[ ]->[5| ]->[9| ]->[30|\]

//  copy:[ ]->[5| ]->[9| ]->[30|\]

class List
{
public: 
    List();
    List& operator=(List const& other);
    void insert(int value);

private:
    class Node
    {
    public:
        Node();
        ~Node(); // delete next;
        int value;
        Node* next;
    };
    Node* first{nullptr};
};

List& List::operator=(List const& other)
{
    Node* current{other.first};

    while(current != nullptr)
    {
        insert(current -> value);
        current = current -> next;
    }

    return *this;
}

int main()
{
    List first_list{};
    first_list.insert(5);
    first_list.insert(9);
    first_list.insert(30);

    List list_copy{};
    list_copy = first_list;

    return 0;
}