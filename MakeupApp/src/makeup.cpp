#include <makeup.hpp>
#include <iostream>
#include <cstring>

CosmeticProduct::CosmeticProduct(std::string n, std::string b, double p, int q, const char* desc) 
    : name(n), brand(b), price(p), quantity(q) {
    description = new char[strlen(desc) + 1];
    strcpy(description, desc);
    std::cout << "Constructor for parent class was called here."<<std::endl;

}

CosmeticProduct::~CosmeticProduct() {
    delete[] description;
    std::cout << "Destructor for parent class was called here."<<std::endl;
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


// Copy Constructor
CosmeticProduct::CosmeticProduct(const CosmeticProduct& other)
    : name(other.name), brand(other.brand), price(other.price), quantity(other.quantity) {
    description = new char[strlen(other.description) + 1];
    strcpy(description, other.description);
    std::cout << "Copy Constructor called for: " << name << std::endl;
}

// Move Constructor
CosmeticProduct::CosmeticProduct(CosmeticProduct&& other) noexcept
    : name(std::move(other.name)), brand(std::move(other.brand)), price(other.price), quantity(other.quantity) {
    description = other.description;
    other.description = nullptr;
    std::cout << "Move Constructor called for: " << name << std::endl;
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

bool CosmeticProduct::sellProduct(int amount) {
    if (amount > quantity) {
        std::cout << "Insufficient stock for " << name << " by " << brand << ". Only " << quantity << " left." << std::endl;
        return false;
    }
    quantity -= amount;
    std::cout << "Sold " << amount << " units of " << name << " by " << brand << ". Remaining stock: " << quantity << std::endl;
    return true;
}


void CosmeticProduct::displayProductInfo() const{
    std::cout << "Product - Name: " << name
              << ", Brand: " << brand
              << ", Price: $" << price
              << ", Quantity: " << quantity
              << ", Description: " << description
              << std::endl;
}