#include <iostream>

using namespace std;

int main() 
{
	int x{1};
	cin >> x;  // 非法输入时将变量设置为默认值0
	cout << x << endl;
	
	char c{'a'};
	cin >> c;
	cout << c << endl;
	
	return 0;
}