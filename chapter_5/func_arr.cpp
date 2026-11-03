#include <iostream>

// 函数参数为数组时，传递的是数组首元素的地址
void base_arr_1(int arr[16]);
void base_arr_2(int* arr);
void base_arr_3(int arr[]);

void tran_size(int arr[], int size);

using Array16 = int[16]; // 类型别名，表示一个包含16个int类型元素的数组
// 参数类型必须指定大小
Array16& ref_arr(int (&arr)[16]) {
    std::cout << "int (&arr)[16] sizeof(arr) = " << sizeof(arr) << std::endl; // arr是数组的引用，sizeof(arr) = 16 * sizeof(int)
    return arr;
}

// 编译运行：g++ -std=c++11 -Wall -Wextra -pedantic chapter_5/func_arr.cpp -o /tmp/func_arr && /tmp/func_arr
int main() {
    
    int data[16] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};

    std::cout << "sizeof(int) = " << sizeof(int) << std::endl;
    std::cout << "sizeof(data) = " << sizeof(data) << std::endl;

    base_arr_1(data);
    base_arr_2(data);
    base_arr_3(data);

    tran_size(data, sizeof(data) / sizeof(data[0]));

    auto& reref_arr = ref_arr(data);
    std::cout << "sizeof(reref_arr) = " << sizeof(reref_arr) << std::endl; // reref_arr是数组的引用，sizeof(reref_arr) = 16 * sizeof(int)
    return 0;
}

void base_arr_1(int arr[16]) {
    std::cout << "int arr[16] sizeof(arr) = " << sizeof(arr) << std::endl; // arr是首元素的地址，在64位机器，一个地址是8个字节
}

void base_arr_2(int* arr) {
    std::cout << "int* arr sizeof(arr) = " << sizeof(arr) << std::endl;
}
void base_arr_3(int arr[]) {
    std::cout << "int arr[] sizeof(arr) = " << sizeof(arr) << std::endl;
}

void tran_size(int arr[], int size) {
    std::cout << "tran_size size = " << size << std::endl;
}