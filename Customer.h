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

	friend std::istream& operator>>(std::istream& input, Customer& customer);
	friend std::ostream& operator<<(std::ostream& output, const Customer& customer);
};