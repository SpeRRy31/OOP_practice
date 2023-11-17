#include "Seller.h"


Seller::Seller() {
	Person();
	this->productCount = 0;
}

Seller::Seller(int id, std::string firstname, std::string secondname, std::string thirdname, std::string address, std::string number, std::string prductList[MAX_PRODUCTS], int productCount) {
	Person(id, firstname, secondname, thirdname, address, number);
	this->productList[MAX_PRODUCTS] = productList[MAX_PRODUCTS];
	this->productCount = productCount;
}

Seller::Seller(const Seller& other) {
	static_cast<Person&>(*this) = other;
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

