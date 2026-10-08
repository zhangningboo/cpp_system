#include <iostream>

// g++ cpp内存类型/1_sizeof.cpp && ./a.out
int main() {
    int a[10]{};

    std::cout << sizeof(a) << '\n'; // 40 类型： int [10]
    std::cout << sizeof(&a) << '\n'; // 8 类型： int (*)[10] （指向一个 int[10] 数组的指针。）
    std::cout << sizeof(a + 0) << '\n'; // 8 类型： int*

    std::cout << sizeof(a[0]) << '\n'; // 4 类型： int
    std::cout << sizeof(&a[0]) << '\n'; // 8 类型： int*


    std::cout << "a:             " << a << '\n';
    std::cout << "&a:            " << &a << '\n';
    std::cout << "a + 1:         " << a + 1 << '\n';
    std::cout << "&a + 1:        " << &a + 1 << '\n'; // 指针运算的步长由指针所指向的类型决定
    std::cout << "&a[0]:         " << &a[0] << '\n';

    // 40
    // 8
    // 8
    // 4
    // 8
    // a:             0x16fa2a730
    // &a:            0x16fa2a730
    // a + 1:         0x16fa2a734
    // &a + 1:        0x16fa2a758
    // &a[0]:         0x16fa2a730

    // 指针 = 地址 + 类型语义

    return 0;
}