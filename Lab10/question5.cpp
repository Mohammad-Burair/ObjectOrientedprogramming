/*
name: mohammad burair
roll number: 24k 0775
section: bcs-2c
date: 04-05-2025
description: this program handles vehicle data parsing for autonomous cars, electric vehicles, and hybrid trucks.
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
        if (type == "AutonomousCar") {
            size_t colon_pos = extra_data.find(':');
            if (colon_pos != std::string::npos) {
                std::string version_str = extra_data.substr(colon_pos + 1);
                float software_version = std::stof(version_str);
                std::cout << "vehicle id: " << vehicle_id << ", software version: " << software_version << std::endl;
            } else {
                std::cout << "error: invalid data format for autonomous car " << vehicle_id << std::endl;
            }
        }
        else if (type == "ElectricVehicle") {
            size_t colon_pos = extra_data.find(':');
            if (colon_pos != std::string::npos) {
                std::string capacity_str = extra_data.substr(colon_pos + 1);
                int battery_capacity = std::stoi(capacity_str);
                std::cout << "vehicle id: " << vehicle_id << ", battery capacity: " << battery_capacity << " kWh" << std::endl;
            } else {
                std::cout << "error: invalid data format for electric vehicle " << vehicle_id << std::endl;
            }
        }
        else if (type == "HybridTruck") {
            size_t cargo_colon = extra_data.find(':');
            size_t pipe_pos = extra_data.find('|');
            size_t battery_colon = extra_data.find(':', pipe_pos);

            if (cargo_colon != std::string::npos && pipe_pos != std::string::npos && battery_colon != std::string::npos) {
                std::string cargo_str = extra_data.substr(cargo_colon + 1, pipe_pos - cargo_colon - 1);
                std::string battery_str = extra_data.substr(battery_colon + 1);
                
                int cargo_capacity = std::stoi(cargo_str);
                int battery_capacity = std::stoi(battery_str);
                
                std::cout << "vehicle id: " << vehicle_id << ", cargo capacity: " << cargo_capacity 
                          << " kg, battery capacity: " << battery_capacity << " kWh" << std::endl;
            } else {
                std::cout << "error: invalid data format for hybrid truck " << vehicle_id << std::endl;
            }
        }
        else {
            std::cout << "error: unknown vehicle type '" << type << "' for id: " << vehicle_id << std::endl;
        }
    }
};

int main() {
    vehicle_data_parser ali_car("AutonomousCar", "Software Version:3.2.1", 101);
    vehicle_data_parser fatima_ev("ElectricVehicle", "Battery Capacity:64", 102);
    vehicle_data_parser saad_ht("HybridTruck", "Cargo:5000|Battery:75", 103);
    vehicle_data_parser ayesha_ht("HybridTruck", "Cargo:3500|Battery:60", 104);
    vehicle_data_parser burair_unknown("FlyingCar", "Wingspan:10", 105);

    ali_car.parse_and_print();
    fatima_ev.parse_and_print();
    saad_ht.parse_and_print();
    ayesha_ht.parse_and_print();
    burair_unknown.parse_and_print();

    return 0;
}
