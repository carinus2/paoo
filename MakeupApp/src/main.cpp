#include <bundle_cosmetic.hpp>
#include <iostream>
#include <vector>
#include <makeup.hpp>

int main() {
    // Test 1: Constructor și Destructor
    std::cout << "Creating initial product...\n";
    CosmeticProduct lipstick("Lipstick", "MAC", 10.99, 5, "Bright red shade, long-lasting.");
    lipstick.displayProductInfo();

    // Test 2: Copy Constructor
    std::cout << "\nTesting Copy Constructor...\n";
    // CosmeticProduct lipstickCopy = lipstick; // Comentat pentru că Copy Constructor este = delete

    // Test 3: Move Constructor
    std::cout << "\nTesting Move Constructor...\n";
    // CosmeticProduct lipstickMoved = std::move(lipstick); // Comentat pentru că Move Constructor este = delete

    // Test 4: Sell Product
    std::cout << "\nTesting Product Selling...\n";
    lipstick.sellProduct(3); // Vindem 3 unități
    lipstick.sellProduct(3); // Încercăm să vindem mai multe decât sunt în stoc

    // Test 6: Crearea unui BundleCosmeticProduct
    std::cout << "\nCreating a Bundle...\n";
    CosmeticProduct foundation("Foundation", "YSL", 20.99, 3, "Matte finish with SPF 15.");
    CosmeticProduct mascara("Mascara", "Maybelline", 15.50, 4, "Waterproof and volumizing.");

    // Vectorul de produse pentru bundle
    std::vector<CosmeticProduct> productList = {lipstick, foundation, mascara};

    // Cream un BundleCosmeticProduct folosind constructorul
    BundleCosmeticProduct bundle(
        "Beauty Bundle", "Sephora", 0.0, 1, "A curated beauty set.",
        productList, 20.0 // Discount de 20%
    );

    // Afișăm informațiile despre bundle
    std::cout << "\nBundle Details:\n";
    bundle.displayBundleInfo();

    // Test 7: Move Constructor pentru BundleCosmeticProduct
    std::cout << "\nTesting Move Constructor for BundleCosmeticProduct...\n";
    // BundleCosmeticProduct movedBundle = std::move(bundle); // Comentat pentru că Move Constructor este = delete

    // Test 8: Copy Constructor pentru BundleCosmeticProduct
    std::cout << "\nTesting Copy Constructor for BundleCosmeticProduct...\n";
    // BundleCosmeticProduct copiedBundle = movedBundle; // Comentat pentru că Copy Constructor este = delete

    CosmeticProduct* basePtr = new BundleCosmeticProduct(
        "Beauty Bundle 2", "Sephora", 0.0, 1, "A curated beauty set.",
        productList, 20.0
    );

    basePtr->displayProductInfo();

    // Cleanup
    delete basePtr;

    return 0;
}
