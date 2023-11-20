#ifndef STACK_H
#define STACK_H

class Stack
{
public:
    // Default constructor and destructor for the stack class.
    Stack() = default;
    ~Stack();

    // Functino to add an int to the beginning of the stack.
    void push(int i);

    // Function to remove the first node of the stack.
    int pop();

    // Function to print the whole stack.
    void print() const;

    // Function to retrieve the first value in the stack.
    int top() const;

    // Function to determine wthere the stack is empty or not
    bool is_empty() const;

    // Returns the size of the stack (number of nodes).
    int size() const;

    // Function to clear the entire stack, setting first to a nullptr.
    void clear();

private:
    // Struct for the node.
    struct Node;
    Node* first{nullptr};
};

#endif