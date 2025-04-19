#include <iostream>
using namespace std;

class Product {
public:
    int id;
    string name;
    int quantity;

    Product(int i, string n, int q) : id(i), name(n), quantity(q) {}

    void displayDetails() {
        cout << "ID: " << id << ", Name: " << name << ", Quantity: " << quantity << endl;
    }
};

class Warehouse {
private:
    Product* products[100]; 
    int count;

public:
    Warehouse() : count(0) {}

    void addProduct(int id, string name, int quantity) {
        if (count < 100) {
            products[count++] = new Product(id, name, quantity);
        }
    }

    void sortProductsByName() {
        for (int i = 0; i < count - 1; ++i) {
            for (int j = i + 1; j < count; ++j) {
                if (products[i]->name > products[j]->name) {
                    Product* temp = products[i];
                    products[i] = products[j];
                    products[j] = temp;
                }
            }
        }
    }

    void searchProductById(int id) {
        for (int i = 0; i < count; ++i) {
            if (products[i]->id == id) {
                products[i]->displayDetails();
                return;
            }
        }
        cout << "Product with ID " << id << " not found." << endl;
    }

    void displayInventory() {
        for (int i = 0; i < count; ++i) {
            products[i]->displayDetails();
        }
    }

    ~Warehouse() {
        for (int i = 0; i < count; ++i) {
            delete products[i];
        }
    }
};

int main() {
    Warehouse warehouse;
    warehouse.addProduct(3, "chair", 50);
    warehouse.addProduct(1, "table", 30);
    warehouse.addProduct(2, "lamp", 20);

    cout << "inventory before sorting:" << endl;
    warehouse.displayInventory();

    warehouse.sortProductsByName();
    cout << "inventory after sorting by name:" << endl;
    warehouse.displayInventory();

    cout << "searching for product with ID 2:" << endl;
    warehouse.searchProductById(2);

    return 0;
}