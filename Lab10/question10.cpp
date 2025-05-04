/*
name: mohammad burair
roll number: 24k 0775
section: bcs-2c
date: 04-05-2025
description: this program demonstrates seeking to specific records in a file.
*/

#include <iostream>
#include <fstream>
#include <string>

void access_specific_record() {
    std::ofstream create_file("data_records.txt");
    create_file << "lahore_population: 98765\n"
                << "karachi_population: 4321\n"
                << "islamabad_population: 55555\n"
                << "peshawar_population: 8888\n"
                << "multan_population: 123456\n";
    create_file.close();

    std::ifstream data_file("data_records.txt");
    if (!data_file) {
        return;
    }

    const int offset_to_third_record = 41;
    data_file.seekg(offset_to_third_record, std::ios::beg);

    std::string record;
    std::getline(data_file, record);

    std::streampos pos = data_file.tellg();

    data_file.close();
}

int main() {
    access_specific_record();
    return 0;
}
