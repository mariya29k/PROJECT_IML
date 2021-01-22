#include <iostream>
#include "Expressions.h"


DLList<double> Expressions::MAP(std::string expression, int n, DLList<double> list)
{
    DLList<double> helper;

    if (expression == "INC") //+
    {
        for(double i : list)
        {
            helper.pushback((n, i));
        }
        return helper;
    }
    
    if (expression == "MLT") //*
    {
        for(double i : list)
        {
            helper.pushback(multiply(n, i));
        }
        return helper;
    }

    return;
}

DLList<double> Expressions::AGG(std::string expression, DLList<double> list)
{
    DLList<double> holder;
    double helper;

    if(expression == "SUM") 
    {
        helper = 0.0;
        
        for(double i : list)
        {
            //so we can recursively add all numbers
            helper += add(helper, i); 
        }

        holder.pushback(helper);
        return holder;
    }

    if(expression == "PRO")
    {
        helper = 1.0;
        
        for(double i : list)
        {
            //so we can recursively multiply all numbers
            helper += multiply(helper, i); 
        }

        holder.pushback(helper);
        return holder;
    }

    if(expression == "AVG")
    {
        helper = 0.0;
        
        for(double i : list)
        {
            helper += add(helper, i); 
        }

        //AVERAGE
        helper /= list.getSize();
        holder.pushback(helper);
        return holder;
    }

    if(expression == "FST")
    {
        helper = list.getFirst();
        holder.pushback(helper);
        return holder;        
    }

    if(expression == "LST")
    {
        helper = list.getLast();
        holder.pushback(helper);
        return holder;  
    }

    return;
}

DLList<double> Expressions::SRT(std::string expression, std::string argument, int n, DLList<double> list)
{
    if (expression == "REV")
    {
        list.reverse();
        return list;
    }

    if (expression == "ORD")
    {   
        list.mergeSortList(list); 

        if(argument == "ASC")
        {
            return list;
        }

        if(argument == "DSC")
        {
            //reverses the already sorted in asc order list 
            //so we get the list sorted in descending order
            list.reverse();
            return list;
        }
        
    }

    if (expression == "SLC")
    {
        list.splitAtList(list,n);
        return list;
    }

    if (expression == "DST")
    {
        list.removeOccurences();
        return list;
    }

    return;
}

double Expressions::add (double first, double second)
{
    return first + second;
}
double Expressions::multiply (double first, double second)
{
    return first * second;
}



 