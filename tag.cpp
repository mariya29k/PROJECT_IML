#include <iostream>
#include "tag.h"

Tag::Tag()
{
    kind = "";
    expression = "";
    argument = false;
}

Tag::Tag(const Tag& other)
{
    this->kind = other.kind;
    this->expression = other.expression;
    this->argument = other.argument;
}

Tag::Tag(std::string _kind, std::string _expression, bool _argument)
{
    kind = _kind;
    expression = _expression;
    argument = _argument;
}


void Tag::setKind(std::string kind)
{
    this->kind = kind;
}

void Tag::setExpression(std::string expression)
{
    this->expression = expression;
}

void Tag::setArgument(bool argument)
{
    this->argument = argument;
}

std::string Tag::getKind() const
{
    return this->kind;
}
std::string Tag::getExpression() const
{
    return this->expression;
}

bool Tag::hasArgument() const
{
    return this->argument;
}

// int Tag::getArgument() const //moje s edna func, no shte tr func ot string kum number
// {
//     if (hasArgument())
//     {
//         return this->argument;
//     } else return 0;
// }

// std::string Tag::getArgumentString() const
// {
//     if(hasArgument())
//     {
//         return this->argument;
//     }
// }