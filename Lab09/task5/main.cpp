#include <iostream>
#include "airfreight.h"
#include "groundshipment.h"

int main() {
    shipment* parcel1 = new airfreight("fedex123", 45.5);
    shipment* parcel2 = new groundshipment("ups456", 75.2);

    std::cout << "--- shipment tracker ---\n";
    parcel1->showdetails();
    std::cout << "\n";
    parcel2->showdetails();

    delete parcel1;
    delete parcel2;

    return 0;
}