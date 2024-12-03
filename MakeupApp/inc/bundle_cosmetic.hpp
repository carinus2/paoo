#ifndef BUNDLE_COSMETIC_HPP
#define BUNDLE_COSMETIC_HPP

#include "makeup.hpp"
#include <vector>

class BundleCosmeticProduct : public CosmeticProduct {
private:
    std::vector<CosmeticProduct> products;
    double bundleDiscount;

public:
    BundleCosmeticProduct(std::string n, std::string b, double p, int q, const char* desc,
                          const std::vector<CosmeticProduct>& productList, double discount);

    virtual ~BundleCosmeticProduct();

    double calculateBundlePrice() const;
    void displayBundleInfo() const;
};

#endif // BUNDLE_COSMETIC_HPP
