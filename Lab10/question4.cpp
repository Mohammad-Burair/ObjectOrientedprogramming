/*
name: mohammad burair
roll number: 24k 0775
section: bcs-2c
date: 04-05-2025
description: this program extracts vehicle data for autonomous cars and electric vehicles.
*/

#include <iostream>
#include <string>

class vehicle_data_parser {
private:
    std::string type;
    std::string extra_data;
    int vehicle_id;

public:
    vehicle_data_parser(std::string t, std::string ed, int id) : type(t), extra_data(ed), vehicle_id(id) {}

    void parse_and_print() {
        size_t colon_pos = extra_data.find(':');
        if (colon_pos == std::string::npos) {
            std::cout << "error: invalid data format for vehicle " << vehicle_id << std::endl;
            return;
        }

        std::string value_str = extra_data.substr(colon_pos + 1);
        while (!value_str.empty() && (value_str[0] == ' ' || value_str[0] == '\t')) {
            value_str.erase(0, 1);
        }

        if (type == "AutonomousCar") {
            try {
                float software_version = std::stof(value_str);
                std::cout << "vehicle id: " << vehicle_id << ", software version: " << software_version << std::endl;
            } catch (...) {
                std::cout << "error: invalid software version for vehicle " << vehicle_id << std::endl;
            }
        }
        else if (type == "ElectricVehicle") {
            try {
                int battery_capacity = std::stoi(value_str);
                std::cout << "vehicle id: " << vehicle_id << ", battery capacity: " << battery_capacity << " kWh" << std::endl;
            } catch (...) {
                std::cout << "error: invalid battery capacity for vehicle " << vehicle_id << std::endl;
            }
        }
        else {
            std::cout << "unknown vehicle type for id: " << vehicle_id << std::endl;
        }
    }
};

int main() {
    vehicle_data_parser ali_car("AutonomousCar", "Software Version:3.2", 101);
    vehicle_data_parser fatima_ev("ElectricVehicle", "Battery Capacity:64", 102);
    vehicle_data_parser saad_car("AutonomousCar", "Software Version:4.0", 103);
    vehicle_data_parser ayesha_ev("ElectricVehicle", "Battery Capacity:82", 104);
    vehicle_data_parser burair_car("UnknownType", "Some Data:123", 105);

    ali_car.parse_and_print();
    fatima_ev.parse_and_print();
    saad_car.parse_and_print();
    ayesha_ev.parse_and_print();
    burair_car.parse_and_print();

    return 0;
}
