#include <iostream>
#include <bitset>

using namespace std;

// g++ logic_op.cpp && ./a.out
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
	
	return 0;
}