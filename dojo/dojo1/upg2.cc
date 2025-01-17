// koperings operator
class List
{
public:
    
    List(/* args */);
    ~List();

    List& operator=(List const& other);
    void insert(int value);  

private:
    class Node
    {
    public:
        Node(/* args */);
        ~Node();
        int value;
        Node* next;


    };

    Node* first{nullptr};


};


List& List::operator=(List const& other) 
{

        Node* current {other.first};

        while (current != nullptr)
        {
            insert(current->value);
            current = current->next;
        }  
    
    return *this;
}

int main()
{
    List l{};
    l.insert(5);
    l.insert(9);
    l.insert(30);

    List l_copy{};
    l_copy = l;

    return 0;
}