#ifndef labcourse_h
#define labcourse_h
#include "course.h"

class labcourse : public course {
private:
    double lab_score;
    double project_score;

public:
    labcourse(std::string code, int creds, double lab, double project);
    double calculate_grade() override;
    void show_stuff() override;
};
#endif