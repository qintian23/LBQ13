#include <iostream>
using namespace std;
int main()
{
  int months[]={31,29,31,30,31,30,31,31,30,31,30,31};
  int month=1;
  int day=1;
  int days=0;
  for(int i=month-1; i<5-1; i++)
    days+=months[i];
  days+=4;
  cout<< days <<endl;
  return 0;
}