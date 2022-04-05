#include "FreeCourse.h"

FreeCourse::FreeCourse(const string& name) : name{name}
{

}

FreeCourse::~FreeCourse()
{

}

void FreeCourse::printInfo()
{
    std::cout<< "FreeCourse:" << name <<std::endl;
}

