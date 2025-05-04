/*
name: mohammad burair
roll number: 24k 0775
section: bcs-2c
date: 04-05-2025
description: this program demonstrates file position tracking for sensor data logging.
*/

#include <iostream>
#include <fstream>
#include <string>

void log_sensor_data() {
    std::ofstream log_file("sensor_log.txt");
    if (!log_file) {
        return;
    }

    std::streampos pos = log_file.tellp();

    log_file << "lahore_temp:32.5C humidity:65%\n";
    pos = log_file.tellp();

    log_file << "karachi_temp:35.2C humidity:80%\n";
    pos = log_file.tellp();

    log_file << "\nislamabad_temp:28.7C humidity:60%\n";
    pos = log_file.tellp();

    log_file.close();
}

int main() {
    log_sensor_data();
    return 0;
}
