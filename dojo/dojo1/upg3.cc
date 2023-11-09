// koperings operator
class List
{
public:
    
    List();
    void insert(int value);  
    void clear()
    {
        while (first->next != nullptr)
        {
            Node * temp{first ->next};
            delete first;
            first = temp;
        }

        delete first;
        first = nullptr;
    }

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
    List l{};
    l.insert(5);
    l.insert(9);
    l.insert(30);

    l.clear();

    return 0;
}