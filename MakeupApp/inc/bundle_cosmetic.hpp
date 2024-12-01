#ifndef BUNDLE_COSMETIC_HPP
#define BUNDLE_COSMETIC_HPP

#include "makeup.hpp"
#include <vector>
#include <string>


class BundleCosmeticProduct : public CosmeticProduct {
public:
    // Constructori existenți
    BundleCosmeticProduct(std::string n, std::string b, double p, int q, const char* desc,
                          const std::vector<CosmeticProduct>& productList, double discount);
    ~BundleCosmeticProduct();

    // Constructor de copiere și operator de copiere dezactivate
    BundleCosmeticProduct(const BundleCosmeticProduct&) = delete;
    BundleCosmeticProduct& operator=(const BundleCosmeticProduct&) = delete;

    // Constructor de mutare și operator de mutare dezactivate
    BundleCosmeticProduct(BundleCosmeticProduct&&) = delete;
    BundleCosmeticProduct& operator=(BundleCosmeticProduct&&) = delete;

    // Funcții
    double calculateBundlePrice() const;
    void displayBundleInfo() const;

private:
    std::vector<CosmeticProduct> products;
    double bundleDiscount;
};

#endif // BUNDLE_COSMETIC_HPP
