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
	std::cout << "\n������ ID: ";
	input >> customer.id;

	std::cout << "������ �������: ";
	input >> customer.firstname;

	std::cout << "������ ��'�: ";
	input >> customer.secondname;

	std::cout << "������ ���������: ";
	input >> customer.thirdname;

	std::cout << "������ ������: ";
	input >> customer.address;

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
		<< "������: " << customer.address << "\n"
		<< "����� ������: " << customer.number << "\n"
		<< "������: " << customer.balance << "\n";

	return output;
}

std::string Customer::toString() {
	std::string output_string = "Customer: " + std::to_string(id) + " " + firstname + " " + secondname + " " + thirdname + " " + address + " " + number + " " + std::to_string(balance);
	return output_string;
}

void Customer::getData() {
	std::cout << "������ ��� �������:\n";
	std::cout << "ID: ";
	std::cin >> id;
	std::cout << "�������: ";
	std::cin >> firstname;
	std::cout << "��'�: ";
	std::cin >> secondname;
	std::cout << "����������: ";
	std::cin >> thirdname;
	std::cout << "�����: ";
	std::cin >> address;
	std::cout << "����� ������: ";
	std::cin >> number;
	std::cout << "��������: ";
	std::cin >> balance;
}

void Customer::opData() {
	std::cout << "\nID: " << id << "\n"
		<< "�������: " << firstname << "\n"
		<< "��'�: " << secondname << "\n"
		<< "���������: " << thirdname << "\n"
		<< "������: " << address << "\n"
		<< "����� ������: " << number << "\n"
		<< "������: " << balance << "\n";
}