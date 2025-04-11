#include <iostream>
#include <string>
using namespace std;

class car {
private:
    string model;
    double price;

public:
    car(string m, double p) : model(m), price(p) {}

    friend class inventorymanager;
    friend void compareprice(const car& c1, const car& c2);
};

class inventorymanager {
public:
    void updateprice(car& c, double newprice) {
        c.price = newprice;
    }

    void displaydetails(const car& c) {
        cout << "model: " << c.model << endl;
        cout << "price: " << c.price << endl;
    }
};

void compareprice(const car& c1, const car& c2) {
    if (c1.price > c2.price) {
        cout << c1.model << " is more expensive than " << c2.model << endl;
    } else if (c1.price < c2.price) {
        cout << c2.model << " is more expensive than " << c1.model << endl;
    } else {
        cout << "both cars have the same price" << endl;
    }
}

int main() {
    car c1("corolla", 2500000);
    car c2("civic", 3000000);

    inventorymanager mgr;

    cout << "mohammad burair - 24k-0775" << endl;
    cout << "\ninitial car details:" << endl;
    mgr.displaydetails(c1);
    mgr.displaydetails(c2);

    compareprice(c1, c2);

    mgr.updateprice(c1, 3200000);
    cout << "\nafter updating price of corolla:" << endl;
    mgr.displaydetails(c1);

    compareprice(c1, c2);

    return 0;
}