#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> iv(2,0);
    cout<< "size=" << iv.size() << "\tcapacity=" << iv.capacity() <<endl;

    for(int i=1; i<=8; i++)
    {
        iv.push_back(i);
        cout<< "size=" << iv.size() << "\tcapacity=" << iv.capacity() <<endl;
    } 
    return 0;
}