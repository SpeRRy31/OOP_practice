#pragma once
#include <string>
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
};