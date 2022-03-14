#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> iv(2,0);
    cout<< "size=" << iv.size() << "\tcapacity=" << iv.capacity() <<endl;

    iv.reserve(10); // 可以让容器重新分配指定大小的空间  
    // shrink_to_fit 函数可以回收所有未使用的剩余空间
    // resize 函数可以强制调整容器中已保存的元素个数

    for(int i=1; i<=8; i++)
    {
        iv.push_back(i);
        cout<< "size=" << iv.size() << "\tcapacity=" << iv.capacity() <<endl;
    } 
    return 0;
}