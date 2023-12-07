#include "Seller.h"


Seller::Seller() {
	this->id = 0;
	this->firstname = "";
	this->secondname = "";
	this->thirdname = "";
	this->address = "";
    this->number = "";
    this->productList = "";
}

Seller::Seller(int id, std::string firstname, std::string secondname, std::string thirdname, std::string address, std::string number, std::string productList) {
	this->id = id;
	this->firstname = firstname;
	this->secondname = secondname;
	this->thirdname = thirdname;
	this->address = address;
    this->number = number;
    this->productList = productList;
}

Seller::Seller(const Seller& other) {
	this->id = other.id;
	this->firstname = other.firstname;
	this->secondname = other.secondname;
	this->thirdname = other.thirdname;
	this->address = other.address;
    this->number = other.number;
    this->productList = other.productList;
}
/*
std::istream& operator>>(std::istream& input, Seller& seller) {

	std::cout << "\n������ ID: ";
	input >> seller.id;

	std::cout << "������ �������: ";
	input >> seller.firstname;

	std::cout << "������ ��'�: ";
	input >> seller.secondname;

	std::cout << "������ ���������: ";
	input >> seller.thirdname;

	std::cout << "������ ������: ";
	input >> seller.address;

	std::cout << "������ ����� ������: ";
	input >> seller.number;

	seller.productCount = 0;

	std::cout << "������ ������ ������ (��� ���������� ������ '000'):\n";
	std::string product;
	while (input >> product && product != "000") {
		seller.addProduct(product);
    }

	return input;
}
std::ostream& operator<<(std::ostream& output, const Seller& seller) {
	output << "\nID: " << seller.id << "\n"
		<< "�������: " << seller.firstname << "\n"
		<< "��'�: " << seller.secondname << "\n"
		<< "���������: " << seller.thirdname << "\n"
		<< "������: " << seller.address << "\n"
		<< "����� ������: " << seller.number << "\n"
        << "������ ������:\n";/*
	for (int i = 0; i < seller.productCount; ++i) {
		output << "  - " << seller.productList[i] << "\n";
    }
	return output;
}*/

std::string Seller::toString() {
	std::string outputString = "Seller: " + std::to_string(id) + " " + firstname + " " + secondname +
        " " + thirdname + " " + address + " " + number + " " + productList;
	return outputString;
}
void Seller::getData() {
	std::cout << "��� ��� ��������:\n";
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
	std::cout << "ʳ������ ������: ";
    std::cin >> productList;
}



void Seller::opData() {
	std::cout << "\nID: " << id << "\n"
		<< "�������: " << firstname << "\n"
		<< "��'�: " << secondname << "\n"
		<< "���������: " << thirdname << "\n"
		<< "������: " << address << "\n"
		<< "����� ������: " << number << "\n"
        << "������ ������:\n";
}

int Seller::getID() {
	return this->id;
}

std::string Seller::getFirstname() const {
    return firstname;
}

std::string Seller::getSecondname() const {
    return secondname;
}

std::string Seller::getThirdname() const {
    return thirdname;
}

std::string Seller::getAddress() const {
    return address;
}

std::string Seller::getNumber() const {
    return number;
}

std::string Seller::getProduct() const {
    return productList;
}
