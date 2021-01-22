#include <iostream>
#include "Expressions.h"


DLList<double> Expressions::MAP(std::string expression, std::string argument, DLList<double> list)
{
    DLList<double> helper;    
    int n = stringToInt(argument);

    if (expression == "INC") //+
    {
        for(double i : list)
        {
            helper.pushback(add(n, i));
        }
    }
    
    if (expression == "MLT") //*
    {
        for(double i : list)
        {
            helper.pushback(multiply(n, i));
        }
    }

    return helper;
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
    }

    if(expression == "PRO")
    {
        helper = 1.0;
        
        for(double i : list)
        {
            //so we can recursively multiply all numbers
            helper *= i; 
        }

        holder.pushback(helper);
    }

    if(expression == "AVG")
    {   
        int count = 0;
        helper = 0.0;
        
        for(double i : list)
        {
            helper += i;
            count++; 
        }

        //AVERAGE
        helper /=count;
        holder.pushback(helper);
    }

    if(expression == "FST")
    {
        helper = list.getFirst();
        holder.pushback(helper);      
    }

    if(expression == "LST")
    {
        helper = list.getLast();
        holder.pushback(helper); 
    }

    return holder;
}

DLList<double> Expressions::SRT(std::string expression, std::string argument, DLList<double> list)
{
    DLList<double> holder;

    if (expression == "REV")
    {
        list.reverse(); 
        holder = list;       
    }

    if (expression == "ORD")
    {   
        list.mergeSortList(list); 

        if(argument == "ASC")
        {
            holder = list;
        }

        if(argument == "DSC")
        {
            //reverses the already sorted in asc order list 
            //so we get the list sorted in descending order
            list.reverse();
            holder = list;
        }
     
    }

    if (expression == "SLC")
    {
        int n = stringToInt(argument);
        list.splitAtList(list,n);
        holder = list;
    }

    if (expression == "DST")
    {
        list.removeOccurences();
        holder = list;
    }

    return holder;
}

double Expressions::add (double first, double second)
{
    return first + second;
}
double Expressions::multiply (double first, double second)
{
    return first * second;
}

int Expressions::stringToInt(std::string argument)
{
    return std::stoi(argument);
}



 