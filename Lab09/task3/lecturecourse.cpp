#include "lecturecourse.h"
#include <iostream>

lecturecourse::lecturecourse(std::string code, int creds, double mid, double final)
    : course(code, creds), mid_score(mid), final_score(final) {}

double lecturecourse::calculate_grade() {
    return (mid_score * 0.4) + (final_score * 0.6);
}

void lecturecourse::show_stuff() {
    std::cout << "boring talky class: " << course_code << " (" << creds << " points)\n";
    std::cout << "half-test: " << mid_score << ", big scary test: " << final_score << "\n";
    std::cout << "your number: " << calculate_grade() << " hope its good\n";
}