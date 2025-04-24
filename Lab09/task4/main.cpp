#include <iostream>
#include "thermometer.h"
#include "barometer.h"

int main() {
    weathersensor* sensor1 = new thermometer();
    weathersensor* sensor2 = new barometer();

    std::cout << "weather\n";
    sensor1->readdata();
    sensor1->showreport();

    sensor2->readdata();
    sensor2->showreport();

    delete sensor1;
    delete sensor2;

    return 0;
}