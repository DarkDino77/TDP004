#include <iostream>
#include "stack.h"

struct Stack::Node
{
    Node* next;
    int value;
    ~Node();
};

Stack::Node::~Node()
{
    delete next;
};

int Stack::pop()
{
    int v = first->value;
    Node* next = first -> next;
    first->next = nullptr;
    delete first;
    first = next;
    return v;
};

void Stack::push(int i)
{
    Node* new_node = new Node();
    new_node -> next = first;
    new_node -> value = i;
    first = new_node;
};

int main()
{
    Stack stack{};

    for (int n; std::cin >> n;)
    {
        stack.push(n);
    }
    stack.print();
    
}