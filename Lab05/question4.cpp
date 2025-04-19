#include <iostream>
using namespace std;

class AlarmSystem {
private:
    string securityLevel;

public:
    AlarmSystem(string level) : securityLevel(level) {
        cout << "AlarmSystem created with security level: " << securityLevel << endl;
    }



    string getSecurityLevel() const {
        return securityLevel;
    }
};

class SmartHome {
private:
    string homeName;
    AlarmSystem alarmSystem; 

public:
    SmartHome(string name, string securityLevel)
        : homeName(name), alarmSystem(securityLevel) {
        cout << "smarthomme '" << homeName << "' created." << endl;
    }

   

    void displayDetails() const {
        cout << "Smarthome name: " << homeName << endl;
        cout << "alarm system security level: " << alarmSystem.getSecurityLevel() << endl;
    }
};

int main() {
    SmartHome home("mysmarthome", "goodd");
    home.displayDetails();

    return 0;
}