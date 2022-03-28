#include <stdio.h>

typedef int Dimension; // 维度
#define DEFAULT_D 3 // 默认初始容量

template<typename T> class vec
{
    protected:
        Dimension _size; int _capacity; T* _elem; // 规模，容量，数据区
        void copyFrom(T const* A, Dimension lo, Dimension hi); // 复制数组区间A[lo,hi]
        void expand(); // 空间不足时扩容
        void shrink(); // 装填因子过小时压缩

    public:
        // 构造函数
        vec(int c=DEFAULT_D, int s=0, T v=0) // 容量为c，规模为s，所有元素初始化为v
        {_elem=new T[_capacity=c]; for(_size=0; _size<s; _elem[_size++]=v);}
        vec(T const* A, Dimension lo, Dimension hi) {copyFrom(A,lo,hi);} //数组区间复制
        vec(T const* A, Dimension n) {copyFrom(A,0,n);} // 数组整体复制
        vec(vec<T> const &V, Dimension lo, Dimension hi) {copyFrom(V._elem,lo,hi);} // 向量区间复制
        vec(vec<T> const &V) {copyFrom(V._elem,0,V._size);} // 向量区间复制
        // 析构函数
        ~vec(){delete [] _elem;} // 释放内部空间
        // 只读访问接口
        Dimension size() const {return _size;} //规模
        bool empty() const {return !_size; } 
        // 可写访问接口
        T& operator[](Dimension r) const; // 重载下标操作符
        vec<T> & operator=(vec<T> const&); //重载赋值操作符
        //遍历
        void traverse(void(*)(T&)); // 遍历使用函数指针，只读或局部修改
        template<typename VST> void traverse(VST&); // 遍历（使用函数对象，可全局性修改）
        // 向量加减运算
        vec<T> operator+(const vec<T> & b);
};

template<typename T>
void vec<T>::copyFrom(T const* A, Dimension lo, Dimension hi)
{
    _elem=new T[_capacity=2*(hi-lo)]; _size=0;
    while (lo<hi)  
        _elem[_size++]=A[lo++];
}

template<typename T> vec<T>& vec<T>::operator=(vec<T> const& V)
{
    if(_elem) delete[] _elem;
    copyFrom(V._elem,0,V.size());
    return *this;
}

template<typename T> T& vec<T>::operator[](Dimension r) const
{
    return _elem[r];
}

template<typename T> vec<T> vec<T>::operator+(const vec<T> & b)
{
    vec<T> c;
    for(int i=0; i<b.size(); i++)
        c[i]=this->_elem[i]+b->_elem[i];             
    
    return c;
}

template<typename T> void vec<T>::expand()
{
    if(_size <_capacity) return ;
    if(_capacity <DEFAULT_D) _capacity=DEFAULT_D;
    T* oldElem=_elem; _elem=new T[_capacity <<=1];
    for(int i=0; i<_size; i++)
        _elem[i]=oldElem[i];
    delete[] oldElem;
}

template<typename T> void vec<T>::shrink()
{
    if(_capacity < _capacity << 1) return ;
    if(_size << 2 > _capacity) _capacity=DEFAULT_D;
    T* oldElem=_elem; _elem=new T[_capacity >>=1];
    for(int i=0; i<_size; i++)
        _elem[i]=oldElem[i];
    delete[] oldElem;
}

template<typename T> void vec<T>::traverse(void (*visit)(T&))
{
    for(int i=0; i<_size; i++) visit(_elem[i]);
}

template<typename T> template<typename VST> 
void vec<T>::traverse(VST& visit)
{
    for(int i=0; i<_size; i++) visit(_elem[i]);
}

int main(int argc, char* argv[])
{
    vec<int> x ={1,2,3};
    vec<int> y ={1,2,3};
    // vec<int> z=x+y;

    printf("%d\n %d, %d, %d\n", x.size(), x[0], x[1], x[2]);

    // printf("%d, %d, %d\n", z[0], z[1], z[2]);

    return 0;
}