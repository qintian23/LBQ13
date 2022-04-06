#include <iostream>
using namespace std;

int main(int argc, char *argv[])
{
    long a=(1<<19);
    long b=(a<<1)-1;
    cout<< b <<'/'<< a <<endl;
    return 0;
}