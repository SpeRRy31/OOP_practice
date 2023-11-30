#include "Seller.h"


Seller::Seller() {
	this->id = 0;
	this->firstname = "";
	this->secondname = "";
	this->thirdname = "";
	this->address = "";
	this->number = "";
	this->productCount = 0;

	for (int i = 0; i < MAX_PRODUCTS; ++i) {
		this->productList[i] = "";
	}
}

Seller::Seller(int id, std::string firstname, std::string secondname, std::string thirdname, std::string address, std::string number, std::string prductList[MAX_PRODUCTS], int productCount) {
	this->id = id;
	this->firstname = firstname;
	this->secondname = secondname;
	this->thirdname = thirdname;
	this->address = address;
	this->number = number;
	this->productCount = productCount;

	for (int i = 0; i < MAX_PRODUCTS; ++i) {
		this->productList[i] = productList[i];
	}
}

Seller::Seller(const Seller& other) {
	this->id = other.id;
	this->firstname = other.firstname;
	this->secondname = other.secondname;
	this->thirdname = other.thirdname;
	this->address = other.address;
	this->number = other.number; 
	this->productCount = other.productCount;

	for (int i = 0; i < MAX_PRODUCTS; ++i) {
		this->productList[i] = other.productList[i];
	}
}

void Seller::addProduct(const std::string& product) {
	if (productCount < MAX_PRODUCTS) {
		productList[productCount++] = product;
	}
	else {
		std::cout << "Помилка: досягнуто максимальну кількість товарів\n";
	}
}

std::istream& operator>>(std::istream& input, Seller& seller) {

	std::cout << "\nВведіть ID: ";
	input >> seller.id;

	std::cout << "Введіть прізвище: ";
	input >> seller.firstname;

	std::cout << "Введіть ім'я: ";
	input >> seller.secondname;

	std::cout << "Введіть побатькові: ";
	input >> seller.thirdname;

	std::cout << "Введіть адресу: ";
	input >> seller.address;

	std::cout << "Введіть номер картки: ";
	input >> seller.number;


	seller.productCount = 0;

	std::cout << "Введіть Список товарів (для завершення введіть '000'):\n";
	std::string product;
	while (input >> product && product != "000") {
		seller.addProduct(product);
	}

	return input;
}
std::ostream& operator<<(std::ostream& output, const Seller& seller) {
	output << "\nID: " << seller.id << "\n"
		<< "Прізвище: " << seller.firstname << "\n"
		<< "Ім'я: " << seller.secondname << "\n"
		<< "Побатькові: " << seller.thirdname << "\n"
		<< "Адреса: " << seller.address << "\n"
		<< "Номер картки: " << seller.number << "\n"
		<< "Список товарів:\n";
	for (int i = 0; i < seller.productCount; ++i) {
		output << "  - " << seller.productList[i] << "\n";
	}
	return output;
}

std::string Seller::toString() {
	std::string outputString = "Seller: " + std::to_string(id) + " " + firstname + " " + secondname +
		" " + thirdname + " " + address + " " + number;
	for (int i = 0; i < productCount; ++i) {
		outputString += " -" + productList[i];
	}
	return outputString;
}
void Seller::getData() {
	std::cout << "Дані про продавця:\n";
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
	std::cout << "Кількість товару: ";
	std::cin >> productCount;
	std::cout << "Введіть " << productCount << " товара:\n";
	for (int j = 0; j < productCount; ++j) {
		std::cout << "Товар " << j + 1 << ": ";
		std::cin >> productList[j];
	}
}

void Seller::opData() {
	std::cout << "\nID: " << id << "\n"
		<< "Прізвище: " << firstname << "\n"
		<< "Ім'я: " << secondname << "\n"
		<< "Побатькові: " << thirdname << "\n"
		<< "Адреса: " << address << "\n"
		<< "Номер картки: " << number << "\n"
		<< "Список товарів:\n";
	for (int i = 0; i < productCount; ++i) {
		std::cout << "  - " << productList[i] << "\n";
	}
}

int Seller::getID() {
	return this->id;
}