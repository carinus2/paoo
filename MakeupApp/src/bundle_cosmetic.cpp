#include "bundle_cosmetic.hpp"
#include <iostream>

BundleCosmeticProduct::BundleCosmeticProduct(std::string n, std::string b, double p, int q, const char* desc,
                                             const std::vector<CosmeticProduct>& productList, double discount)
    : CosmeticProduct(n, b, p, q, desc), products(productList), bundleDiscount(discount) {
    std::cout << "Constructor for child class was called here" << std::endl;
}

BundleCosmeticProduct::~BundleCosmeticProduct() {
    std::cout << "Destructor for child class was called here" << std::endl;
}

double BundleCosmeticProduct::calculateBundlePrice() const {
    double originalPrice = 0.0;
    for (const auto& product : products) {
        originalPrice += product.getPrice();
    }
    return originalPrice * (1 - bundleDiscount / 100);
}

void BundleCosmeticProduct::displayBundleInfo() const {
    displayProductInfo();
    std::cout << "Bundle contains the following products:\n";
    for (const auto& product : products) {
        product.displayProductInfo();
    }
    std::cout << "Bundle discount: " << bundleDiscount << "%\n";
    std::cout << "Total price after discount: $" << calculateBundlePrice() << std::endl;
}
