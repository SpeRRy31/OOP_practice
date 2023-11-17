#include "Person.h"

Person::Person() {
	this->id = 0;
	this->firstname = "";
	this->secondname = "";
	this->thirdname = "";
	this->address = "";
	this->number = "";
}

Person::Person(int id, std::string firstname, std::string secondname, std::string thirdname, std::string address, std::string number) {
	this->id = id;
	this->firstname = firstname;
	this->secondname = secondname;
	this->thirdname = thirdname;
	this->address = address;
	this->number = number;
}

Person::Person(const Person& other) {
	this->id = other.id;
	this->firstname = other.firstname;
	this->secondname = other.secondname;
	this->thirdname = other.thirdname;
	this->address = other.address;
	this->number = other.number;
}

std::istream& operator>>(std::istream& input, Person& person)
{
	std::cout << "\nВведіть ID: ";
	input >> person.id;

	std::cout << "Введіть прізвище: ";
	input >> person.firstname;

	std::cout << "Введіть ім'я: ";
	input >> person.secondname;

	std::cout << "Введіть побатькові: ";
	input >> person.thirdname;

	std::cout << "Введіть адресу: ";
	input >> person.address;

	std::cout << "Введіть номер картки: ";
	input >> person.number;

	return input;
}

std::ostream& operator<<(std::ostream& output, const Person& person)
{
	output << "\nID: " << person.id << "\n"
		<< "Прізвище: " << person.firstname << "\n"
		<< "Ім'я: " << person.secondname << "\n"
		<< "Побатькові: " << person.thirdname << "\n"
		<< "Адреса: " << person.address << "\n"
		<< "Номер картки: " << person.number << "\n";

	return output;
}