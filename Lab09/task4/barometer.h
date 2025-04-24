#ifndef barometer_h
#define barometer_h
#include "weathersensor.h"

class barometer : public weathersensor {
private:
    float pressure;

public:
    barometer() : pressure(0.0f) {}
    void readdata() override;
    void showreport() override;
};
#endif