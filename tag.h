#pragma once
#include <string>

class Tag
{
    //Three kinds of tags
    // <MAP-INC "N">, <MAP-MLT "N">
    //<AGG-SUM>, <AGG-PRO>, <AGG-AVG>, <AGG-FST>, <AGG-LST>
    //<SRT-REV>, <SRT-ORD "ARG">

    private:

    std::string kind;
    std::string expression;

    //two of the type of tags include an argument
    bool argument;

    public:
    //constructors
    Tag();
    Tag(const Tag& other);
    Tag(std::string, std::string, bool);
    //no need for a destructor since we dont work with dynamic memory

    //setters
    void setKind(std::string kind);
    void setExpression(std::string expression);
    void setArgument(bool);

    //getters
    std::string getKind() const;
    std::string getExpression() const;
    bool getArgument() const;

};





// //bool isOpen(char c)
// {
//     return c == '<';
// }


//*********but for MLT, AVG etc
// size_t size = expression.size();
// 	for (size_t i = 0; i < size; i++)
// 	{
// 		if (isOpen(expression[i]))
// 		{
// 			stack.push(expression[i]);
// 		}
// 		else // При срещане на затваряща скоба
// 		{
// 			if (stack.empty()) // Ако няма отварящи скоби преди затваряща - изразът не е валиден
// 			{
// 				return false;
// 			}

// 			char stackElement = stack.top();
// 			char exprElement = expression[i];
// 			if (exprElement == ']' && stackElement == '[')
// 			{
// 				stack.pop();
// 			}

// void checkExpression(const std::string& fileName) 
// {
// 	std::ifstream file(fileName); 

// 	if (!file.is_open()) 
// 	{
// 		std::cout << "Unable to open " << fileName << " file.\n";
// 		return;
// 	}

// 	std::string expression;
// 	file >> expression; 

// 	file.close(); 

// 	isBalanced(expression) ? std::cout << "Balanced\n" : std::cout << "Not balanced\n";
// }