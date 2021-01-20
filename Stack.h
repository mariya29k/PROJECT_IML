#pragma once

template <class T>
class Stack //LIFO
{
    public:
    //big four
    Stack();
    Stack(const Stack<T>& other);
    Stack<T>& operator=(const Stack<T>& other);
    ~Stack();

    //adding element
    void push(T data);
    //removing the last element
    T pop(); 
    bool isEmpty() const;

    T getTop() const;
    size_t getSize() const;
    void print();

    private:

    //Node is an element of the Stack
    struct Node
    {
        T data;
        Node* next;

        Node(T data, Node* next = nullptr)
        {
            this->data = data;
            this->next = next;
        }
    };

    //pointer that saves the connection to the top of the stack
    Node* top;
    size_t size;

    void copy(const Stack<T>& other);
    void clear();

};