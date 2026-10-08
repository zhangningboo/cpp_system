#include <iostream>

// g++ chapter_4/for_base.cpp && ./a.out
int main(int argc, char* argv[], char* env[]) {
    
    for (int i = 0; env[i] != nullptr; i++) {
        std::cout << env[i] << std::endl;
    }
    
    return 0;
}