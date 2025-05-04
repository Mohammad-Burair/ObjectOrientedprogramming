/*
name: mohammad burair
roll number: 24k 0775
section: bcs-2c
date: 04-05-2025
description: this program demonstrates updating specific records in a configuration file.
*/

#include <iostream>
#include <fstream>
#include <string>

void update_config_file() {
    std::ofstream out_file("config.txt");
    out_file << "lhr01khi02isb03pes04mux05";
    out_file.close();

    std::fstream config_file("config.txt", std::ios::in | std::ios::out);
    if (!config_file) {
        return;
    }

    config_file.seekp(10, std::ios::beg);
    config_file << "xxxxx";
    config_file.close();
}

int main() {
    update_config_file();
    return 0;
}
