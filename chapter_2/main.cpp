#include <iostream>

// g++ chapter_2/main.cpp && ./a.out
int main() 
{
	bool b{false};
	std::cout << "bool的内存大小：" << sizeof(b) << std::endl;  // 1
	
	char c{49};
	std::cout << "char的内存大小：" << sizeof(c) << std::endl;  // 1
	
	int x{0};
	std::cout << "int的内存大小：" << sizeof(x) << std::endl;  // 4
	
	long long bigint{0};
	std::cout << "bigint的内存大小：" << sizeof(bigint) << std::endl; // 8
	
	float f{0.0};
	std::cout << "float的内存大小：" << sizeof(f) << std::endl;  // 4
	
	double d{0.0};
	std::cout << "double的内存大小：" << sizeof(d) << std::endl;  // 8
	
	size_t s{0};
	std::cout << "size_t的内存大小：" << sizeof(s) << std::endl;  // 8
	
	uint u{0};
	std::cout << "uint的内存大小：" << sizeof(u) << std::endl;  // 4
	
	return 0;
}