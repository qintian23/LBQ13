# 游戏之乐

喜欢玩电脑，会玩电脑，也会运用电脑解决实际问题。

## 1.1 让CPU占用率曲线听你指挥

Task Manager

1. CPU的占用率固定在50%，为一条直线；
2. CPU的占用率为一条直线，具体占用率由命令行参数决定（参数范围1~100）；
3. CPU的占用率状态是一条正弦曲线。

> 总结

能帮助你了解当前线程/进程/系统效能的API大致有以下这些。

1. `Sleep()` —— 这个方法能让当前线程“停下来”；
2. `WaitForSingleObject()` —— 自己停下来，等待某个事件发生。
3. `GetTickCount()` —— 有人把Tick翻译成“滴答”，很形象
4. `QueryPerformanceFrequency()` 、 `QueryPerformanceCounter()` —— 让自己访问到精度更高的CPU数据
5. `timeGetSystemTime()` —— 另一个得到高精度时间的方法
6. `PerformanceCounter` —— 效能计数器
7. `GetProcessorInfo()/SetThreadAffinityMask()` —— 遇到多核的问题怎么办呢？这两个方法能够帮你更好地控制CPU
8. `GetCPUTickCount()` —— 想拿到CPU核心运行周期数吗？用用这个方法吧。

了解并应用了上面的API，就可以考虑在简历上写“精通Windows”了。

### 1.1.1 int _tmain(int argc, _TCHAR* argv[])函数及其参数的详解

首先，这个_tmain()是为了支持unicode所使用的main一个别名而已，既然是别名，应该有宏定义过的，在哪里定义的呢？就在那个让你困惑的<stdafx.h>里，有这么两行

#include <stdio.h>
#include <tchar.h>

我们可以在头文件<tchar.h>里找到_tmain的宏定义

#define _tmain main

所以，经过预编译以后， _tmain就变成main了，这下明白了吧

括号里面分别定义了一个整数型的参数个数（int argc ）和一个char类型的指针表示参数的值（char *argv[]）

_tmain 是高版本的微软 VC 编译器才有的，你查看一下 _tmain 的定义，会发现其实它和 main 是一样的。你把 _tmain 改为 main，不会有问题。相反，你如果在低版本的 VC 编译器，比如VC6.0中将 main 改为 _tmian ，就会出错。
参数的话，argc 表示命令行参数的个数，argv 是字符串数组，存储命令行参数。比如你写的程序是test.exe，你在命令行中输入“test.exe /r /s”，那么argc 就等于 3，argv[0] 就是 “test.exe”，argv[1]就是“/r"，argv[2] 就是“/s”。

DWORD 现在表示 32bit 无符号整数，即使以后 Windows 升级到64位，DWORD 仍然是 32bit 无符号整数。
