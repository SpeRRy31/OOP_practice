#pragma once
#include <string>
#include <iostream>
#include "Person.h"
/*
2 Customer
id, прізвище, ім'я, по батькові, адреса, номер кредитної картки, баланс рахунку (кількість грошей).
*/
class Customer : public Person
{
	float balance;

public:
	Customer();
	Customer(int id, std::string firstname, std::string secondname, std::string thirdname, std::string address, std::string number, float balance);
	Customer(const Customer& other);

    std::string getFirstname() const;
    std::string getSecondname() const;
    std::string getThirdname() const;
    std::string getAddress() const;
    std::string getNumber() const;
    float getBalance() const;

	std::string toString() override;
	void getData() override;
	void opData() override;
	int getID() override;



	friend std::istream& operator>>(std::istream& input, Customer& customer);
	friend std::ostream& operator<<(std::ostream& output, const Customer& customer);
};
