#pragma once

template<class T>
class DLList
{
    public:
    //big four
    DLList();
    DLList(const DLList<T> &other);
    DLList<T>& operator=(const DLList<T> &other);
    ~DLList();

    private:

    //Node is an element of the list
    struct Node
    {
        T data; //value
        Node* next; // pointer to the next element in the list
        Node* prev; //pointer to the previous element in the list

        Node(T data, Node* next = nullptr, Node* prev = nullptr)
        {
            this->data = data;
            this->next = next;
            this->prev = prev;
        }
    };

    Node* first; //pointer-helper to hold the connection to the first element of the list;
    size_t size; 

    //helper functions for cleaner work with the constructors
    void copy(const DLList<T>& other);
    void clear();

    public:

    //adding new element to the list
    void pushback(T data);
    void pushfront(T data);

    void print();
    
    bool empty();
    int getSize();
    T getFirst();
    T getLast();

    //sort
    void reverse();
    void split(Node* head, Node** a, Node** b);
    //Node* splitAt(int);
    Node* merge(Node* ls1, Node* ls2);
    void mergeSort(Node** head);
    //from seminar
    void removeOccurences();
    

    //************
    //Iterator from lectures
    class Iterator
    {
        public:
        Iterator (Node*, DLList*);
        Iterator& operator++(); 
        Iterator& operator--(); 
        T& operator*(); //by using & we can change elements, not only read them
        bool operator != (const Iterator& other);

        friend class DLList;

        private:
        Node* current;
        const DLList *list;
    };

    Iterator begin();
    Iterator end();

    bool deleteAt(const Iterator&);
};