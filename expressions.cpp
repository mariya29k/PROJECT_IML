#include <iostream>
#include "Expressions.h"


void Expressions::MAP()
{
    int x = std::stoi(tag.getArgument()); //string to int
    if (tag.getExpression() == "INC") //+
    {
        for(DLList<double>::Iterator i = list.begin(); i !=  list.end(); i++) // for(int i : list)
        {
            add(x, *i);
        }
    }
    
    if (tag.getExpression() == "MLT") //*
    {
        for(DLList<double>::Iterator i = list.begin(); i !=  list.end(); i++) // for(int i : list)
        {
            multiply(x, *i);
        }
    }
}

void Expressions::AGG()
{
    int helper;

    if(tag.getExpression() == "SUM") 
    {
        helper = 0;
        
        for(DLList<double>::Iterator i = list.begin(); i !=  list.end(); i++) // for(int i : list)
        {
            //so we can recursively add all numbers
            helper += add(helper, *i); 
        }
    }

    if(tag.getExpression() == "PRO")
    {
        helper = 1;
        
        for(DLList<double>::Iterator i = list.begin(); i !=  list.end(); i++) // for(int i : list)
        {
            //so we can recursively multiply all numbers
            helper += multiply(helper, *i); 
        }
    }

    if(tag.getExpression() == "AVG")
    {
        helper = 0;
        
        for(DLList<double>::Iterator i = list.begin(); i !=  list.end(); i++) // for(int i : list)
        {
            helper += add(helper, *i); 
        }

        //AVERAGE
        helper /= list.getSize();
    }

    if(tag.getExpression() == "FST")
    {
        list.getFirst();
    }

    if(tag.getExpression() == "LST")
    {
        list.getLast();
    }

}

void Expressions::SRT()
{
    if (tag.getExpression() == "REV")
    {
        list.reverse();
    }

    if (tag.getExpression() == "ORD")
    {   
        list.mergeSortList(list); 

        if(tag.getArgument() == "DSC")
        {
            //reverses the already sorted in asc order list 
            //so we get the list sorted in descending order
            list.reverse();
        }
    }

    if (tag.getExpression() == "SLC")
    {
        list.splitAtList(list,stoi(tag.getArgument()));
    }

    if (tag.getExpression() == "DST")
    {
        list.removeOccurences();
    }
}

double Expressions::add (double first, double second)
{
    return first + second;
}
double Expressions::multiply (double first, double second)
{
    return first * second;
}



 