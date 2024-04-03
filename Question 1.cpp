#include <iostream>
#include <string>

using namespace std;

class Package {
protected:
    string senderName;
    string senderAddress;
    string senderCity;
    string senderState;
    string senderZIP;
    string recipientName;
    string recipientAddress;
    string recipientCity;
    string recipientState;
    string recipientZIP;
    double weight;
    double costPerOunce;

public:
    Package(const string& senderName, const string& senderAddress, const string& senderCity, const string& senderState, const string& senderZIP,
            const string& recipientName, const string& recipientAddress, const string& recipientCity, const string& recipientState, const string& recipientZIP,
            double weight, double costPerOunce)
        : senderName(senderName), senderAddress(senderAddress), senderCity(senderCity), senderState(senderState), senderZIP(senderZIP),
          recipientName(recipientName), recipientAddress(recipientAddress), recipientCity(recipientCity), recipientState(recipientState), recipientZIP(recipientZIP),
          weight(weight > 0 ? weight : 0), costPerOunce(costPerOunce > 0 ? costPerOunce : 0) {}

    virtual double calculateCost() const {
        return weight * costPerOunce;
    }
};

class TwoDayPackage : public Package {
private:
    double flatFee;

public:
    TwoDayPackage(const string& senderName, const string& senderAddress, const string& senderCity, const string& senderState, const string& senderZIP,
                  const string& recipientName, const string& recipientAddress, const string& recipientCity, const string& recipientState, const string& recipientZIP,
                  double weight, double costPerOunce, double flatFee)
        : Package(senderName, senderAddress, senderCity, senderState, senderZIP, recipientName, recipientAddress, recipientCity, recipientState, recipientZIP,
                  weight, costPerOunce), flatFee(flatFee) {}

    double calculateCost() const override {
        return Package::calculateCost() + flatFee;
    }
};

class OvernightPackage : public Package {
private:
    double additionalFeePerOunce;

public:
    OvernightPackage(const string& senderName, const string& senderAddress, const string& senderCity, const string& senderState, const string& senderZIP,
                     const string& recipientName, const string& recipientAddress, const string& recipientCity, const string& recipientState, const string& recipientZIP,
                     double weight, double costPerOunce, double additionalFeePerOunce)
        : Package(senderName, senderAddress, senderCity, senderState, senderZIP, recipientName, recipientAddress, recipientCity, recipientState, recipientZIP,
                  weight, costPerOunce), additionalFeePerOunce(additionalFeePerOunce) {}

    double calculateCost() const override {
        return Package::calculateCost() + additionalFeePerOunce * weight;
    }
};

int main() {
    // Creating Package objects
    Package package1("John Doe", "123 Main St", "Anytown", "NY", "12345", "Jane Smith", "456 Elm St", "Othertown", "CA", "67890", 10, 0.5);
    cout << "Standard Package Cost: $" << package1.calculateCost() << endl;

    // Creating TwoDayPackage objects
    TwoDayPackage twoDayPackage("John Doe", "123 Main St", "Anytown", "NY", "12345", "Jane Smith", "456 Elm St", "Othertown", "CA", "67890", 10, 0.5, 5);
    cout << "Two Day Package Cost: $" << twoDayPackage.calculateCost() << endl;

    // Creating OvernightPackage objects
    OvernightPackage overnightPackage("John Doe", "123 Main St", "Anytown", "NY", "12345", "Jane Smith", "456 Elm St", "Othertown", "CA", "67890", 10, 0.5, 2);
    cout << "Overnight Package Cost: $" << overnightPackage.calculateCost() << endl;

    return 0;
}
