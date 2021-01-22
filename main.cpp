#include <iostream>
#include <fstream>
#include <sstream>
#include "IML.h"


int main()
{
    IML parser1;
    std::string input;
    std::string output;

    std::cout << "Enter name of input file.\n";
    std::cin >> input;
    std::cout << "Enter name of output file.\n";
    std::cin >> output;
    parser1.parser(input, output);

    IML parser2;
    parser2.parser("test.txt","newfile.txt");



    //parser.readInput("test.txt");


    // //test Operation func
    // const std::string str = "<AGG-PRO>1 2 3</AGG-PRO>";
    // std::cout<<parser.Operation(str);

    return 0;
}