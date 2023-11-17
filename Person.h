#pragma once
#include <string>
#include <iostream>

class Person
{
    int id;
    std::string firstname;
    std::string secondname;
    std::string thirdname;
    std::string address;
    std::string number;
public:
    Person();
    Person(int id, std::string firstname, std::string secondname, std::string thirdname, std::string address, std::string number);
    Person(const Person& other);

    friend std::istream& operator>>(std::istream& input, Person& person); 
    friend std::ostream& operator<<(std::ostream& output, const Person& person);
};

