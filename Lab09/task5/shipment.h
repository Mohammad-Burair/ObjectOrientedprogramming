#ifndef shipment_h
#define shipment_h
#include <string>

class shipment {
protected:
    std::string trackingnumber;
    double weight;

public:
    shipment(std::string num, double w) : trackingnumber(num), weight(w) {}
    virtual ~shipment() = default;
    virtual double estimatedeliverytime() = 0;
    virtual void showdetails() = 0;
};
#endif