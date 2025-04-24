#include <iostream>
#include "lecturecourse.h"
#include "labcourse.h"

int main() {
    course* thing1 = new lecturecourse("cs101", 3, 85.0, 90.0);
    course* thing2 = new labcourse("cs102", 4, 92.0, 88.0);

    std::cout << "school stuff\n";
    thing1->show_stuff();
    std::cout << "\n";
    thing2->show_stuff();

    delete thing1;
    delete thing2;

    return 0;
}