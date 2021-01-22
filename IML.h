#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "DLList.h"
#include "tag.h"
#include "expressions.h"

//need:
//a file we read the tags from (input file)
//an object from class Tag
//functions:
//-input validation 
//-read input file
//-reading tag function - opening <, determine kind, determine expression,
//                          *determine arguments, saving the numbers we are working with,
//                           closing >
//-function that calls the needed expressions, 
//-function that saves the final result
//-function that writes the result in an output file

class IML
{
    private:
    std::ifstream input;
    std::ofstream test;
    DLList<std::string> tag;

    //using sstream to save data in the memory
    std::stringstream helper; 
    std::string holder;
    
    Expressions expressions;

    
    public:

    bool isValid(const std::string &tag);
    //expression - Tag or String?
    void readInput(const std::string& fileName);

    //<
    bool isOpening(char c);
    //>
    bool isClosing(char c);
    //kind
    std::string getKind(const std::string &tag);
    //expression
    std::string getExpession(const std::string &tag);
    //get argument and if it is a MAP function we convert it to an integer
    std::string getArgument(const std::string &tag);
    //get numbers and save in a list
    DLList<double> getNumbers(std::string &tag);

    //performs operation
    DLList<double> Operation(std::string &tag);

    //write in File
    void writeOuput(const std::string& fileName, const std::string &expression);


    public:

    //combines all the functions in one 
    void parser(const std::string &input, const std::string &output);


};
