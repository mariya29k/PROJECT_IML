#pragma once
#include <iostream>
#include "Stack.h"

template<class T>
Stack<T>::Stack(): top(nullptr), size(0)
{

}

template<class T>
Stack<T>::Stack(const Stack<T>& other)
{
    this->copy(other);
}

template<class T>
Stack<T>& Stack<T>::operator=(const Stack<T>& other)
{
    if (this != &other)
    {
        this->clear();
        this->copy(other);
    }
    return *this;
}

template<class T>
Stack<T>::~Stack()
{
    this->clear();
}

template<class T>
void Stack<T>::push(T data)
{
    Node* newNode = new Node(data);
    
    if(top != nullptr)
    {
        newNode->next = top;
    }
    top = newNode;
    size++;
}

template<class T>
typename T Stack<T>::pop()
{
    if(this->isEmpty())
    {
        throw std::out_of_range("Stack is empty.");
    }

    Node* holder = top->next;
    T data = holder->data;
    delete top;

    top = holder;
    size--;
    return data;
} 

template<class T>
bool Stack<T>::isEmpty() const
{
    return top == nullptr;
}

template<class T>
typename T Stack<T>::getTop() const
{
    if (this->isEmpty())
    {
        throw std::out_of_range("Stack is empty");
    }

    return top->data;
}

template<class T>
size_t Stack<T>::getSize() const
{
    return this->size;
}

template<class T>
void Stack<T>::print()
{
    Node* current = top;
    while(current != nullptr)
    {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << "\n";
}

template<class T>
void Stack<T>::copy(const Stack<T>& other)
{
    this->size = other.sizel
    this->top = new Node(other.top->data);

    Node* otherCurrent = other.top;
	Node* copyCurrent = this->top;

	while (otherCurrent->next != nullptr)
	{
		copyCurrent->next = new Node(otherCurrent->next->data);
		copyCurrent = copyCurrent->next;
		otherCurrent = otherCurrent->next;
	}
}

template<class T>
void Stack<T>::clear()
{
    Node* holder = nullptr; 
	while (top != nullptr)
	{
		holder = top->next;
		delete top;
		top = holder;
	}
	size = 0;
}