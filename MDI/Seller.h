#pragma once
#include <string>
#include "Person.h"

/*
Seller 
id, прізвище, ім'я, по батькові, адреса, номер рахунку, список товарів.
*/


class Seller : public Person{
    std::string productList;

public:
    Seller();
    Seller(int id, std::string firstname, std::string secondname, std::string thirdname, std::string address, std::string number, std::string productList);
    Seller(const Seller& other);

    ///void addProduct(const std::string& product);
    void getData() override;
    void opData() override;
    int getID() override;

    std::string getFirstname() const;
    std::string getSecondname() const;
    std::string getThirdname() const;
    std::string getAddress() const;
    std::string getNumber() const;
    std::string getProduct() const;

    std::string toString() override;/*

    friend std::ostream& operator<<(std::ostream& output, const Seller& seller);
    friend std::istream& operator>>(std::istream& input, Seller& seller);*/
};

