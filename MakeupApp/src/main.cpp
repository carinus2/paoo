#include "bundle_cosmetic.hpp"
#include <iostream>
#include <vector>
#include "makeup.hpp"

int main() {
    // Test 1: Constructor și Destructor
    std::cout << "Creating initial product...\n";
    CosmeticProduct lipstick("Lipstick", "MAC", 10.99, 5, "Bright red shade, long-lasting.");
    lipstick.displayProductInfo();

    // Test 2: Copy Constructor
    std::cout << "\nTesting Copy Constructor...\n";
    CosmeticProduct lipstickCopy = lipstick; // Copiere permisă și gestionată corect
    lipstickCopy.displayProductInfo();

    // Test 3: Move Constructor
    std::cout << "\nTesting Move Constructor...\n";
    CosmeticProduct lipstickMoved = std::move(lipstick); // Mutare permisă
    lipstickMoved.displayProductInfo();

    // Test 4: Sell Product
    std::cout << "\nTesting Product Selling...\n";
    lipstickMoved.sellProduct(3);
    lipstickMoved.sellProduct(3);

    // Test 6: Crearea unui BundleCosmeticProduct
    std::cout << "\nCreating a Bundle...\n";
    CosmeticProduct foundation("Foundation", "YSL", 20.99, 3, "Matte finish with SPF 15.");
    CosmeticProduct mascara("Mascara", "Maybelline", 15.50, 4, "Waterproof and volumizing.");

    std::vector<CosmeticProduct> productList = {lipstickMoved, foundation, mascara};

    BundleCosmeticProduct bundle(
        "Beauty Bundle", "Sephora", 0.0, 1, "A curated beauty set.",
        productList, 20.0
    );

    std::cout << "\nBundle Details:\n";
    bundle.displayBundleInfo();

    return 0;
}
