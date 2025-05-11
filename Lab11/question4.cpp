/* 
name: mohammad burair
roll number: 24k 0775
section: bcs-1c
date: 11-05-2025
description: database connection and query execution with exception handling
*/

#include <iostream>
#include <stdexcept>
#include <string>

using namespace std;

class databaseexception : public exception {
public:
    const char* what() const noexcept override {
        return "a database error occurred.";
    }
};

class connectionfailedexception : public databaseexception {};
class querytimeoutexception : public databaseexception {};

template <typename t>
class databaseconnector {
public:
    void connect(const string& dbname) {
        if (dbname == "invalid_db") {
            throw connectionfailedexception();
        }
        else if (dbname == "slow_db") {
            throw databaseexception();
        }
    }

    void executequery(const string& query) {
        if (query == "timeout_query") {
            throw querytimeoutexception();
        }
    }
};

int main() {
    databaseconnector<int> connector;

    try {
        cout << "attempting to connect to invalid_db..." << endl;
        connector.connect("invalid_db");
    }
    catch (const connectionfailedexception& e) {
        cerr << "caught connectionfailedexception - what(): " << e.what() << endl;
    }

    try {
        cout << "attempting to connect to slow_db" << endl;
        connector.connect("slow_db");
    }
    catch (const databaseexception& e) {
        cerr << "caught a general databaseexception  what(): " << e.what() << endl;
    }

    try {
        cout << "attempting to execute timeout_query" << endl;
        connector.executequery("timeout_query");
    }
    catch (const querytimeoutexception& e) {
        cerr << "caught querytimeoutexception  what(): " << e.what() << endl;
    }

    return 0;
}
