#include <iostream>
#include <vector>

std::vector<int> vector_1(std::vector<int> vec);
std::vector<int> vector_ref(std::vector<int>& vec);

// 编译运行：g++ -std=c++11 -Wall -Wextra -pedantic chapter_5/func_vector.cpp -o /tmp/func_vector && /tmp/func_vector
int main() {

    std::vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // vec的内存布局：
    //  1. vector对象本身在栈上，包含三个成员变量：
    //     - 指向动态分配的数组的指针: vec.data()，是一个指针，大小是8字节
    //     - 当前元素的数量: vec.size()，是一个size_t类型的值，大小是8字节
    //     - 当前数组的容量: vec.capacity()，是一个size_t类型的值，大小是8字节
    //  2. 动态分配的数组在堆上，存储实际的元素
    std::cout << "======main函数============= " << std::endl;
    std::cout << "sizeof(vec) = " << sizeof(vec) << std::endl; // vec是一个对象，sizeof(vec) = 24（8 + 8 + 8）
    std::cout << vec.data() << " &vec = " << &vec << std::endl; // vec.data()返回vec的首元素的地址
    std::cout << "vec.size() = " << vec.size() << std::endl;
    std::cout << "vec.capacity() = " << vec.capacity() << std::endl;
    auto vec1 = vector_1(vec); // vec的拷贝构造函数被调用，vec1是vec的一个副本，vec1的内存布局与vec相同，v
    std::cout << "==========调用后========= " << std::endl;
    std::cout << "sizeof(vec1) = " << sizeof(vec1) << std::endl; // vec1是一个对象，sizeof(vec1) = 24
    std::cout << vec1.data() << " &vec1 = " << &vec1 << std::endl; // vec1.data()返回vec1的首元素的地址
    std::cout << "vec1.size() = " << vec1.size() << std::endl;
    std::cout << "vec1.capacity() = " << vec1.capacity() << std::endl;

    auto vec2 = vector_ref(vec1); // vec的引用被传递给函数，函数内对vec的修改会影响到main函数中的vec
    std::cout << "==========调用vector_ref后========= " << std::endl;
    std::cout << "sizeof(vec2) = " << sizeof(vec2) << std::endl; // vec2是一个对象，sizeof(vec2) = 24
    std::cout << vec2.data() << " &vec2 = " << &vec2 << std::endl; // vec2.data()返回vec2的首元素的地址
    std::cout << "vec2.size() = " << vec2.size() << std::endl;
    std::cout << "vec2.capacity() = " << vec2.capacity() << std::endl;

    return 0;
}


std::vector<int> vector_1(std::vector<int> vec) {
    std::cout << "======函数内============= " << std::endl;
    std::cout << "sizeof(vec) = " << sizeof(vec) << std::endl; // vec是一个对象，sizeof(vec) = 24
    std::cout << vec.data() << " &vec = " << &vec << std::endl; // vec.data()返回vec的首元素的地址
    std::cout << "vec.size() = " << vec.size() << std::endl;
    std::cout << "vec.capacity() = " << vec.capacity() << std::endl;
    for (auto& v : vec) {
        v += 10;
    }
    return vec;  // 返回值优化(RVO)，编译器会在返回时直接在调用者的栈上构造返回值，避免拷贝构造函数的调用
}


std::vector<int> vector_ref(std::vector<int>& vec) {
    std::cout << "======ref函数内============= " << std::endl;
    std::cout << "sizeof(vec) = " << sizeof(vec) << std::endl; // vec是一个对象，sizeof(vec) = 24
    std::cout << vec.data() << " &vec = " << &vec << std::endl; // vec.data()返回vec的首元素的地址
    std::cout << "vec.size() = " << vec.size() << std::endl;
    std::cout << "vec.capacity() = " << vec.capacity() << std::endl;
    for (auto& v : vec) {
        v += 10;
    }
    return vec;  // 传进来的是引用，所以返回的是引用的拷贝，返回值优化(RVO)不会发生
}