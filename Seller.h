#pragma once
#include <string>
#include <iostream>
#include "Person.h"

/*
Seller 
id, прізвище, ім'я, по батькові, адреса, номер рахунку, список товарів.
*/

const int MAX_PRODUCTS = 10;

class Seller : public Person{
    std::string productList[MAX_PRODUCTS];
    int productCount;

public:
    Seller();
    Seller(int id, std::string firstname, std::string secondname, std::string thirdname, std::string address, std::string number, std::string prductList[MAX_PRODUCTS], int productCount);
    Seller(const Seller& other);

    void addProduct(const std::string& product);
    void getData() override;
    void opData() override;
    int getID() override;
    std::string toString() override;

    friend std::ostream& operator<<(std::ostream& output, const Seller& seller);
    friend std::istream& operator>>(std::istream& input, Seller& seller);
};

