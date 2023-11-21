#pragma once
#include <string>
#include <iostream>

class Person
{
protected:
    int id;
    std::string firstname;
    std::string secondname;
    std::string thirdname;
    std::string address;
    std::string number;
public:
    virtual std::string toString() = 0;
    virtual void getData() = 0;
    virtual void opData() = 0;
};

