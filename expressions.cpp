#include <iostream>
#include "Expressions.h"


void Expressions::MAP(std::string expression, int n)
{
    
    if (expression == "INC") //+
    {
        for(DLList<double>::Iterator i = list.begin(); i !=  list.end(); i++) // for(int i : list)
        {
            add(n, *i);
        }
    }
    
    if (expression == "MLT") //*
    {
        for(DLList<double>::Iterator i = list.begin(); i !=  list.end(); i++) // for(int i : list)
        {
            multiply(n, *i);
        }
    }
}

void Expressions::AGG(std::string expression)
{
    int helper;

    if(expression == "SUM") 
    {
        helper = 0;
        
        for(DLList<double>::Iterator i = list.begin(); i !=  list.end(); i++) // for(int i : list)
        {
            //so we can recursively add all numbers
            helper += add(helper, *i); 
        }
    }

    if(expression == "PRO")
    {
        helper = 1;
        
        for(DLList<double>::Iterator i = list.begin(); i !=  list.end(); i++) // for(int i : list)
        {
            //so we can recursively multiply all numbers
            helper += multiply(helper, *i); 
        }
    }

    if(expression == "AVG")
    {
        helper = 0;
        
        for(DLList<double>::Iterator i = list.begin(); i !=  list.end(); i++) // for(int i : list)
        {
            helper += add(helper, *i); 
        }

        //AVERAGE
        helper /= list.getSize();
    }

    if(expression == "FST")
    {
        list.getFirst();
    }

    if(expression == "LST")
    {
        list.getLast();
    }

}

void Expressions::SRT(std::string expression, std::string argument, int n)
{
    if (expression == "REV")
    {
        list.reverse();
    }

    if (expression == "ORD")
    {   
        list.mergeSortList(list); 

        if(argument == "DSC")
        {
            //reverses the already sorted in asc order list 
            //so we get the list sorted in descending order
            list.reverse();
        }
    }

    if (expression == "SLC")
    {
        list.splitAtList(list,n);
    }

    if (expression == "DST")
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



 