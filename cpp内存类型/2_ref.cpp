#include <iostream>

// g++ cpp内存类型/2_ref.cpp && ./a.out
int main() {
    int a[10]{};

    auto x = a;  // 数组退化为指针; x的类型是 int*
    auto& y = a; // y的类型是 int(&)[10]，引用类型不会发生退化
    auto z = &a; // z的类型是 int(*)[10]，指向一个 int[10] 数组的指针

    std::cout << "sizeof(a) = " << sizeof(a) << '\n';
    std::cout << "sizeof(x) = " << sizeof(x) << '\n';
    std::cout << "sizeof(y) = " << sizeof(y) << '\n';
    std::cout << "sizeof(z) = " << sizeof(z) << '\n';

    std::cout << "a     = " << a << '\n';
    std::cout << "&a    = " << &a << '\n';
    std::cout << "x     = " << x << '\n';
    std::cout << "&y    = " << &y << '\n';
    std::cout << "z     = " << z << '\n';
}