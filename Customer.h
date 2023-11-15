#pragma once
#include <string>
#include <iostream>
/*
2 Customer
id, �������, ��'�, �� �������, ������, ����� �������� ������, ������ ������� (������� ������).
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

	friend std::istream& operator>>(std::istream& input, Customer& customer);
	friend std::ostream& operator<<(std::ostream& output, const Customer& customer);
};