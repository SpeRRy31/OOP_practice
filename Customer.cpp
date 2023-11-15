#include "Customer.h"

Customer::Customer() {
	this->id = 0;
	this->firstname = "";
	this->secondname = "";
	this->thirdname = "";
	this->number = "";
	this->balance = 0.0;
}

Customer::Customer(int id, std::string firstname, std::string secondname, std::string thirdname, std::string number, float balance) {
	this->id = id;
	this->firstname = firstname;
	this->secondname = secondname;
	this->thirdname = thirdname;
	this->number = number;
	this->balance = balance;
}

Customer::Customer(const Customer& other) {
	this->id = other.id;
	this->firstname = other.firstname;
	this->secondname = other.secondname;
	this->thirdname = other.thirdname;
	this->number = other.number;
	this->balance = other.balance;
}

std::istream& operator>>(std::istream& input, Customer& customer)
{
	std::cout << "Enter ID: ";
	input >> customer.id;

	std::cout << "Enter First Name: ";
	input >> customer.firstname;

	std::cout << "Enter Second Name: ";
	input >> customer.secondname;

	std::cout << "Enter Third Name: ";
	input >> customer.thirdname;

	std::cout << "Enter Number: ";
	input >> customer.number;

	std::cout << "Enter Balance: ";
	input >> customer.balance;

	return input;
}