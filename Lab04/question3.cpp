#include <iostream>
#include <string>

using namespace std;

class Car {
private:
    string brand;
    string model;
    double rentalPrice;
    bool isAvailable;

public:
    Car() : brand("unknown"), model("generic"), rentalPrice(0.0), isAvailable(true) {}

    Car(string b, string m, double p, bool a) : brand(b), model(m), rentalPrice(p), isAvailable(a) {}

    Car(const Car& other) {
        brand = other.brand;
        model = other.model;
        rentalPrice = other.rentalPrice;
        isAvailable = other.isAvailable;
        cout << "Copy constructor called. Car copied successfully." << endl;
    }

    ~Car() {
        cout << "Car object for " << brand << " " << model << " is being destroyed." << endl;
    }

    void updateDetails(const string& newBrand, const string& newModel, double newPrice) {
        brand = newBrand;
        model = newModel;
        rentalPrice = newPrice;
    }

    bool checkAvailability() const {
        return isAvailable;
    }

    void rentCar(int days) {
        if (!isAvailable) {
            cout << "Car is not available for rent." << endl;
            return;
        }

        double totalPrice = rentalPrice * days;
        if (days > 10) {
            totalPrice *= 0.9;
        } else if (days > 5) {
            totalPrice *= 0.95;
        }

        isAvailable = false;
        cout << "Car rented successfully for " << days << " days. Total price: " << totalPrice << endl;
    }

    void returnCar() {
        isAvailable = true;
        cout << "Car returned successfully." << endl;
    }

    void displayDetails() const {
        cout << "Brand: " << brand << ", Model: " << model << ", Price: " << rentalPrice << ", Available: " << (isAvailable ? "Yes" : "No") << endl;
    }
};

int main() {
    Car car1("toyota", "corolla", 50.0, true);
    cout << "original Car Details:" << endl;
    car1.displayDetails();

    Car car2 = car1;
    cout << " copied car  details:" << endl;
    car2.displayDetails();

    car1.updateDetails("Honda", "Civic", 60.0);
    cout << "original car details after modification:" << endl;
    car1.displayDetails();

   
    cout << "copied car details after original modification:" << endl;
    car2.displayDetails();

    return 0;
}