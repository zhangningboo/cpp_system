#include <iostream>
#include <string>
#include <cstring>

using namespace std;

void c_style_string();

void cpp_style_string();

// g++ chapter_3/string_op.cpp && ./a.out
int main() {
    c_style_string();
    cpp_style_string();

    return 0;
}


void c_style_string() {
    const char* cstr1 = "Hello";
    const char* cstr2 = "World";
    char cstr3[50];

    strcpy(cstr3, cstr1); // 复制
    strcat(cstr3, " _ ");   // 连接
    strcat(cstr3, cstr2);
    strstr(cstr3, "Hello"); // 比较
    cout << "c_str: " << cstr3 << endl;

    string s{cstr3};
    cout << "c_str to cpp string: " << s << endl;
}

void cpp_style_string() {
    string str1 = "Hello";  // str1在栈， str1的内容在堆
    string str2 = "World";
    string str3 = str1 + " " + str2;

    cout << "cpp string: " << str3 << endl;

    const char* cstr = str3.c_str(); // 转为c风格字符串
    str3.append("!!!");
    cout << "cpp string to c_str: " << cstr << endl;

    cout << "size: " << str3.size() << endl;
    cout << "capacity: " << str3.capacity() << endl; // 当前分配的内存空间

    cout << "empty: " << str3.empty() << endl; // 是否为空
    cout << "empty: " << (str3.size() == 0) << endl; // 是否为空
    cout << "empty: " << (str3 == "") << endl; // 是否为空
    str3.clear(); // 清空内容
    cout << "empty: " << str3.empty() << endl;

    cout << "string to int: " << stoi("123") << endl;
    cout << "int to string: " << to_string(123) << endl;
    cout << "string to double: " << stod("12.34") << endl;
    cout << "double to string: " << to_string(12.34) << endl;

    string strfind = "Hello World";
    auto pos = strfind.find("or");
    if (pos != string::npos) { // npos表示未找到
        cout << "'or' found at position: " << pos << endl;
        strfind.replace(pos, 2, "O"); // 替换
        cout << "strfind: " << strfind << endl;
    } else {
        cout << "'or' not found" << endl;
    }
}
