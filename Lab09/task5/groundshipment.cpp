#include "groundshipment.h"
#include <iostream>

groundshipment::groundshipment(std::string num, double w) : shipment(num, w) {}

double groundshipment::estimatedeliverytime() {
    return weight < 20.0 ? 3.0 : 5.0; 
}

void groundshipment::showdetails() {
    std::cout << "ground shipment [" << trackingnumber << "]\n";
    std::cout << "weight: " << weight << " kg\n";
    std::cout << "will arrive in " << estimatedeliverytime() << " days (slow truck)\n";
}