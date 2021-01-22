#pragma once
#include "DLList.h"
#include "DLList.cpp"


class Expressions
{
    public:
    DLList<double> MAP(std::string expression, int n, DLList<double> list); 
    DLList<double> AGG(std::string expression, DLList<double> list);
    DLList<double> SRT(std::string expression, std::string argument, int n, DLList<double> list);
    
    double add (double first, double second);
    double multiply (double first, double second);
};

/*
    -------- Expressions ----------
    1. Map
        - INC +
        - MLT *
    2. Aggregate
        - SUM +
        - PRO *
        - AVG (+)/n
        - FST 
        - LST
    3. SORT
        - REV 1 2 3 => 3 2 1
        - ORD
            - ASC 2 3 1 => 1 2 3
            - DSC 2 3 1 => 3 2 1
            - SLC '1' 3 2 1 => 2 1
            - DST 2 3 2 2 1 3 4 => 1 4
*/