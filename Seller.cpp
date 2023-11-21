#include "Seller.h"


Seller::Seller() {
	this->id = 0;
	this->firstname = "";
	this->secondname = "";
	this->thirdname = "";
	this->address = "";
	this->number = "";
	this->productCount = 0;
}

Seller::Seller(int id, std::string firstname, std::string secondname, std::string thirdname, std::string address, std::string number, std::string prductList[MAX_PRODUCTS], int productCount) {
	this->id = id;
	this->firstname = firstname;
	this->secondname = secondname;
	this->thirdname = thirdname;
	this->address = address;
	this->number = number;
	this->productList[MAX_PRODUCTS] = productList[MAX_PRODUCTS];
	this->productCount = productCount;
}

Seller::Seller(const Seller& other) {
	this->id = other.id;
	this->firstname = other.firstname;
	this->secondname = other.secondname;
	this->thirdname = other.thirdname;
	this->address = other.address;
	this->number = other.number;
	this->productList[MAX_PRODUCTS] = other.productList[MAX_PRODUCTS];
	this->productCount = other.productCount;
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

	input >> static_cast<Person&>(seller);

	seller.productCount = 0;

	std::cout << "Введіть Список товарів (для завершення введіть '000'):\n";
	std::string product;
	while (input >> product && product != "000") {
		seller.addProduct(product);
	}

	return input;
}
std::ostream& operator<<(std::ostream& output, const Seller& seller) {
	output << static_cast<const Person&>(seller) << "\n"
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