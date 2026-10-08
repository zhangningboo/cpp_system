#include <iostream>
#include <bitset>

using namespace std;

// g++ chapter_3/logic_op.cpp && ./a.out
int main() 
{
	char a = 0b10000001; // c++14
	char b = 0b00000001;
	cout << "a:\t" << bitset<8>(a) << endl;
	cout << "b:\t" << bitset<8>(b) << endl;
	// 逐位非 ~
	cout << "~a:\t" << bitset<8>(~a) << endl;
	cout << "~b:\t" << bitset<8>(~b) << endl;
	// 逐位与 &
	cout << "a & b:\t" << bitset<8>(a & b) << endl;
	// 逐为或 |
	cout << "a | b:\t" << bitset<8>(a | b) << endl;

	// a:      10000001
	// b:      00000001
	// ~a:     01111110
	// ~b:     11111110
	// a & b:  00000001
	// a | b:  10000001
	
	return 0;
}