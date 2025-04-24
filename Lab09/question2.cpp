#include <iostream>
using namespace std;

class menuitem {
protected:
    string dishname;
    double price;

public:
    menuitem(string n, double p) : dishname(n), price(p) {}
    virtual void showdetails() = 0;
    virtual void prepare() = 0;
};

class appetizer : public menuitem {
public:
    appetizer(string n, double p) : menuitem(n, p) {}

    void showdetails() override {
        cout << "appetizer: " << dishname << " - $" << price << endl;
    }

    void prepare() override {
        cout << "preparing appetizer: " << dishname << endl;
    }
};

class maincourse : public menuitem {
public:
    maincourse(string n, double p) : menuitem(n, p) {}

    void showdetails() override {
        cout << "main course: " << dishname << " - $" << price << endl;
    }

    void prepare() override {
        cout << "cooking main course: " << dishname << endl;
    }
};

int main() {
    menuitem* m1 = new appetizer("chicken strips", 4.99);
    menuitem* m2 = new maincourse("alfredo pasta", 22.50);

    m1->showdetails();
    m1->prepare();
    cout << "\n"<<endl;

    m2->showdetails();
    m2->prepare();

    delete m1;
    delete m2;

    return 0;
}