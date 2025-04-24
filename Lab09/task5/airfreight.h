#ifndef airfreight_h
#define airfreight_h
#include "shipment.h"

class airfreight : public shipment {
public:
    airfreight(std::string num, double w);
    double estimatedeliverytime() override;
    void showdetails() override;
};
#endif