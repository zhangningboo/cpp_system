#include <iostream>

using namespace std;

enum Color { RED, GREEN, BLUE };
enum Fruit { APPLE=1, BANANA=2, ORANGE=3 }; //
// c++11后
enum class Animal { DOG=1, CAT=2, TIGER=3 }; // 强类型枚举

// g++ enum_op.cpp && ./a.out
int main() {
    Color c{RED};
    Fruit f{APPLE};

    cout << "Color: " << static_cast<int>(c) << endl;
    cout << "Fruit: " << static_cast<int>(f) << endl;

    Animal a{Animal::DOG};
    cout << "Animal: " << static_cast<int>(a) << endl;
    return 0;
}