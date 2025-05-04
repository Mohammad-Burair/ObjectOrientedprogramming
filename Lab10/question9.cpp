/*
name: mohammad burair
roll number: 24k 0775
section: bcs-2c
date: 04-05-2025
description: this program demonstrates reading positions in a log file using tellg().
*/

#include <iostream>
#include <fstream>
#include <string>

void read_log_file() {
    std::ofstream create_file("large_log.txt");
    create_file << "server1:lahore:online\n"
                << "server2:karachi:offline\n"
                << "server3:islamabad:online\n"
                << "server4:peshawar:maintenance\n"
                << "server5:multan:offline\n";
    create_file.close();

    std::ifstream log_file("large_log.txt");
    if (!log_file) {
        return;
    }

    char buffer[11];
    std::streampos pos;

    log_file.read(buffer, 10);
    buffer[10] = '\0';
    pos = log_file.tellg();

    log_file.read(buffer, 10);
    buffer[10] = '\0';
    pos = log_file.tellg();

    std::string line;
    std::getline(log_file, line);
    pos = log_file.tellg();

    std::getline(log_file, line);
    pos = log_file.tellg();

    log_file.close();
}

int main() {
    read_log_file();
    return 0;
}
