#include <iostream>
#include <fstream>
#include <sstream>
// #include "DLList.h"
// #include "DLList.cpp"
#include "IML.h"


int main()
{
    IML parser;
    parser.parser("test.txt","newfile.txt");

    return 0;
}