#include <iostream>
#include <string>
using namespace std;

class Device {
protected:
    string deviceID;
    string deviceName;
    bool status;
public:
    Device(string id, string name) {
        deviceID = id;
        deviceName = name;
        status = false;
    }
    virtual void turnOn() {
        status = true;
    }
    virtual void turnOff() {
        status = false;
    }
    virtual string getStatus() {
        if(status) return "ON";
        else return "OFF";
    }
    virtual void displayInfo() {
        cout << "Device ID: " << deviceID << endl;
        cout << "Name: " << deviceName << endl;
        cout << "Status: " << getStatus() << endl;
    }
};

class Light : public Device {
    int brightnessLevel;
    string colorMode;
public:
    Light(string id, string name) : Device(id, name) {
        brightnessLevel = 50;
        colorMode = "Warm";
    }
    void displayInfo() {
        Device::displayInfo();
        cout << "Brightness Level: " << brightnessLevel << endl;
        cout << "Color Mode: " << colorMode << endl;
    }
};

class Thermostat : public Device {
    float temperature;
    string mode;
    float targetTemperature;
public:
    Thermostat(string id, string name) : Device(id, name) {
        temperature = 22.0;
        mode = "Cooling";
        targetTemperature = 22.0;
    }
    string getStatus() {
        return Device::getStatus() + " (Current Temp: " + to_string(temperature) + ")";
    }
};

class SecurityCamera : public Device {
    string resolution;
    bool recordingStatus;
    bool nightVisionEnabled;
public:
    SecurityCamera(string id, string name) : Device(id, name) {
        resolution = "1080p";
        recordingStatus = false;
        nightVisionEnabled = false;
    }
    void turnOn() {
        Device::turnOn();
        recordingStatus = true;
    }
};

class SmartPlug : public Device {
    float powerConsumption;
    int timeSetting;
public:
    SmartPlug(string id, string name) : Device(id, name) {
        powerConsumption = 0;
        timeSetting = 0;
    }
    void turnOff() {
        Device::turnOff();
    }
};

int main() {
    Device* d1 = new Light("L1", "Living Room Light");
    Device* d2 = new Thermostat("T1", "Living Room Thermostat");
    Device* d3 = new SecurityCamera("C1", "Front Door Camera");
    Device* d4 = new SmartPlug("P1", "Coffee Maker Plug");

    d1->turnOn();
    d2->turnOn();
    d3->turnOn();
    d4->turnOn();

    d1->displayInfo();
    d2->displayInfo();
    d3->displayInfo();
    d4->displayInfo();

    delete d1;
    delete d2;
    delete d3;
    delete d4;

    return 0;
}