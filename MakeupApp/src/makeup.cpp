#include "makeup.hpp"
#include <iostream>
#include <cstring>

// Constructor
CosmeticProduct::CosmeticProduct(std::string n, std::string b, double p, int q, const char* desc)
    : name(n), brand(b), price(p), quantity(q), description(std::make_unique<char[]>(strlen(desc) + 1)) {
    strcpy(description.get(), desc);
    std::cout << "Constructor for parent class was called here." << std::endl;
}

// Destructor
CosmeticProduct::~CosmeticProduct() {
    std::cout << "Destructor for parent class was called here." << std::endl;
}

// Constructor de copiere
CosmeticProduct::CosmeticProduct(const CosmeticProduct& other)
    : name(other.name), brand(other.brand), price(other.price), quantity(other.quantity),
      description(std::make_unique<char[]>(strlen(other.description.get()) + 1)) {
    strcpy(description.get(), other.description.get());
    std::cout << "Copy Constructor called for: " << name << std::endl;
}

// Operator de copiere
CosmeticProduct& CosmeticProduct::operator=(const CosmeticProduct& other) {
    if (this != &other) {
        name = other.name;
        brand = other.brand;
        price = other.price;
        quantity = other.quantity;

        description = std::make_unique<char[]>(strlen(other.description.get()) + 1);
        strcpy(description.get(), other.description.get());
    }
    std::cout << "Overload operator was called here." << std::endl;
    return *this;
}

// Constructor de mutare
CosmeticProduct::CosmeticProduct(CosmeticProduct&& other) noexcept
    : name(std::move(other.name)), brand(std::move(other.brand)), price(other.price), quantity(other.quantity),
      description(std::move(other.description)) {
    std::cout << "Move Constructor called for: " << name << std::endl;
}

// Operator de mutare
CosmeticProduct& CosmeticProduct::operator=(CosmeticProduct&& other) noexcept {
    if (this != &other) {
        name = std::move(other.name);
        brand = std::move(other.brand);
        price = other.price;
        quantity = other.quantity;
        description = std::move(other.description);
    }
    std::cout << "Move Assignment Operator was called here." << std::endl;
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
    return description.get(); 
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
    description = std::make_unique<char[]>(strlen(desc) + 1);
    strcpy(description.get(), desc);
}

// Funcții
bool CosmeticProduct::sellProduct(int amount) {
    if (amount > quantity) {
        std::cout << "Insufficient stock for " << name << " by " << brand << ". Only " << quantity << " left." << std::endl;
        return false;
    }
    quantity -= amount;
    std::cout << "Sold " << amount << " units of " << name << " by " << brand << ". Remaining stock: " << quantity << std::endl;
    return true;
}

void CosmeticProduct::displayProductInfo() const {
    std::cout << "Product - Name: " << name
              << ", Brand: " << brand
              << ", Price: $" << price
              << ", Quantity: " << quantity
              << ", Description: " << description.get()
              << std::endl;
}
