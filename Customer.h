#pragma once
#include <string>
/*
2 Customer
id, прізвище, ім'я, по батькові, адреса, номер кредитної картки, баланс рахунку (кількість грошей).
*/
class Customer
{
	int id;
	std::string firstname;
	std::string secondname;
	std::string thirdname;
	std::string number;
	float balance;

public:
	Customer();
	Customer(int id, std::string firstname, std::string secondname, std::string thirdname, std::string number, float balance);
	Customer(const Customer& other);
};