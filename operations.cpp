#include <iostream>
#include "operations.h"

void Operations::MAP()
{
    if (tag.getExpression() == "INC")
    {
        double argument = tag.getArgument();
        // for(int i = list.begin(); i < list.end(); i++) // for(int i : list)
        // {
        //     add(argument, *i);
        // }
    }
    
    if (tag.getExpression() == "MLT")
    {
        //same but multiply
    }
}

void Operations::AGG()
{
    if(tag.getExpression() == "SUM")
    {

    }

    if(tag.getExpression() == "PRO")
    {
        
    }

    if(tag.getExpression() == "AVG")
    {
        
    }

    if(tag.getExpression() == "FST")
    {
        
    }

    if(tag.getExpression() == "LST")
    {
        
    }

}

void Operations::SRT()
{
    if (tag.getExpression() == "REV")
    {
        list.reverse();
    }

    if (tag.getExpression() == "ORD")
    {
        // if (tag.getArgument() == "ASC")
        // {

        // }

        // if (tag.getArgument() == "DSC")
        // {

        // }
    }

    if (tag.getExpression() == "SLC")
    {
        
    }

    if (tag.getExpression() == "DST")
    {
        
    }
}