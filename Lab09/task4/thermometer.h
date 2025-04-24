#ifndef thermometer_h
#define thermometer_h
#include "weathersensor.h"

class thermometer : public weathersensor {
private:
    float temp;

public:
    thermometer() : temp(0.0f) {}
    void readdata() override;
    void showreport() override;
};
#endif