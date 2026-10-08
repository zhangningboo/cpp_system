#include <iostream>

// g++ cpp内存类型/3_cal.cpp && ./a.out
int main() {
    int a[10]{};

    int* p = a;
    int (&r)[10] = a;
    int (*q)[10] = &a;

    std::cout << "p     = " << p << '\n';
    std::cout << "p + 1 = " << p + 1 << '\n';

    std::cout << "q     = " << q << '\n';
    std::cout << "q + 1 = " << q + 1 << '\n';

    std::cout << "&r    = " << &r << '\n';
    std::cout << "&r+1  = " << &r + 1 << '\n';


    // p     = 0x16f27e730
    // p + 1 = 0x16f27e734
    // q     = 0x16f27e730
    // q + 1 = 0x16f27e758
    // &r    = 0x16f27e730
    // &r+1  = 0x16f27e758
}
