#include "Customer.h"

Customer::Customer() {
	Person();
	this->balance = 0.0;
}

Customer::Customer(int id, std::string firstname, std::string secondname, std::string thirdname, std::string address, std::string number, float balance) {
	Person(id, firstname, secondname, thirdname, address, number);
	this->balance = balance;
}

Customer::Customer(const Customer& other) {
	static_cast<Person&>(*this) = other;
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
