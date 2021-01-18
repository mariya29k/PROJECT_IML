#pragma once

template <class T>
class DLList
{
    private:

    struct Node
    {
        T data; //value of element
        Node* next; //pointer to the next element of the list
        Node* prev; //pointer to the previous element of the list

        Node(T data, Node* next = nullptr, Node* prev = nullptr)
        {
            this->data = data;
            this->next = next;
            this->prev = prev;
        }
    };

    Node* first; //pointer to the first element of the list
    Node* last; //pointer to the last element of the list
    size_t size;

    void clear();
    void copy(const DLList<T>& other);

    public:

    DLList();
    DLList(const DLList<T> &other);
    DLList<T>& operator=(const DLList &other);
    ~DLList();

    void pushfront(T data);
    void pushback(T data);

    void print() const;
    DLList<T> operator + (const T&) const;
    DLList<T>& operator += (const T&);
    
    void reverse();
    void swap(Node *left, Node *right);  
    bool empty();

    Node *merge(Node *first, Node *second);
    //mergeSort
    //split 

    public:
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
      
    //Temporary
    template<class E> 
    friend ostream& operator << (ostream&, const DLList<E>&);
};