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
	std::cout << "\n������ ID: ";
	input >> customer.id;

	std::cout << "������ �������: ";
	input >> customer.firstname;

	std::cout << "������ ��'�: ";
	input >> customer.secondname;

	std::cout << "������ ���������: ";
	input >> customer.thirdname;

	std::cout << "������ ����� ������: ";
	input >> customer.number;

	std::cout << "������ ������: ";
	input >> customer.balance;

	return input;
}

std::ostream& operator<<(std::ostream& output, const Customer& customer)
{
	output << "\nID: " << customer.id << "\n"
		<< "�������: " << customer.firstname << "\n"
		<< "��'�: " << customer.secondname << "\n"
		<< "���������: " << customer.thirdname << "\n"
		<< "����� ������: " << customer.number << "\n"
		<< "������: " << customer.balance << "\n";

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