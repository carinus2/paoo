// src/main.cpp
#include "makeup.hpp"
#include <iostream>

int main() {

    CosmeticProduct lipstick("Lipstick", "MAC", 10.99, 5, "Bright red shade, long-lasting.");
    CosmeticProduct foundation("Foundation", "YSL", 20.99, 3, "Matte finish with SPF 15.");

    std::cout << "Initial Products:\n";
    std::cout << "Product 1 - Name: " << lipstick.getName() << ", Brand: " << lipstick.getBrand()
              << ", Price: $" << lipstick.getPrice() << ", Quantity: " << lipstick.getQuantity()
              << ", Description: " << lipstick.getDescription() << "\n";

    std::cout << "Product 2 - Name: " << foundation.getName() << ", Brand: " << foundation.getBrand()
              << ", Price: $" << foundation.getPrice() << ", Quantity: " << foundation.getQuantity()
              << ", Description: " << foundation.getDescription() << "\n";

    foundation = lipstick;

    std::cout << "\nAfter Assignment (foundation = lipstick):\n";
    std::cout << "Product 2 - Name: " << foundation.getName() << ", Brand: " << foundation.getBrand()
              << ", Price: $" << foundation.getPrice() << ", Quantity: " << foundation.getQuantity()
              << ", Description: " << foundation.getDescription() << "\n";

    return 0;
}
