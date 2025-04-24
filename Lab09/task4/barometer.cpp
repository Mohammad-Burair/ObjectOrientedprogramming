#include "barometer.h"
#include <iostream>
#include <cstdlib>

void barometer::readdata() {
    pressure = 1000.0f + (rand() % 20); // Random pressure between 1000-1020 hPa
}

void barometer::showreport() {
    std::cout << " air says: " << pressure << " hPa\n";
    if (pressure > 1015) std::cout << "  (sky is angry\n";
    else std::cout << "sky is happy\n";
}