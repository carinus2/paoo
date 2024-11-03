#include "makeup.hpp"
#include <iostream>
#include <cstring>

CosmeticProduct::CosmeticProduct(std::string n, std::string b, double p, int q, const char* desc) 
    : name(n), brand(b), price(p), quantity(q) {
    description = new char[strlen(desc) + 1];
    strcpy(description, desc);
    std::cout << "Constructor was called here."<<std::endl;

}

CosmeticProduct::~CosmeticProduct() {
    delete[] description;
    std::cout << "Destructor was called here."<<std::endl;
}

CosmeticProduct& CosmeticProduct::operator=(const CosmeticProduct& other) {
    if (this != &other) {
        name = other.name;
        brand = other.brand;
        price = other.price;
        quantity = other.quantity;

        delete[] description; 
        description = new char[strlen(other.description) + 1];
        strcpy(description, other.description);
    }
    std::cout << "Overload operator was called here."<<std::endl;
    return *this;
}

// Getters
std::string CosmeticProduct::getName() const { 
    return name; 
}

std::string CosmeticProduct::getBrand() const { 
    return brand; 
}

double CosmeticProduct::getPrice() const { 
    return price; 
}

int CosmeticProduct::getQuantity() const { 
    return quantity; 
}

const char* CosmeticProduct::getDescription() const { 
    return description; 
}

// Setters
void CosmeticProduct::setName(const std::string& n) { 
    name = n; 
}

void CosmeticProduct::setBrand(const std::string& b) { 
    brand = b; 
}

void CosmeticProduct::setPrice(double p) { 
    price = p; 
}

void CosmeticProduct::setQuantity(int q) { 
    quantity = q; 
}

void CosmeticProduct::setDescription(const char* desc) {
    delete[] description; 
    description = new char[strlen(desc) + 1];
    strcpy(description, desc);
}
