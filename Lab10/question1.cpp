/* 
Name: Mohammad Burair
Roll No: 24k-0775
Section: BCS-2C
Date: 4-5-2025
Description: this program reads the vehicles.txt file line by line using object oriented approach
*/

#include <iostream>
#include <fstream>
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

    void read_file() {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
    }

    void close_file() {
        if (file.is_open()) {
            file.close();
        }
    }
};

int main() {
    vehicle_reader ahsan;

    ahsan.open_file("vehicles.txt");
    ahsan.read_file();
    ahsan.close_file();

    return 0;
}
