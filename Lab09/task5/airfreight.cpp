#include "airfreight.h"
#include <iostream>

airfreight::airfreight(std::string num, double w) : shipment(num, w) {}

double airfreight::estimatedeliverytime() {
    return weight < 50.0 ? 1.0 : 2.0;
}

void airfreight::showdetails() {
    std::cout << "air shipment [" << trackingnumber << "]\n";
    std::cout << "weight: " << weight << " kg\n";
    std::cout << "will arrive in " << estimatedeliverytime() << " days\n";
}