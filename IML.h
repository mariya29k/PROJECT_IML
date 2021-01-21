#pragma once
#include <iostream>
#include <fstream>
#include "DLList.h"
#include "tag.h"
#include "operations.h"

//need:
//a file we read the tags from (input file)
//an object from class Tag
//functions:
//-input validation 
//-read input file
//-reading tag function - opening <, determine kind, determine expression,
//                          *determine arguments, saving the numbers we are working with,
//                           closing >
//-function that calls the needed operations, 
//-function that saves the final result
//-function that writes the result in an output file

class IML
{
    private:
    std::istream input;
    //it should be a DLList?
    Tag tag;

    //******************************************************

    bool isValid(const Tag& tag);
    //expression - Tag or String?
    void readInput(const std::string& fileName, std::string& expression);

    //<
    bool isOpening(char c);
    //>
    bool isClosing(char c);
    //kind
    std::string getKind(const Tag& tag);
    //expression
    std::string getExpession(const Tag& tag);
    //get argument
    std::string getArgument(const Tag& tag);
    //get numbers and save in a list
    void getNumbers(const Tag& tag);

    //performs operation
    void Operation(const Tag& tag);

    //write in File
    void writeOuput(const std::string& fileName, const std::string &expression);


    public:

    //combines all the functions in one 
    void parser(const std::string input, const std::string output);


};
