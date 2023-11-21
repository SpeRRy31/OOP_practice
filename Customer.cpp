#include "Customer.h"

Customer::Customer() {
	this->id = 0;
	this->firstname = "";
	this->secondname = "";
	this->thirdname = "";
	this->address = "";
	this->number = "";
	this->balance = 0.0;
}

Customer::Customer(int id, std::string firstname, std::string secondname, std::string thirdname, std::string address, std::string number, float balance) {
	this->id = id;
	this->firstname = firstname;
	this->secondname = secondname;
	this->thirdname = thirdname;
	this->address = address;
	this->number = number;
	this->balance = balance;
}

Customer::Customer(const Customer& other) {
	this->id = other.id;
	this->firstname = other.firstname;
	this->secondname = other.secondname;
	this->thirdname = other.thirdname;
	this->address = other.address;
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

	std::cout << "Введіть адресу: ";
	input >> customer.address;

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
		<< "Адреса: " << customer.address << "\n"
		<< "Номер картки: " << customer.number << "\n"
		<< "Баланс: " << customer.balance << "\n";

	return output;
}

std::string Customer::toString() {
	std::string output_string = "Customer: " + std::to_string(id) + " " + firstname + " " + secondname + " " + thirdname + " " + address + " " + number + " " + std::to_string(balance);
	return output_string;
}

void Customer::getData() {
	std::cout << "Введіть дані покупця:\n";
	std::cout << "ID: ";
	std::cin >> id;
	std::cout << "Прізвище: ";
	std::cin >> firstname;
	std::cout << "Ім'я: ";
	std::cin >> secondname;
	std::cout << "Побатькове: ";
	std::cin >> thirdname;
	std::cout << "Адрес: ";
	std::cin >> address;
	std::cout << "Номер картки: ";
	std::cin >> number;
	std::cout << "Баланчіс: ";
	std::cin >> balance;
}

void Customer::opData() {
	std::cout << "\nID: " << id << "\n"
		<< "Прізвище: " << firstname << "\n"
		<< "Ім'я: " << secondname << "\n"
		<< "Побатькові: " << thirdname << "\n"
		<< "Адреса: " << address << "\n"
		<< "Номер картки: " << number << "\n"
		<< "Баланс: " << balance << "\n";
}