#include <iostream>

// 全局变量，进入main函数前申请空间，在所有文件中都可访问
int gcount = 0;

// 静态变量，进入main函数前申请空间，只能在当前文件中访问
static int scount = 0;

void func();

// 编译运行：g++ -std=c++11 -Wall -Wextra -pedantic chapter_5/var.cpp -o /tmp/var && /tmp/var
int main() {
    // 局部变量，进入main函数时申请空间，离开main函数时释放空间
    int lcount = 0;

    gcount++;
    scount++;
    lcount++;

    std::cout << "gcount = " << gcount << std::endl;
    std::cout << "scount = " << scount << std::endl;
    std::cout << "lcount = " << lcount << std::endl;
    
    func();
    // count++; // error: ‘count’ was not declared in this scope

    return 0;
}

void func() {
    gcount++;
    scount++;
    // lcount++; // error: ‘lcount’ was not declared in this scope
    // 静态局部变量，进入main函数时申请空间，离开main函数时不释放空间
    // 生命周期：从第一次调用开始，直到程序结束
    // c++11 之前多线程不安全
    static int count = 0;
    count++;
    std::cout << "count = " << count << std::endl;
}