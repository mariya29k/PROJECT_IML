#include <iostream>
#include "DLList.h"
#include "DLList.cpp"

int main()
{
    DLList<int> first;
    first.pushback(7);
    first.pushback(3);
    first.pushback(2);
    first.pushback(8);
    first.pushback(5);
    first.pushback(1);
    first.pushback(5);
    first.pushback(2);
    first.pushback(5);
    first.pushback(1);


    first.print();
    std::cout<<"*****************";
    first.removeOccurences();
    first.print();
    std::cout<<"\n*****************\n";
    //first.mergeSort(first);
    std::cout<< first.getLast() << "\n";
    std::cout << first.getFirst();
    

    return 0;
}