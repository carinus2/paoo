// src/main.cpp
#include "makeup.hpp"
#include <iostream>

int main() {

    CosmeticProduct lipstick("Lipstick", "MAC", 10.99, 5, "Bright red shade, long-lasting.");
    CosmeticProduct foundation("Foundation", "YSL", 20.99, 3, "Matte finish with SPF 15.");

    std::cout << "Initial Products:\n";
    lipstick.displayProductInfo();
    foundation.displayProductInfo();

    std::cout << "Apply overloading here:\n";
    foundation = lipstick;

    std::cout << "\nAfter Assignment (foundation = lipstick):\n";
    foundation.displayProductInfo();

    lipstick.sellProduct(3);//vindem 3 produse
    lipstick.sellProduct(3);//incercam sa vedem daca apare ca e pe stoc

    return 0;
}
