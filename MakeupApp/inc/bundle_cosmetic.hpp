#ifndef BUNDLE_COSMETIC_HPP
#define BUNDLE_COSMETIC_HPP

#include "makeup.hpp"
#include <vector>
#include <string>

class BundleCosmeticProduct : public CosmeticProduct {
private:
    std::vector<CosmeticProduct> products; // Lista produselor din pachet
    double bundleDiscount;                 // Discount pentru pachet

public:
    // Constructor
    BundleCosmeticProduct(std::string n, std::string b, double p, int q, const char* desc,
                          const std::vector<CosmeticProduct>& products, double discount);

    // Metode adiționale
    double calculateBundlePrice() const; // Calculează prețul total redus al pachetului
    void displayBundleInfo() const;      // Afișează informațiile despre pachet
};

#endif // BUNDLE_COSMETIC_HPP
