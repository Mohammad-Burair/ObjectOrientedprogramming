#ifndef lecturecourse_h
#define lecturecourse_h
#include "course.h"

class lecturecourse : public course {
private:
    double mid_score;
    double final_score;

public:
    lecturecourse(std::string code, int creds, double mid, double final);
    double calculate_grade() override;
    void show_stuff() override;
};
#endif