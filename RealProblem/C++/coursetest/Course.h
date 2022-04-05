#pragma once

#include <iostream>

using namespace std;

class Course
{
    public:
        Course(const string &name):name(name){};
        virtual ~Course()=0;

        void printInfo();
        
    private:
        string name;
};

