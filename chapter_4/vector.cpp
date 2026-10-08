#include <iostream>
#include <stdexcept>
#include <vector>

// 编译运行：g++ -std=c++11 -Wall -Wextra -pedantic chapter_4/vector.cpp -o /tmp/vector_demo && /tmp/vector_demo

// size：已构造的元素个数，有效下标范围为 [0, size)。
// capacity：当前存储空间能容纳的元素个数，始终 >= size。
// sizeof(vector)：容器对象本身的大小，不包含动态分配的元素存储空间。
void print_vector(const char* label, const std::vector<int>& values) {
    std::cout << label << "\n  size=" << values.size()
              << ", capacity=" << values.capacity() << ", elements=[";
    for (std::size_t i = 0; i < values.size(); ++i) {
        if (i != 0) {
            std::cout << ", ";
        }
        std::cout << values[i]; // 已确认 i < size，可使用不检查边界的 operator[]。
    }
    std::cout << "]\n";
}

void construction_and_access() {
    std::cout << "\n=== 1. 构造与访问 ===\n";
    std::vector<int> empty;
    std::vector<int> zeros(3);          // 3 个 int 元素，值均为 0。
    std::vector<int> repeated(3, 7);    // 3 个元素，每个值为 7。
    std::vector<int> values{10, 20, 30}; // 花括号表示元素列表。
    // 注意：vector<int>(3, 7) 是三个 7，vector<int>{3, 7} 是两个元素 3 和 7。
    print_vector("默认构造", empty);
    print_vector("指定元素个数", zeros);
    print_vector("指定个数与初始值", repeated);
    print_vector("初始化列表", values);

    std::cout << "sizeof(values)=" << sizeof(values) << " bytes\n";
    std::cout << "values[1]=" << values[1]
              << ", front=" << values.front() << ", back=" << values.back() << '\n';
    // front()/back() 要求容器非空；operator[] 越界是未定义行为。
    // at() 检查下标，越界时抛出 std::out_of_range。
    try {
        std::cout << values.at(values.size()) << '\n';
    } catch (const std::out_of_range&) {
        std::cout << "at(size())：下标越界，捕获 std::out_of_range\n";
    }

    // vector<int> 的元素连续存储，data() 返回底层元素指针。
    // 空 vector 的 data() 不可解引用，也不能通过 data() 访问 size 之外的空间。
    std::cout << "data()=" << static_cast<const void*>(values.data()) << '\n';
}

void capacity_and_resize() {
    std::cout << "\n=== 2. reserve、添加元素与 resize ===\n";
    std::vector<int> values;
    values.reserve(10);
    // reserve(10) 保证 capacity >= 10，size 仍为 0，不构造新元素。
    // reserve 不会缩小容量；预留空间不意味着可以访问这些位置。
    print_vector("reserve(10)", values);

    values.push_back(11);
    values.emplace_back(12); // 在末尾直接构造元素；对 int 与 push_back 效果相近。
    // 容量足够时，尾部添加元素只增加 size，不改变 capacity。
    // push_back 的时间复杂度为均摊 O(1)，发生扩容的一次操作为 O(n)。
    print_vector("添加两个元素", values);

    values.resize(5);
    // 增大 size 时构造新增元素；这里新增的 int 为 0，原有元素保持不变。
    print_vector("resize(5)", values);

    values.resize(8, 99); // 仅新增元素使用 99，已有元素不会被覆盖。
    print_vector("resize(8, 99)", values);

    // 为确保演示扩容，目标大小取当前 capacity + 1。
    const auto larger_size = values.capacity() + 1;
    values.resize(larger_size);
    // 新 size 超过原 capacity 时必须扩容；新 capacity 至少等于 size。
    // 扩容倍率和最终 capacity 由实现决定，不能假定翻倍或恰好等于 size。
    // 重新分配会使指向原元素的指针、引用和迭代器全部失效。
    print_vector("resize(原 capacity + 1)：触发扩容", values);

    values.resize(2);
    // 缩小 size 会销毁尾部元素，但不会缩小 capacity。
    print_vector("resize(2)：删除尾部元素，保留容量", values);

    values.shrink_to_fit();
    // 请求释放多余容量，不改变 size；非强制请求，实现可以不缩容。
    // 如果发生重新分配，原有指针、引用和迭代器也会失效。
    print_vector("shrink_to_fit()：请求缩容", values);
}

void insertion_and_removal() {
    std::cout << "\n=== 3. 插入、删除与遍历 ===\n";
    std::vector<int> values{10, 20, 30};
    values.insert(values.begin() + 1, 15);
    print_vector("在下标 1 处插入 15", values);

    values.erase(values.begin() + 2); // 删除下标 2 的元素，后续元素向前移动。
    print_vector("删除下标 2 的元素", values);
    // 中间插入/删除通常需要移动后续元素，时间复杂度为 O(n)。
    // erase 使删除位置及其后的迭代器、引用失效；insert 未扩容时也使
    // 插入位置及其后的迭代器、引用失效，扩容时则使全部失效。

    for (int& value : values) { // 使用引用修改元素；使用 int value 只修改副本。
        value *= 2;
    }
    print_vector("范围 for：每个元素乘以 2", values);

    values.pop_back(); // 删除最后一个元素，要求容器非空，不缩小 capacity。
    print_vector("pop_back()", values);

    values.clear(); // 销毁所有元素，size 变为 0，capacity 保持不变。
    print_vector("clear()：清空元素，保留容量", values);
    std::cout << "empty()=" << std::boolalpha << values.empty() << '\n';
}

int main() {
    construction_and_access();
    capacity_and_resize();
    insertion_and_removal();
    return 0;
}
