#include <iostream>
#include "DLList.h"

template <class T>
DLList<T>::DLList(): size(0), fist(nullptr), last(nullptr)
{

}

template <class T>
DLList<T>::DLList(const DLList<T> &other)
{
    this->copy(other);
}

template <class T>
DLList<T>& DLList<T>::operator=(const DLList &other)
{
    if (this != &other)
    {
        this->clear(); //same as clear();
        this->copy(other);
    }
    return *this;
}

template <class T>
DLList<T>::~DLList()
{
    this->clear();
}

template <class T>
void DLList<T>::pushfront(T data)
{
    Node* newNode = new Node(data);
    if (this->first != nullptr) //if list isn't empty
    {
        newNode->next = this->first;
        this->first->prev = newNode;
    }

    this->first = newNode;
    this->size++;
}

template <class T>
void DLList<T>::pushback(T data)
{
    Node* newNode = new Node(data);

    if (this->first == nullptr) //check wheter list is empty
    {
        this->first = newNode;
    }
    else
    {
        Node* current = this->first;
        while (current->next != nullptr) 
        {
            current = current->next;
        }
        current->next = newNode;
        newNode->prev = current;
    }
    this->size++;
}

template <class T>
void DLList<T>::print() const
{
    Node* current = this->first;

    while (current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}

//from lectures
template <class T>
DLList<T> DLList<T>::operator + (const T& x) const
{
    DLList<T> result(*this);
    result += x;
    return result;
}

//*************************************************************************
//FIX THIS
template <class T>
DLList<T>& DLList<T>::operator += (const T& x)
{

    first->next = new DLList<T>::Node {x,first->next,&first};

    if (first->prev == &first)
    {
        first->prev = first->next;
    } else 
    {
        first->next->next->prev = first->next;
    }

    return *this;
}

/*Ако добавяш отзад
Свързваш ласт->некст с нюноуд
И нюноуд->прев с ласт
И местиш ласт
Ако е отпред е същото ама с фърст*/

//************************************************************************8
template <class T>
void DLList<T>::reverse()
{
    typename DLList<T>::Node* current = first;
    typename DLList<T>::Node* holder; //saves the connection
    
    while (current != nullptr)
    {

        holder = current->next;
        current->next = current->prev;
        current->prev = holder;

        current = holder;
    }

    holder = first;
    first = last;
    last = holder;
}


// //idk if i need it yet
// template <class T>
// void DLList<T>::swap(Node *left, Node *right)
// {

// }

template <class T>
bool DLList<T>::empty()
{
    return first == nullptr;
}

template <class T>
void DLList<T>::clear()
{
    Node* holder = nullptr; //pointer used to save the connection to the next element

    while (this-> first != nullptr)
    {
        holder = this->first->next;
        delete = this->first;
        this->first = holder;
    }
    this->size = 0;
}

//can this be better?
template <class T>
void DLList<T>::copy(const DLList<T>& other)
{
    this->size = other.size;

    Node* copyFirst = new Node (other.first->data);
    this->first = copyFirst;

    Node* otherCurrent = other.first; //pointer used for going through the list we want to copy (other)
    Node* copyCurrent = this->first; //pointer used for going through the current list
    Node* newNode = nullptr;

    while (otherCurrent->next != nullptr)
    {
        newNode = new Node(otherCurrent->next->data);
        copyCurrent->next = newNode;
        newNode->prev = copyCurrent;

        otherCurrent = otherCurrent->next;
        copyCurrent = copyCurrent->next;
    }
}

//from lectures
template<class T>
DLList<T>::Iterator::Iterator (Node *_current, DLList<T> *_list): current(_current), list(_list)
{

}

template<class T>
typename DLList<T>::Iterator& DLList<T>::Iterator::operator++()
{
    if (current == nullptr)
    {
        throw out_of_range("No more elements in list.");
    }
    current = current->next;
    return *this;
}

template<class T>
typename DLList<T>::Iterator& DLList<T>::Iterator::operator--()
{
    if (current == nullptr)
    {
        if (list->first == nullptr)
        {
            throw out_of_range("List is empty.");
        } 
        else
        {
            current = list->last; 
        }

    } 
    else
    {
        current = current->prev;
    }    

    current = current->prev;
    return *this;
}

template<class T>
T& DLList<T>::Iterator::operator*() //by using & we can change elements, not only read them
{
    return current->data;
}

template<class T>
bool DLList<T>::Iterator::operator != (const Iterator& other)
{
    return current != other.current;
}

template<class T>
typename DLList<T>::Iterator DLList<T>::begin() //tova e tip iterator, definiran kato vlojen na klas dllist, a metoda e metod na klas dllist
{
    return typename DLList<T>::Iterator(first, this);
}

template<class T>
typename DLList<T>::Iterator DLList<T>::end()
{
    return typename DLList<T>::Iterator(nullptr, this);
}

template<class T>
bool DLList<T>::deleteAt (const Iterator &it)
{
    typename DLList<T>::Box *crr = it.current,
                                    *save;

    if (crr == nullptr) 
    {
        return false;
    }

    if (crr == first)
    //delete first element
    {
        save = first;
        first = first->next;
        delete save;

        if (first == nullptr) //this means the list had only one element
        {
            last = nullptr;
        }

        return true;
    }

    save = crr;
    crr->prev->next = crr->next;

    if(crr->next != nullptr)
    {
        crr->next->prev = crr->prev;
    } else
    {
        last = crr->prev;
    }
    
    delete save;

    return true;
}

// Function to merge two linked lists  
template <class T>
DLList<T>::Node* DLList<T>::merge(Node *first, Node *second)  
{  
    // If first linked list is empty  
    if (!first)  
        return second;  
  
    // If second linked list is empty  
    if (!second)  
        return first;  
  
    // Pick the smaller value  
    if (first->data < second->data)  
    {  
        first->next = merge(first->next,second);  
        first->next->prev = first;  
        first->prev = NULL;  
        return first;  
    }  
    else
    {  
        second->next = merge(first,second->next);  
        second->next->prev = second;  
        second->prev = NULL;  
        return second;  
    }  
}  

//check this
template<class T>
std::ostream& operator << (std::ostream &out, const DLList<T> &list)
{
    typename DLList<T>::Box<T> *crr = list.first;
    while (crr != nullptr)
    {
        out << crr -> data << " ";
        crr = crr -> next;
    }
    return out;
}