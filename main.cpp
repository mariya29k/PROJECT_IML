#include <iostream>
#include <fstream>
#include <sstream>
#include "IML.h"


int main()
{
    IML parser;
    const std::string str = "<AGG-PRO>1 2 3</AGG-PRO>";
    parser.parser("test.txt","newfdddile.txt");
    // parser.readInput("test.txt");
    //parser.writeOuput("test.txt", str);
    //std::cout<<parser.Operation(str);


    return 0;
}