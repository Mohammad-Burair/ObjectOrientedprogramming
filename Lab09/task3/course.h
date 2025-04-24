#ifndef course_h
#define course_h
#include <string>

class course {
protected:
    std::string course_code;
    int creds;

public:
    course(std::string code, int creds) : course_code(code), creds(creds) {}
    virtual ~course() = default;
    virtual double calculate_grade() = 0;
    virtual void show_stuff() = 0;
};
#endif