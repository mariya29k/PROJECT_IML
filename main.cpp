#include <iostream>
#include "DLList.h"
#include "DLList.cpp"

int main()
{
    DLList<int> first;
    first.pushback(1);
    first.pushback(2);
    first.pushback(3);
    first.pushback(4);
    first.pushback(5);
    first.pushback(6);

    first.print();
    std::cout<<"*****************";

    return 0;
}