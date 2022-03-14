# 智能指针

由于C++11抛弃了传统的智能指针auto_ptr，因此在新代码中最好不要使用auto_ptr，c++11常用的三个智能指针包括：

* unique_ptr : 独享指针
* shared_ptr : 共享指针
* weak_ptr : 弱指针

> unique_ptr唯一拥有所指向对象的所有权，不支持拷贝和赋值操作，因此只能通过move函数将其所有权转移给其他的智能指针，确保不喝其他智能指针指向同一个对象。

```
unique_ptr<int> p1(new int(1));
unique_ptr<int> p2=p1; // 错误，不能进行赋值操作
unique_ptr<int> p2=std::move(p1); // 正确，可以通过move函数转移所有权
```

> 多个shared_ptr共享所指向对象的所有权，通过引用计数管理指向同一对象的智能指针个数，每增加一个智能指针指向对象时，引用计数加1，当指向同一对选哪个的所有智能指针的生命周期都结束时，引用计数为0，此时释放对象的内存空间。

> weak_ptr 配合shared_ptr一起使用，二者可以指向同一个对象，但是不改变引用计数的值。

```
shared_ptr<int> p1(new int(1)); // 引用计数为1
shared_ptr<int> p2=p1; // 引用计数为2
weak_ptr<int> p3=p2; // 引用计数为2
```

根据三种智能指针的性质不难看出，当对象无需共享所有权，应该使用unique_ptr；当对象需要共享所有权时，应该使用shared_ptr；当需要与shared_ptr共享所有权而不想改变引用计数时，应该使用weak_ptr。

## 1 简述环状引用问题及其解决方案

```
class A
{
    public:
        shared_ptr<B> bptr;
        ~A() {cout<< "~A()" <<endl;}
};
class B
{
    public:
        shared_ptr<A> bptr;
        ~B() {cout<< "~B()" <<endl;}
};
int main()
{
    shared_ptr<A> a(new A());
    shared_ptr<B> b(new B());

    a->bptr=b;
    b->aptr=a;
}
```

在可能出现环状引用的地方使用weak_ptr弱指针代替shared_ptr共享指针可以有效地避免环状引用问题。

## 2 unique_ptr 优于 auto_ptr的原因

auto_ptr允许赋值操作，只是赋值操作的含义是将指针指向对象的所有权转移给另一个auto_ptr指针，原指针在失去对象的所有权后成为空指针，如果后续程序错误地使用了这个空指针可能会发生潜在的问题，而unique_ptr从根本上禁止了赋值操作。

实际上，unique_ptr在赋值上做了折中：如果赋值给一个临时变量，则允许进行赋值操作。因为临时变量在赋值后会立即销毁，不会被使用，也就不会产生安全问题。

其次auto_ptr不能作为容器的元素。由于容器中的对象需要支持拷贝构造函数，拷贝构造函数的参数为const类型，之不能改变，而auto_ptr在赋值是肯定会修改参数值，因为auto_ptr需要将参数中的指针置空，避免两个auto_ptr指向同一个对象。

最后auto_ptr不适用于动态数组，由于动态数组使用delete[/]释放数组中所有元素的空间，而auto_ptr在释放对象空间是默认使用delete操作符，只会释放动态数组首元素的空间，造成内存泄漏，而unique_ptr则会正确使用delete[/]释放整个动态数组空间。

由于unique_ptr在内存安全性、充当容器元素和支持动态数组方面均优于auto_ptr，因此C++11中使用unique_ptr代替auto_ptr。

```
unique_ptr<int> p1=(new int(1));
unique_ptr<int> p2=p1; // 不允许
unique_ptr<int> p1=unique_ptr<int> (new int(1)); // 允许

vector<auto_ptr<int>> vs; // 不允许
vector<unique_ptr<int>> vs; // 允许

auto_ptr<int> p1(new int[10]); // 不允许
unique_ptr<int> p2(new int[10]); // 允许
```