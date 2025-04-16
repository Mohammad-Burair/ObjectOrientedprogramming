#include <iostream>
#include <string>
using namespace std;

class cityaqi {
private:
    int aqidata[28];
    int totalaqi;
    int highestaqi;
    int lowestaqi;
    bool criticaldays[28];

public:
    cityaqi() {
        totalaqi = 0;
        highestaqi = -999999;
        lowestaqi = 999999;
        for (int i = 0; i < 28; i++) {
            criticaldays[i] = false;
        }
    }

    void inputdata() {
        for (int i = 0; i < 28; i++) {
            cout << "Day " << i + 1 << ": ";
            cin >> aqidata[i];
            totalaqi += aqidata[i];
            
            if (aqidata[i] > highestaqi) highestaqi = aqidata[i];
            if (aqidata[i] < lowestaqi) lowestaqi = aqidata[i];
            if (aqidata[i] > 150) criticaldays[i] = true;
        }
    }

    float getweeklyavg(int week) {
        float sum = 0;
        for (int i = (week - 1) * 7; i < week * 7; i++) {
            sum += aqidata[i];
        }
        return sum / 7.0;
    }

    void printcriticaldays(int week) {
        bool found = false;
        for (int i = (week - 1) * 7; i < week * 7; i++) {
            if (criticaldays[i]) {
                cout << "Day " << i + 1 << " ";
                found = true;
            }
        }
        if (!found) cout << "None";
    }

    void visualizeaqi(int week) {
        for (int i = (week - 1) * 7; i < week * 7; i++) {
            cout << string(aqidata[i] / 50, '*') << " ";
        }
    }

    int gethighestaqi() { return highestaqi; }
    int getlowestaqi() { return lowestaqi; }
};

int main() {
    cityaqi cities[4];

    for (int i = 0; i < 4; i++) {
        cout << "\nCity " << i + 1 << ":\n";
        cities[i].inputdata();
    }

    int mostpolluted = 0;
    cout << "\nAverage AQI weak 1:\n";
    for (int i = 0; i < 4; i++) {
        float avg = cities[i].getweeklyavg(1);
        cout << "City " << i + 1 << ": " << avg << endl;
        if (avg > cities[mostpolluted].getweeklyavg(1)) mostpolluted = i;
    }
    cout << "\nMost polluted city:City " << mostpolluted + 1 << endl;

    cout << "\nCritical Pollution Days (Week 1):\n";
    for (int i = 0; i < 4; i++) {
        cout << "City " << i + 1 << ": ";
        cities[i].printcriticaldays(1);
        cout << endl;
    }

    cout << "\nAQI visualization Week 1, * = 50 AQI:\n";
    for (int i = 0; i < 4; i++) {
        cout << "City " << i + 1 << ": ";
        cities[i].visualizeaqi(1);
        cout << endl;
    }

    int mostimproved =0;
    float highestimprovement = cities[0].getweeklyavg(1) - cities[0].getweeklyavg(4);
    for (int i = 1; i < 4; i++) {
        float improvement = cities[i].getweeklyavg(1) - cities[i].getweeklyavg(4);
        if (improvement > highestimprovement) {
            highestimprovement =  improvement;
            mostimproved = i;
        }
    }
    cout << "\nmsost improved city:  City " << mostimproved + 1 << endl;

    return 0;
}