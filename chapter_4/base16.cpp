#include <iostream>
#include <stdexcept>
#include <vector>
#include <string>

// 编译运行：g++ -std=c++11 -Wall -Wextra -pedantic chapter_4/base16.cpp -o /tmp/base16 && /tmp/base16


static const std::string hex_chars {"0123456789ABCDEF"};

std::string base16_encode(const std::string& input_str = "你好Hello, World!");

void base16_decode(const std::string& hex_str, std::string& decoded_str);

int main() {

    auto encoded_str = base16_encode();
    std::string decoded_str;
    base16_decode(encoded_str, decoded_str);
    std::cout << "Decoded: " << decoded_str << std::endl;

    return 0;
}

std::string base16_encode(const std::string& input_str) {
    std::string hex_str;
    for (unsigned char c : input_str) {
        hex_str += hex_chars[c >> 4]; // 高四位
        hex_str += hex_chars[c & 0x0F]; // 低四位
    }
    std::cout << "Original: " << input_str << std::endl;
    std::cout << "Hex: " << hex_str << std::endl;

    return hex_str;
}

void base16_decode(const std::string& hex_str, std::string& decoded_str) {
    if (hex_str.length() % 2 != 0) {
        throw std::invalid_argument("Hex string must have an even length.");
    }

    decoded_str.clear();
    for (size_t i = 0; i < hex_str.length(); i += 2) {
        char high_nibble = hex_str[i];
        char low_nibble = hex_str[i + 1];
        // isxdigit() 函数用于检查一个字符是否是十六进制数字字符（0123456789ABCDEFabcdef）。它返回一个非零值（true）如果字符是十六进制数字字符，否则返回零（false）。
        if (!isxdigit(high_nibble) || !isxdigit(low_nibble)) {
            throw std::invalid_argument("Hex string contains invalid characters.");
        }

        int high_value = (high_nibble >= 'A') ? (high_nibble - 'A' + 10) : (high_nibble - '0');
        int low_value = (low_nibble >= 'A') ? (low_nibble - 'A' + 10) : (low_nibble - '0');

        char decoded_char = static_cast<char>((high_value << 4) | low_value);  // 将高四位和低四位组合成一个字节
        decoded_str += decoded_char;
    }
}