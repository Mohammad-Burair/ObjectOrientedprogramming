#include "labcourse.h"
#include <iostream>

labcourse::labcourse(std::string code, int creds, double lab, double project)
    : course(code, creds), lab_score(lab), project_score(project) {}

double labcourse::calculate_grade() {
    return (lab_score * 0.3) + (project_score * 0.7);
}

void labcourse::show_stuff() {
    std::cout << "fun smashy smashy class: " << course_code << " (" << creds << " points)\n";
    std::cout << "lab stuff: " << lab_score << ", big thingy: " << project_score << "\n";
    std::cout << "your number: " << calculate_grade() << " y or n";
}