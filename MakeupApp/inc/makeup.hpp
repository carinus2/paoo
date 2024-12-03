#ifndef MAKEUP_HPP
#define MAKEUP_HPP

#include <string>
#include <memory>

class CosmeticProduct {
private:
    std::string name;
    std::string brand;
    double price;
    int quantity;
    std::unique_ptr<char[]> description;

public:
    // Constructor
    CosmeticProduct(std::string n, std::string b, double p, int q, const char* desc);

    // Destructor
    virtual ~CosmeticProduct();

    // Constructor de copiere
    CosmeticProduct(const CosmeticProduct& other);

    // Operator de copiere
    CosmeticProduct& operator=(const CosmeticProduct& other);

    // Constructor de mutare
    CosmeticProduct(CosmeticProduct&& other) noexcept;

    // Operator de mutare
    CosmeticProduct& operator=(CosmeticProduct&& other) noexcept;

    // Getters
    std::string getName() const;
    std::string getBrand() const;
    double getPrice() const;
    int getQuantity() const;
    const char* getDescription() const;

    // Setters
    void setName(const std::string& n);
    void setBrand(const std::string& b);
    void setPrice(double p);
    void setQuantity(int q);
    void setDescription(const char* desc);

    // Funcții
    bool sellProduct(int amount);
    virtual void displayProductInfo() const;
};

#endif // MAKEUP_HPP
