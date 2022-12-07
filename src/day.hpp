#pragma once
#include <iostream>
#include <string>

class Day
{
public:
    void Run()
    {
        std::cout << "Part A: " << A() << std::endl;
        std::cout << "Part B: " << B() << std::endl;
    };
protected:
    virtual std::string A() {return "";}
    virtual std::string B() {return "";}
};