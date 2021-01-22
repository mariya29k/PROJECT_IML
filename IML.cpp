#include "IML.h"


void IML::readInput(const std::string& fileName)
{
    std::ifstream input;
    std::string writeTag; //saving the tags in the DLList
    

    if(input.is_open())
    {
        std::cout << "File is already opened! " << std::endl;
    } 
    else 
    {   
        std::cout << "File is now opened! " << std::endl;
        input.open(fileName, std::ios::in); //ios::in-> read from file
    }
    
    //then we check for errors
    if (input.fail())
    {
        std::cout << "Error opening file! " << std::endl;
        exit(1); //we close the program exit(0) - successfully executed, exit(1) - closed because of fail
    }

    
    helper << input.rdbuf();    
    input.close();

    while(std::getline(helper, holder)) //whitespaces
    {
        helper >> holder;
        tag.pushback(holder);
        writeOuput("translation.txt", holder);
    }

}



bool IML::isValid(const std::string &tag)
{
    std::ifstream translation("translation.txt"); //change to string, because u will use other files bruhhh
    if(input)
    {
        helper << translation.rdbuf();
        translation.close();



        while(std::getline(helper, holder))
        {
            if(holder.substr(1,1) != "<") 
                            return false;
            // else if (holder.substr(1,3) )
            
        }

    }
    return false;
}


// bool IML::isOpening(char c)
// {
//     return c == '<';
// }

// bool IML::isClosing(char c)
// {
//     return c == '>' || c == '/>';
// }

std::string IML::getKind(const std::string &tag)
{
    return holder.substr(1,3);
}

std::string IML::getExpession(const std::string &tag)
{
    return holder.substr(5,3);
}

std::string IML::getArgument(const std::string &tag)
{
    if(holder.substr(1,3) == "MAP" || holder.substr(1,3) == "SLC")
    {
        //needs validation in case of numbers bigger than 9
        //if (holder.substr(11,1) != '"') return holder.substr(10,2);
        return holder.substr(10,1);
    }

    if(holder.substr(5,3) == "ASC") return "ASC";

    if(holder.substr(5,3) == "DSC") return "DSC";

    return nullptr;
}

DLList<double> IML::getNumbers(std::string &tag)
{
    DLList<double> numbers;
    double number;    

    for(char& c : tag)
    {
        if(c != ' ' && c != '<' && (c > 'A' && c < 'Z') && c != '"' && c != '-' && c != '/' && c != '>')
        {
            number = c - '0';
            numbers.pushback(number);
        }
    }
    return numbers;
}


DLList<double> IML::Operation(std::string &tag)
{
    int n = std::stoi(getArgument(tag)); //string to int
    std::string expression = getExpession(tag);
    std::string argument = getArgument(tag);

    DLList<double> returnList; //because i dont know what to return here


    if (getKind(tag) == "MAP")
    {
        return expressions.MAP(expression, n, getNumbers(tag));
    }

    if(getKind(tag) == "AGG")
    {
        return expressions.AGG(expression, getNumbers(tag));
    }

    if(getKind(tag) == "SRT")
    {
        return expressions.SRT(expression, argument, n, getNumbers(tag));
    }

    return returnList; //because i dont know what to return here
}




void IML::writeOuput(const std::string& fileName, const std::string &expression)
{
    std::ofstream output;

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



void IML::parser(const std::string &input, const std::string &output)
{
    readInput(input);
    std::ofstream outFile(output);
    std::stringstream save;
    
    for(std::string i : tag)
    { 
            save << Operation(i)<<std::endl;
            outFile << save.rdbuf();    
    }
    
    
}


//fix isValid
//fix parser