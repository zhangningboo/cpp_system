#include <iostream>

// g++ env_op.cpp && ./a.out arg1 arg2
int main(int argc, char* argv[], char* envp[]) {
    for (int i = 0; i < argc; ++i) {
        std::cout << "arg[" << i << "]: " << argv[i] << std::endl;
    }

    for (char** env = envp; *env != nullptr; ++env) {
        std::cout << "env: " << *env << std::endl;
    }

    return 0;
}