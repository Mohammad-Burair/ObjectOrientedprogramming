#ifndef weathersensor_h
#define weathersensor_h
#include <string>

class weathersensor {
public:
    virtual ~weathersensor() = default;
    virtual void readdata() = 0;
    virtual void showreport() = 0;
};
#endif