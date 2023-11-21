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
	input >> static_cast<Person&>(customer);

	std::cout << "¬вед≥ть баланс: ";
	input >> customer.balance;

	return input;
}

std::ostream& operator<<(std::ostream& output, const Customer& customer)
{
	output << static_cast<const Person&>(customer) << "\n"
		<< "Ѕаланс: " << customer.balance << "\n";

	return output;
}

std::string Customer::toString() {
	std::string outputString = "Customer: " + std::to_string(id) + " " + firstname + " " + secondname + " " + thirdname + " " + address + " " + number + " " + std::to_string(balance);
	return outputString;
}
