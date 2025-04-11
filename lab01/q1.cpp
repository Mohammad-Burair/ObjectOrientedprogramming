/*
    Name : Mohammad Burair
    Roll No : 24K-0775
    Class : BCS-2C
    Desc : Program to register names for two events
*/

#include <iostream>
#include <string>

using namespace std;

string FirstEvent[5];
string SecondEvent[5];

void collectNames() {
    cout << "Registration for First Event:" << endl;
    cout << "Type 0 (zero) to stop registration" << endl;

    int i = 0;
    string name;
    while (i < 5) {
        cout << "Enter Name " << i + 1 << ":" << endl;
        cin >> name;
        if (name == "0") break;  
        FirstEvent[i] = name;
        i++;
    }

    cout << "Registration for Second Event:" << endl;
    cout << "Type 0 (zero) to stop registration" << endl;

    i = 0;
    while (i < 5) {
        cout << "Enter Name " << i + 1 << ":" << endl;
        cin >> name;
        if (name == "0") break;  
        SecondEvent[i] = name;
        i++;
    }
}

int main() {
    collectNames();
    return 0;
}
