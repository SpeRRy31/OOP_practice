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
	std::cout << "\nВведіть ID: ";
	input >> customer.id;

	std::cout << "Введіть прізвище: ";
	input >> customer.firstname;

	std::cout << "Введіть ім'я: ";
	input >> customer.secondname;

	std::cout << "Введіть побатькові: ";
	input >> customer.thirdname;

	std::cout << "Введіть номер картки: ";
	input >> customer.number;

	std::cout << "Введіть баланс: ";
	input >> customer.balance;

	return input;
}

std::ostream& operator<<(std::ostream& output, const Customer& customer)
{
	output << "\nID: " << customer.id << "\n"
		<< "Прізвище: " << customer.firstname << "\n"
		<< "Ім'я: " << customer.secondname << "\n"
		<< "Побатькові: " << customer.thirdname << "\n"
		<< "Номер картки: " << customer.number << "\n"
		<< "Баланс: " << customer.balance << "\n";

	return output;
}

bool Customer::operator==(const Customer& other) const
{
	return (id == other.id &&
		firstname == other.firstname &&
		secondname == other.secondname &&
		thirdname == other.thirdname &&
		number == other.number &&
		balance == other.balance);
}