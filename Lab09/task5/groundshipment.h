#ifndef groundshipment_h
#define groundshipment_h
#include "shipment.h"

class groundshipment : public shipment {
public:
    groundshipment(std::string num, double w);
    double estimatedeliverytime() override;
    void showdetails() override;
};
#endif