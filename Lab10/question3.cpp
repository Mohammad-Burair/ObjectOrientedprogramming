/* 
Name: Mohammad Burair
Roll No: 24k-0775
Section: BCS-2C
Date: 4-5-2025
Description: this program reads the vehicles.txt file, splits each line into parts, and converts year to integer using object oriented approach
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

class vehicle_reader {
private:
    ifstream file;
public:
    void open_file(const string& filename) {
        file.open(filename);
        if (!file.is_open()) {
            cout << "unable to open the file" << endl;
            exit(1);
        }
    }

    void read_and_parse_file() {
        string line;
        while (getline(file, line)) {
            istringstream iss(line);
            string type, id, name, year_str, extra_data, certification;

            getline(iss, type, ',');
            getline(iss, id, ',');
            getline(iss, name, ',');
            getline(iss, year_str, ',');
            getline(iss, extra_data, ',');
            getline(iss, certification, ',');

            cout << "type: " << type << endl;
            cout << "id: " << id << endl;
            cout << "name: " << name << endl;
            cout << "year (string): " << year_str << endl;
            cout << "extra data: " << extra_data << endl;
            cout << "certification: " << certification << endl;

            int year_int = stoi(year_str);
            cout << "year (integer): " << year_int << endl;

            cout << endl;
        }
    }

    void close_file() {
        if (file.is_open()) {
            file.close();
        }
    }
};

int main() {
    vehicle_reader zohaib;

    zohaib.open_file("vehicles.txt");
    zohaib.read_and_parse_file();
    zohaib.close_file();

    return 0;
}
