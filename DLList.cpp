#include <iostream>
#include <exception>
#include "DLList.h"


template<class T>
DLList<T>::DLList(): first(nullptr), size(0)
{

}

template<class T>
DLList<T>::DLList(const DLList<T> &other)
{
    this->copy(other);
}

template<class T>
DLList<T>& DLList<T>::operator=(const DLList<T> &other)
{
    if(this != &other)
    {
        this->clear();
        this->copy(other);
    }

    return *this;
}

template<class T>
DLList<T>::~DLList()
{
    this->clear();
}

template<class T>
void DLList<T>::copy(const DLList<T>& other)
{
    this->size = other.size;

    //we copy the pointer to the first element of the other list
    Node* holder = newNode(other.first->data);
    this->first = holder;

    //create new pointers used to go through both lists
    Node* otherCopy = other.first; //list we want to copy
    Node* thisCopy = this->fist;    //current list
    Node* newNode = nullptr;

    while (otherCopy->next != nullptr) //going through the list
    {
        //connecting and copying
        newNode = new Node(otherCopy->next->data);
        thisCopy->next = newNode;
        newNode->prev = thisCopy;

        //next step
        otherCopy = otherCopy->next;
        thisCopy = thisCopy->next;
    }
}

template<class T>
void DLList<T>::clear()
{
    Node* holder = nullptr; //pointer that saves the connection to the next element

    while(first != nullptr)
    {
        holder = this->first->next; //next step
        delete this->first; 
        this->first = holder;
    }

    this->size = 0;    
}

template<class T>
void DLList<T>::pushback(T data)
{
    Node* newNode = new Node(data); //creating the new element

    //if empty
    if (first == nullptr)
    {
        first = newNode;
    }
    else
    {
        Node* current = this->first;

        //going through the list until we reach the last element
            while (current->next != nullptr)
            {
                current = current->next;
            }
            //connecting the new element
            current->next = newNode;
            newNode->prev = current;        
    }
    size++;    
}

template<class T>
void DLList<T>::pushfront(T data)
{
    //creating the new element
    Node* newNode = new Node(data);
    
    //if the list is not empty
    if(this->first != nullptr)
    {
        //putting the new element in the front of the list 
        //and connecting it with the first element
        newNode->next = first;
        first->prev = newNode;
    }
    //if empty
    else
    {
        this->first = newNode;
    }
    size++;    
}

template<class T>
void DLList<T>::print()
{
    Node* current = first;

    while(current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}

template<class T>
bool DLList<T>::empty()
{
    return first == nullptr;
}

template<class T>
int DLList<T>::getSize()
{
    return size;
}

template<class T>
void DLList<T>::reverse()
{
    Node* current = first;
    Node* holder = nullptr; //pointer used to save the connection to the previous element

    while(current != nullptr)
    {
        //switching connections
        holder = current->prev;
        current->prev = current->next;
        current->next = holder;
        current = current->prev;
    }

    if (holder != nullptr)
    {
        first = holder->prev;
    }
}

template<class T>
typename DLList<T>::Node* DLList<T>::split()
{
    Node* slowPtr = first; //slowPtr ++ once
    Node* fastPtr = first; //fastPtr ++ twice

    while (fastPtr->next != nullptr && fastPtr->next->next != nullptr)
	{
		fastPtr = fastPtr->next->next;
		slowPtr = slowPtr->next;
	}

	Node* temp = slowPtr->next;
	slowPtr->next = nullptr;
	return temp;
}

template<class T>
typename DLList<T>::Node* DLList<T>::splitAt(int n)
{
    int count = 1;
    Node* current = first;
    Node* helper;
    
    while(current != nullptr)
    {
        if(count != n-1)
        {
            helper = current;
            delete current;
            helper = current->next;
        }
    }
    return helper;
}

// template<class T>
// typename DLList<T>::Node* DLList<T>::merge();

// template<class T>
// typename DLList<T>::Node* DLList<T>::mergeSort();


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
        throw std::out_of_range("No more elements in list.");
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
            throw std::out_of_range("List is empty.");
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

        // if (first == nullptr) //this means the list had only one element
        // {
        //     last = nullptr;
        // }

        return true;
    }

    save = crr;
    crr->prev->next = crr->next;

    if(crr->next != nullptr)
    {
        crr->next->prev = crr->prev;
    
    }
    //  else
    // {
    //     last = crr->prev;
    // }
    delete save;

    return true;
}
