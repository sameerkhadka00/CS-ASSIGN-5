#include <iostream>
#include <string>

using namespace std;

class Product {
protected:
    long barcode;
    string name;

public:
    Product(long barcode = 0, string name = "") : barcode(barcode), name(name) {}

    void setCode(long code) { barcode = code; }
    long getCode() const { return barcode; }

    virtual void scanner() const {
        cout << "Barcode: " << barcode << ", Name: " << name << endl;
    }

    virtual void printer() {
        cout << "Enter barcode: ";
        cin >> barcode;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
    }
};

class PrepackedFood : public Product {
protected:
    double unitPrice;

public:
    PrepackedFood(long barcode = 0, string name = "", double unitPrice = 0.0) : Product(barcode, name), unitPrice(unitPrice) {}

    void setUnitPrice(double price) { unitPrice = price; }
    double getUnitPrice() const { return unitPrice; }

    void scanner() const override {
        cout << "Barcode: " << barcode << ", Name: " << name << ", Unit Price: $" << unitPrice << endl;
    }

    void printer() override {
        Product::printer();
        cout << "Enter unit price: ";
        cin >> unitPrice;
    }
};

class FreshFood : public Product {
protected:
    double weight;
    double pricePerKilo;

public:
    FreshFood(long barcode = 0, string name = "", double weight = 0.0, double pricePerKilo = 0.0) : Product(barcode, name), weight(weight), pricePerKilo(pricePerKilo) {}

    void setWeight(double w) { weight = w; }
    double getWeight() const { return weight; }

    void setPricePerKilo(double price) { pricePerKilo = price; }
    double getPricePerKilo() const { return pricePerKilo; }

    void scanner() const override {
        cout << "Barcode: " << barcode << ", Name: " << name << ", Weight: " << weight << "kg, Price per kilo: $" << pricePerKilo << endl;
    }

    void printer() override {
        Product::printer();
        cout << "Enter weight (kg): ";
        cin >> weight;
        cout << "Enter price per kilo: ";
        cin >> pricePerKilo;
    }
};

int main() {
    // Test Product class
    Product product1(123456, "Product 1");
    Product product2;
    product2.printer();
    product1.scanner();
    product2.scanner();

    // Test PrepackedFood class
    PrepackedFood prepacked1(654321, "Prepacked Food 1", 2.5);
    PrepackedFood prepacked2;
    prepacked2.printer();
    prepacked1.scanner();
    prepacked2.scanner();

    // Test FreshFood class
    FreshFood fresh1(987654, "Fresh Food 1", 1.5, 3.0);
    FreshFood fresh2;
    fresh2.printer();
    fresh1.scanner();
    fresh2.scanner();

    return 0;
}
