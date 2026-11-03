#include <iostream>

// 函数返回时，不能返回栈区变量
// 指针、引用作为参数，可以减少内存拷贝，提高效率
void ptr(int* x, int* y);
void ref(int& x, int& y);

// 编译运行：g++ -std=c++11 -Wall -Wextra -pedantic chapter_5/func_ptr_ref.cpp -o /tmp/func_ptr_ref && /tmp/func_ptr_ref
int main() {

    // 指针 = 内存地址
    // 指针变量 = 内存地址 + 类型语义

    int x{10};
    int y{20};
    std::cout << "&x = " << &x << std::endl;
    std::cout << "&y = " << &y << std::endl;

    std::cout << "----------ptr--------------" << std::endl;
    ptr(&x, &y);
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;

    std::cout << "----------ref--------------" << std::endl;
    ref(x, y);
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;

    return 0;
}

void ptr(int* x, int* y) {
    
    std::cout << "x = " << *x << std::endl;
    std::cout << "&x = " << x << std::endl;
    std::cout << "y = " << *y << std::endl;
    std::cout << "&y = " << y << std::endl;

    *x = 100; // 修改 x 的值
    *y = 200; // 修改 y 的值

    int* ptr = x; // 指针变量 ptr 存储了 x 的内存地址
    std::cout << "ptr = " << ptr << std::endl;
    std::cout << "*ptr = " << *ptr << std::endl; // 解引用指针变量 ptr，获取其指向的内存地址的值，即 x 的值
    std::cout << "&ptr = " << &ptr << std::endl; // ptr 的内存地址
}

void ref(int& x, int& y) {
    std::cout << "x = " << x << std::endl;
    std::cout << "&x = " << &x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "&y = " << &y << std::endl;
    x = 101; // 修改 x 的值
    y = 201; // 修改 y 的值

    int &ref = x; // 引用变量 ref 绑定到 x
    std::cout << "ref = " << ref << std::endl;
    std::cout << "&ref = " << &ref << std::endl; // ref 的内存地址
}