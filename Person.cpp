#include "Person.h"

std::istream& operator>>(std::istream& input, Person& person)
{
	std::cout << "\n������ ID: ";
	input >> person.id;

	std::cout << "������ �������: ";
	input >> person.firstname;

	std::cout << "������ ��'�: ";
	input >> person.secondname;

	std::cout << "������ ���������: ";
	input >> person.thirdname;

	std::cout << "������ ������: ";
	input >> person.address;

	std::cout << "������ ����� ������: ";
	input >> person.number;

	return input;
}

std::ostream& operator<<(std::ostream& output, const Person& person)
{
	output << "\nID: " << person.id << "\n"
		<< "�������: " << person.firstname << "\n"
		<< "��'�: " << person.secondname << "\n"
		<< "���������: " << person.thirdname << "\n"
		<< "������: " << person.address << "\n"
		<< "����� ������: " << person.number << "\n";

	return output;
}