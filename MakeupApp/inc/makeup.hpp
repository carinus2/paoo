#define MAKEUP_HPP

#include <string>

class CosmeticProduct {
private:
    std::string name;
    std::string brand;
    double price;
    int quantity;
    char* description;

public:

    CosmeticProduct(std::string n, std::string b, double p, int q, const char* desc);

    ~CosmeticProduct();

    CosmeticProduct& operator=(const CosmeticProduct& other);

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
};