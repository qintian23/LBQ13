#include "VipCourse.h" 
VipCourse::VipCourse(const string &name, const string &tag):name{name}, tag{tag}
{};

VipCourse::~VipCourse()
{

}

void VipCourse::printInfo()
{
    str::cout<< "VipCouse:" <<name <<"[" << tag << "]" <<std::endl;
}