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
    std::string argument;

    //two of the kinds of tags include an argument
    //bool hasArgument;

    public:
    //constructors
    Tag();
    Tag(const Tag& other);
    Tag(std::string, std::string, std::string);
    //no need for a destructor since we dont work with dynamic memory

    //setters
    void setKind(std::string kind);
    void setExpression(std::string expression);
    void setArgument(bool);

    //getters
    std::string getKind() const;
    std::string getExpression() const;

    //bool has argument 1 -> getArgument ->
    bool hasArgument() const;
    std::string getArgument() const;

};

