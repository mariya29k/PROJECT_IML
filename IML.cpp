#include "IML.h"

bool IML::isValid(const Tag& tag)
{

}

void IML::readInput(const std::string& fileName, std::string& expression)
{
    std::ifstream input;
    //ios::in-> read from file
    input.open(fileName, std::ios::in);

    //error
    if(!input.is_open())
    {
        std::cout << "Error occured when opening file." << std::endl;
        return;
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

}

std::string IML::getExpession(const Tag& tag)
{

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

}



void IML::parser(const std::string input, const std::string output)
{

}