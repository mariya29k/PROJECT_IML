#include "IML.h"

bool IML::isValid(const Tag& tag)
{

}

void IML::readInput(const std::string& fileName, std::string& expression)
{
    std::ifstream input;
    //ios::in-> read from file

    if(input.is_open())
    {
        std::cout << "File is already opened! " << std::endl;
    } 
    else 
    {   
        std::cout << "File is now opened! " << std::endl;
        input.open(fileName, std::ios::in);
    }
    
    //then we check for errors
    if (input.fail())
    {
        std::cout << "Error opening file! " << std::endl;
        exit(1); //we close the program exit(0) - successfully executed, exit(1) - closed because of fail
    }

    input >> expression; //reads until white space HANDLE IT
    input.close();
}


bool IML::isOpening(char c)
{
    return c == '<';
}

bool IML::isClosing(char c)
{
    return c == '>' || c == '/>';
}

std::string IML::getKind(const Tag& tag)
{
    return tag.getKind();
}

std::string IML::getExpession(const Tag& tag)
{
    return tag.getExpression();
}

std::string IML::getArgument(const Tag& tag)
{

}

void IML::getNumbers(const Tag& tag)
{

}


void IML::Operation(const Tag& tag)
{

}


void IML::writeOuput(const std::string& fileName, const std::string &expression)
{
    std::ofstream  output;

    if (output.is_open())
    {   
        //delete everything already written
        output.open(fileName, std::ios::trunc); 
    }
    else output.open(fileName, std::ios::out);

    if (output.fail())
    {
        std::cout << "Error opening file! " << std::endl;
        exit(1);
    } 
    else
    {
        output << expression;
        std::cout << "Info is saved! " << std::endl;
    }

    output.close();
}



void IML::parser(const std::string input, const std::string output)
{

}