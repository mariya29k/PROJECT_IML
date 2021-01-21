#include <iostream>
#include "operations.h"

void Operations::MAP()
{
    double argument = tag.getArgument();

    if (tag.getExpression() == "INC") //+
    {
        for(DLList<double>::Iterator i = list.begin(); i !=  list.end(); i++) // for(int i : list)
        {
            add(argument, *i);
        }
    }
    
    if (tag.getExpression() == "MLT") //*
    {
        for(DLList<double>::Iterator i = list.begin(); i !=  list.end(); i++) // for(int i : list)
        {
            multiply(argument, *i);
        }
    }
}

void Operations::AGG()
{
    int helper;
    //kude zapisvame rezultata?

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

void Operations::SRT()
{
    //switch
    if (tag.getExpression() == "REV")
    {
        list.reverse();
    }

    if (tag.getExpression() == "ORD")
    {
        if(tag.getArgument() == "ASC")
        {
            //sorts the list in ascending order
            // list.mergeSort(list);
        }

        if (tag.getArgument() == "DSC")
        {
            //list.mergeSort(list)
            //reverses the already sorted in asc order list 
            //so we get the list sorted in descending order
            list.reverse();
        }
    }

    if (tag.getExpression() == "SLC")
    {
        //splitAt
    }

    if (tag.getExpression() == "DST")
    {
        list.removeOccurences();
    }
}

double Operations::add (double first, double second)
{
    return first + second;
}
double Operations::multiply (double first, double second)
{
    return first * second;
}

 