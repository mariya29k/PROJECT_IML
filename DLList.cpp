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
T DLList<T>::getFirst()
{
    Node* current = first;
    if (current == nullptr)
    {
        throw std::out_of_range("List is empty");
    }

    return first->data;
}

template<class T>
T DLList<T>::getLast()
{
    Node* current = first;
    if (current == nullptr)
    {
        throw std::out_of_range("List is empty");
    }
    
    while(current->next != nullptr)
    {
        current = current->next;
    }

    return current->data;
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

//The functions split, merge and mergeSort didn't work successfully when given
//a parameter DLList<T> -- this idea is taken from the internet
// template<class T>
// void DLList<T>::split(Node* head, Node** a, Node** b)
// {
//     Node* slowPtr = head; //slowPtr ++ once
//     Node* fastPtr = head; //fastPtr ++ twice

//     while (fastPtr->next != nullptr && fastPtr->next->next != nullptr)
// 	{
// 		fastPtr = fastPtr->next->next;
// 		slowPtr = slowPtr->next;
// 	}

//     //Node* temp?
// 	b = slowPtr->next;
// 	slowPtr->next = nullptr;
// }

// template<class T>
// typename DLList<T>::Node* DLList<T>::splitAt(int n)
// {
//     int count = 1;
//     Node* current = first;
//     Node* helper;
    
//     while(current != nullptr)
//     {
//         if(count != n-1)
//         {
//             helper = current;
//             delete current;
//             helper = current->next;
//         }
//     }
//     return helper;
// }

// template<class T>
// typename DLList<T>::Node* DLList<T>::merge(Node* list1, Node* list2)
// {
//     //If a list is empty
//     if(list1 == nullptr)
//     {
//         return list2;
//     }

//     if(list2 == nullptr)
//     {
//         return list1;
//     }

//     //Recursively chosing the smallest and merge
//     if(a->data <= b<-data)
//     {
//         a->next = merge(a->next,b);
//         a->next->prev = a;
//         a->prev = nullptr;
//         return a
//     } else
//     {
//         b->next = merge(b->next, a);
//         b->next->prev = b;
//         b->prev = nullptr;
//         return b;
//     }    
// }
// //i guess in order to avoid .... use **
// template<class T>
// void DLList<T>::mergeSort(Node** head)
// {
//     if (*head == nullptr || (*head)->next == nullptr)
//     {  
//         throw std::out_of_range ("List is empty.");
//     }

//     //splits the list1 and list2 into sublists
//     Node *list1 = head, 
//         *list2 = nullptr;
//     split(*head, &list1, &list2);
  
//     // Recur for left and right halves  
//     mergeSort(&list1);  
//     mergeSort(&list2);  
  
//     // Merge the two sorted halves  
//     head = merge(list1, list2); 
// }

template<class T>
void DLList<T>::removeOccurences()
{
	Node* firstPtr = first;
	Node* secondPtr = nullptr;
	Node* nextHolder = nullptr;

	while (firstPtr != nullptr && firstPtr->next != nullptr)
	{
		secondPtr = firstPtr->next;
		while (secondPtr != nullptr) // Търсим срещане на текущия елемент в останалата част от списъка
		{
			nextHolder = secondPtr->next; // Пазим връзка към следващия елемент, за данея загубим след изтриването
			if (firstPtr->data == secondPtr->data)
			{
				secondPtr->prev->next = secondPtr->next;
				if (secondPtr->next != nullptr) 
				{
					secondPtr->next->prev = secondPtr->prev;
				}
				delete secondPtr;
			}
			secondPtr = nextHolder;
		}
		firstPtr = firstPtr->next;
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
