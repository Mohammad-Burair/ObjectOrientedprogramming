/* 
name: mohammad burair
roll number: 24k 0775
section: bcs-1c
date: 11-05-2025
description: temperature conversion from celsius to fahrenheit with exception handling
*/

#include <iostream>
#include <stdexcept>

using namespace std;

class invalidtemperatureexception : public exception {};

template <typename t>
t converttofahrenheit(t celsius) {
    if (celsius < -273.15) {
        throw invalidtemperatureexception();
    }
    return celsius * 9.0 / 5.0 + 32;
}

int main() {
    try {
        cout << "attempting to convert -300c" << endl;
        double result = converttofahrenheit(-300.0);
        cout << "result: " << result << "f" << endl;
    }
    catch (const invalidtemperatureexception& e) {
        cerr << "caught invalidtemperatureexception  what(): " << e.what() << endl;
    }

    try {
        cout << "attempting to convert 0c..." << endl;
        double result = converttofahrenheit(0.0);
        cout << "result: " << result << "f" << endl;
    }
    catch (const invalidtemperatureexception& e) {
        cerr << "caught invalidtemperatureexception what(): " << e.what() << endl;
    }

    try {
        cout << "attempting to convert -273.15c" << endl;
        double result = converttofahrenheit(-273.15);
        cout << "result: " << result << "f" << endl;
    }
    catch (const invalidtemperatureexception& e) {
        cerr << "caught invalidtemperatureexception  what(): " << e.what() << endl;
    }

    return 0;
}
