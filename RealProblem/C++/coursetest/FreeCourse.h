#pragma once
#include "Course.h"

class FreeCourse : protected Course
{
    public:
        FreeCourse(const string&);
        ~FreeCourse();

        void printInfo();
};

