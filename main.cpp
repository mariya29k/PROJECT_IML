#include <iostream>
#include <fstream>
#include <sstream>
#include "DLList.h"
#include "DLList.cpp"
#include "IML.h"


int main()
{
    // DLList<int> first;
    // first.pushback(7);
    // first.pushback(3);
    // first.pushback(2);
    // first.pushback(8);
    // first.pushback(5);
    // first.pushback(1);
    // first.pushback(5);
    // first.pushback(2);
    // first.pushback(5);
    // first.pushback(1);

    // DLList<int> second;
    // second.pushback(1);
    // second.pushback(2);
    // second.pushback(3);
    // second.print();
    // second.splitAtList(second,1);
    // second.print();


    // first.print();
    // std::cout<<"*****************";
    // first.removeOccurences();
    // std::cout<<"\n";
    // first.print();
    // std::cout<<"\n*****************\n";
    // first.mergeSortList(first);
    // first.print();
    // std::cout<<"\n********************\n";
    // std::cout<< first.getFirst() << "\n";
    // std::cout << first.getLast();
    // std::cout<<"\n********************\n";
    // first.splitAtList(first, 4);
    // first.print();

    std::ifstream input("test.txt");
    if(input)
    {
        std::stringstream hi;
        hi << input.rdbuf();
        input.close();

        std::string hello;
        std::string ss;
        while(std::getline(hi,hello))
        {
           // hi >> hello;
            //std::cout << "" << hello << "\n";
            std::string ss = hello.substr(10,1);
            std::cout << "" << ss << "\n";
        }
    }
    

    

    return 0;
}