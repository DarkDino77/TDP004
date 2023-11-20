#ifndef STACK_H
#define STACK_H

class Stack
{
public:
    Stack() = default;
    ~Stack();
    void push(int i);
    int pop();
    void print();

private:
    struct Node;
    Node* first{nullptr};
};

#endif