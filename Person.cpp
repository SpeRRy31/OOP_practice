#include "Person.h"

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