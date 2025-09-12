## 字符串

- `const char *`
    - 指向一段以 `\0`结尾的字符数组（C风格字符串）。
    - 内存需要手动管理
    - 本身指针可以变，指向不同的地方；但字符串的字面量不能变；
    - 操作需利用`<cstring>`提供的C函数
        - strlen(s)
        - strcat(s1, s2)
        - strstr(s, "xx")
    - `const char* p = "hello"; std::string s{p};`
- `std::string`
    - 自动管理内存
    - 可随时增删改查
    - 本身提供了丰富的成员函数
    - `const char* p = s.c_str();`


## main参数
- `int main()`
- `int main(int argc, char* argv[])`
- `int main(int argc, char* argv[], char* env[])`