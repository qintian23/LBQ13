#pragma once
#include "Course.h"

class VipCourse : protected Course
{
    public:
        VipCourse(const string &name, const string &tag);
        ~VipCourse();

        void printInfo();
    
    private:
        string tag;
};

