#include "makeup.hpp"
#include <iostream>
#include <cstring>

CosmeticProduct::CosmeticProduct(std::string n, std::string b, double p, int q, char* desc) 
    : name(n), brand(b), price(p), quantity(q) {
    description = new char[strlen(desc) + 1];
    strcpy(description, desc);
    std::cout << "Constructor was called here."<<std::endl;

}

CosmeticProduct::~CosmeticProduct() {
    delete[] description;
    std::cout << "Destructor was called here."<<std::endl;
}

CosmeticProduct& CosmeticProduct::operator=(CosmeticProduct& other) {
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
std::string CosmeticProduct::getName() { 
    return name; 
}

std::string CosmeticProduct::getBrand() { 
    return brand; 
}

double CosmeticProduct::getPrice() { 
    return price; 
}

int CosmeticProduct::getQuantity() { 
    return quantity; 
}

const char* CosmeticProduct::getDescription() { 
    return description; 
}

// Setters
void CosmeticProduct::setName( std::string& n) { 
    name = n; 
}

void CosmeticProduct::setBrand(std::string& b) { 
    brand = b; 
}

void CosmeticProduct::setPrice(double p) { 
    price = p; 
}

void CosmeticProduct::setQuantity(int q) { 
    quantity = q; 
}

void CosmeticProduct::setDescription(char* desc) {
    delete[] description; 
    description = new char[strlen(desc) + 1];
    strcpy(description, desc);
}

bool CosmeticProduct::sellProduct(int amount) {
    if (amount > quantity) {
        std::cout << "Insufficient stock for " << name << " by " << brand << ". Only " << quantity << " left." << std::endl;
        return false;
    }
    quantity -= amount;
    std::cout << "Sold " << amount << " units of " << name << " by " << brand << ". Remaining stock: " << quantity << std::endl;
    return true;
}


void CosmeticProduct::displayProductInfo() {
    std::cout << "Product - Name: " << name
              << ", Brand: " << brand
              << ", Price: $" << price
              << ", Quantity: " << quantity
              << ", Description: " << description
              << std::endl;
}