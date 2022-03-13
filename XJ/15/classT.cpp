#include <stdio.h>

template<typename T> class Test
{
    public:
        Test(T a) :a(a){}
        void set(const T &a) {this->a=a;}
        T get(){return a;}
    
    private:
        T a;
};

int main()
{
    Test<int> t1(100);
    Test<char> t2('a');

    printf("%d\n %c\n",t1.get(), t2.get());
    return 0;
}