#include "bundle_cosmetic.hpp"
#include <iostream>
#include <vector>
#include <mutex>

// Mutex pentru gestionarea resurselor
std::mutex resourceMutex;
std::vector<std::string> soldProducts;

// Funcție Template
template <typename T>
void displayProductDetails(const T& product) {
    product.displayProductInfo();
}

// Funcție pentru vânzarea unui produs cu protecție Mutex
void sellProductWithMutex(CosmeticProduct& product, int quantity) {
    std::lock_guard<std::mutex> lock(resourceMutex);
    if (product.sellProduct(quantity)) {
        soldProducts.push_back(product.getName());
        std::cout << product.getName() << " has been sold and added to the sold products list." << std::endl;
    }
}

int main() {
    CosmeticProduct lipstick("Lipstick", "MAC", 10.99, 5, "Bright red shade, long-lasting.");
    displayProductDetails(lipstick);

    CosmeticProduct lipstickCopy = lipstick;
    displayProductDetails(lipstickCopy);

    CosmeticProduct lipstickMoved = std::move(lipstick);
    displayProductDetails(lipstickMoved);

    sellProductWithMutex(lipstickMoved, 3);
    sellProductWithMutex(lipstickMoved, 2);

    CosmeticProduct foundation("Foundation", "YSL", 20.99, 3, "Matte finish with SPF 15.");
    CosmeticProduct mascara("Mascara", "Maybelline", 15.50, 4, "Waterproof and volumizing.");

    std::vector<CosmeticProduct> productList = {lipstickMoved, foundation, mascara};
    BundleCosmeticProduct bundle("Beauty Bundle", "Sephora", 0.0, 1, "A curated beauty set.", productList, 20.0);
    bundle.displayBundleInfo();

    return 0;
}
