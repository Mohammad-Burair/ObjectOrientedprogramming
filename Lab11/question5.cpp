/* 
name: mohammad burair
roll number: 24k 0775
section: bcs-1c
date: 11-05-2025
description: inventory stock management with exception handling
*/

#include <iostream>
#include <stdexcept>

using namespace std;

class negativestockexception : public exception {};
class overcapacityexception : public exception {};

template <typename t>
class inventoryitem {
private:
    t stock;
    t maxcapacity;

public:
    inventoryitem(t max) : maxcapacity(max), stock(0) {}

    void setstock(t newstock) {
        if (newstock < 0) {
            throw negativestockexception();
        }
        if (newstock > maxcapacity) {
            throw overcapacityexception();
        }
        stock = newstock;
    }

    t getstock() const {
        return stock;
    }
};

int main() {
    inventoryitem<int> item(100);

    try {
        cout << "attempting to set stock to -5" << endl;
        item.setstock(-5);
    }
    catch (const negativestockexception& e) {
        cerr << "caught negativestockexception - what(): " << e.what() << endl;
    }

    try {
        cout << "attempting to set stock to 120 (max 100)" << endl;
        item.setstock(120);
    }
    catch (const overcapacityexception& e) {
        cerr << "caught overcapacityexception - what(): " << e.what() << endl;
    }

    try {
        cout << "setting valid stock (50)" << endl;
        item.setstock(50);
        cout << "current stock: " << item.getstock() << endl;
    }
    catch (const exception& e) {
        cerr << "caught exception: " << e.what() << endl;
    }

    return 0;
}
