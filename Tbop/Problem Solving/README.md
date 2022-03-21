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
