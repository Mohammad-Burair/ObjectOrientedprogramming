#include "thermometer.h"
#include <iostream>
#include <cstdlib>

void thermometer::readdata() {
    temp = 20.0f + (rand() % 15); 
}

void thermometer::showreport() {
    std::cout << " ouchie-hot-thingy says: " << temp << "°C\n";
    if (temp > 30) std::cout << " pant pant... too hot\n";
    else std::cout << "  not too bad\n";
}