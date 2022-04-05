#include "FreeCourse.h"
#include "VipCourse.h"
#include <vector>

using namespace std;

int main()
{
    vector<Course*> courses;
    FreeCourse linuxcourse("Linux Basic");
    VipCourse sparckcourse("Spark Project", "BigData");
    FreeCourse cppcourse("C++ Basic");
    VipCourse mlcourse("machine Learning Project", "MachineLearning");
    courses.push_back(&linuxcourse);
    courses.push_back(&sparckcourse);
    courses.push_back(&cppcourse);
    courses.push_back(&mlcourse;
    for(auto course :courses)
    {
        course->printInfo();
    }
}
