#include <iostream>
#include <vector>


// int arr[9]
// │
// ├── 类型：int[9]
// ├── sizeof(arr)：36
// ├── arr：大多数表达式中退化成 int*
// └── &arr：int (*)[9]


// int* p = new int[6]
// │
// ├── p 类型：int*
// ├── sizeof(p)：8
// ├── p 指向：堆上的 6 个 int
// └── sizeof(p) ≠ 堆内存大小


// std::vector<int> v(6)
// │
// ├── v 类型：std::vector<int>
// ├── sizeof(v)：vector 对象本身大小
// ├── v.size()：6
// ├── v.capacity()：容量
// └── v.data()：底层数组地址

void stack_array();

void heap_array();

void container_array();

// g++ chapter_4/array.cpp && ./a.out
int main() {
    stack_array();
    heap_array();
    container_array();
    return 0;
}

void stack_array() {
    std::cout << "============ 栈区数组 ============= " << std::endl;

    int arr1[9] = {0};
    std::cout << "sizeof(arr1): " << sizeof(arr1) << std::endl; // arr1的类型是：int[9]
    std::cout << "arr1: " << arr1 << std::endl; // 数组到指针的隐式转换（array-to-pointer decay）
    std::cout << "&arr1: " << &arr1 << std::endl; // &arr1类型是：int (*)[9]
    std::cout << "sizeof(int*): " << sizeof(int*) << std::endl;
    std::cout << "sizeof(int): " << sizeof(int) << std::endl;
}

void heap_array() {
    std::cout << "============ 堆区数组 =============" << std::endl;

    int* arr1 = new int[6] {0};
    auto arr2 = new int[4] {1, 2, 3, 4};

    std::cout << "sizeof(arr1): " << sizeof(arr1) << std::endl; // 获取的是指针的大小；arr1的类型是：int*，是一个指针
    std::cout << "sizeof(int*): " << sizeof(int*) << std::endl;
    std::cout << "sizeof(int): " << sizeof(int) << std::endl;


    delete []arr1;
    arr1 = nullptr;

    delete []arr2;
    arr2 = nullptr;

}

void container_array() {
    std::vector<int> arr1{};
}