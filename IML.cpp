#include "IML.h"


void IML::readInput(const std::string& fileName)
{
    std::ifstream input;    

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

    while(std::getline(helper, holder)) //whitespaces
    {
        //std::cout<< holder << std::endl;
        tag.pushback(holder);
    }

    input.close();
}



bool IML::isValid(const std::string &tag)
{
    //couldve made a file with all possible tags and to check from there
    if(tag.substr(0,1) == "<")
    {
        if((getKind(tag) == "MAP" && (getExpession(tag) == "INC" || getExpession(tag) == "MLT")) ||
            (getKind(tag) == "AGG" && (getExpession(tag) == "SUM" || getExpession(tag) == "PRO" || getExpession(tag) == "AVG"  ||
            getExpession(tag) == "FST" || getExpession(tag) == "LST" )) || 
            (getKind(tag) == "SRT" && ( getExpession(tag) == "REV" ||
            getExpession(tag) == "ORD" || getExpession(tag) == "SLC" || getExpession(tag) == "DST")))
        {
            return true;
        }
        else 
        {
            std::cout<<"Wrong input.\n";
            return false;
        }
    }
    else return false;
}



std::string IML::getKind(std::string tag)
{

    return tag.substr(1,3);
}

std::string IML::getExpession(std::string tag)
{
    return tag.substr(5,3);
}

std::string IML::getArgument(std::string tag)
{
    //finds the first " and second " and returns the value between them
    
    size_t size = tag.find("\"");
    std::string tag_substr = tag.substr(size+1); //from this point onward
    size = tag_substr.find("\"");
    tag_substr = tag_substr.substr(0,size);  //between
    
    return tag_substr;
}

DLList<double> IML::getNumbers(std::string tag)
{
    DLList<double> numbers;
    double number;
    std::stringstream helper;
    std::string temp;

    size_t size = tag.find(">");
    std::string tag_substr = tag.substr(size+1); //finds the first > -> after it numbers
    size = tag_substr.find("<");
    tag_substr = tag_substr.substr(0,size); 
    helper << tag_substr;
    
    while(!helper.eof())
    {
        helper >> temp;
        number = std::stod(temp);
        numbers.pushback(number);
    }
    return numbers;
}


DLList<double> IML::Operation(std::string tag)
{
    std::string expression = getExpession(tag);
    std::string argument = getArgument(tag);

    if (getKind(tag) == "MAP")
    {
        return expressions.MAP(expression, argument, getNumbers(tag));
    }
    else if(getKind(tag) == "AGG")
    {
        return expressions.AGG(expression, getNumbers(tag));
    }
    else //(getKind(tag) == "SRT")
    {
        return expressions.SRT(expression, argument, getNumbers(tag));
    }
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
    }

    outFile << save.rdbuf();    
    
}


