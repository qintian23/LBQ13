#include <iostream>
#include <string>
using namespace std;
int main(int argc, char* argv[])
{
    string day;
    cin>> day;
    if(day[0]>='6' || day[5]>='6') // 19**年
    {
        cout<< "19" << day.substr(0,2) << '-' <<  day.substr(3,2) << '-' <<  day.substr(6,2) <<endl;
        cout<< "19" << day.substr(6,2) << '-' <<  day.substr(0,2) << '-' <<  day.substr(3,2) <<endl;
        cout<< "19" << day.substr(6,2) << '-' <<  day.substr(3,2) << '-' <<  day.substr(0,2) <<endl;
    }
    else
    {
        cout<< "20" << day.substr(0,2) << '-' <<  day.substr(3,2) << '-' <<  day.substr(6,2) <<endl;
        cout<< "20" << day.substr(6,2) << '-' <<  day.substr(0,2) << '-' <<  day.substr(3,2) <<endl;
        cout<< "20" << day.substr(6,2) << '-' <<  day.substr(3,2) << '-' <<  day.substr(0,2) <<endl;
    }
    return 0;
}