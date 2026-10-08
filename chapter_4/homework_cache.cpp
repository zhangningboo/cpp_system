#include <iostream>
#include <vector>
#include <string>

static std::vector<std::string> cache_key{};
static std::vector<std::string> cache_value{};

bool insert(const std::string& key, const std::string& value) {
    cache_key.push_back(key);
    cache_value.push_back(value);
    return true;
}

bool get(const std::string& key, std::string& value) {
    for (size_t i = 0; i < cache_key.size(); ++i) {
        if (cache_key[i] == key) {
            value = cache_value[i];
            return true;
        }
    }
    return false;
}

bool delete_key(const std::string& key) {
    for (size_t i = 0; i < cache_key.size(); ++i) {
        if (cache_key[i] == key) {
            cache_key.erase(cache_key.begin() + i);
            cache_value.erase(cache_value.begin() + i);
            return true;
        }
    }
    return false;
}

// 编译运行：g++ -std=c++11 -Wall -Wextra -pedantic chapter_4/homework_cache.cpp -o /tmp/homework_cache && /tmp/homework_cache
int main() {
    
    while (true) {
        std::string input;
        getline(std::cin, input); // 读取一行输入

        std::cout << "You entered: " << input << std::endl;

        input.erase(0, input.find_first_not_of(' ')); // 去除首部空格
        input.erase(input.find_last_not_of(' ') + 1); // 去除尾部空格

        if (input.empty()) {
            std::cout << "Input is empty." << std::endl;
            continue;
        }

        if (input == "exit") {
            std::cout << "Exiting program." << std::endl;
            break;
        }

        std::string command[3] = {"", "", ""};

        // 如果key或者value中间有空格，则只取第一个空格前的作为key，剩下的作为value
        size_t pos = input.find(" ");
        if (pos != std::string::npos) {
            command[0] = input.substr(0, pos);
            std::string remaining_input = input.substr(pos + 1);
            pos = remaining_input.find(" ");
            if (pos != std::string::npos) {
                command[1] = remaining_input.substr(0, pos);
                command[2] = remaining_input.substr(pos + 1);
            } else {
                command[1] = remaining_input;
                command[2] = "";
            }
        } else {
            std::cout << "Invalid input format. Please enter in the format: key value" << std::endl;
            continue;
        }
        
        if (command[0].compare("insert") == 0) {
            if (insert(command[1], command[2])) {
                std::cout << "Inserted key: " << command[1] << ", value: " << command[2] << std::endl;
            } else {
                std::cout << "Failed to insert key: " << command[1] << std::endl;
            }
        } else if (command[0].compare("get") == 0) {
            std::string value;
            if (get(command[1], value)) {
                std::cout << "Value for key " << command[1] << ": " << value << std::endl;
            } else {
                std::cout << "Get failed. Key not found: " << command[1] << std::endl;
            }
        } else if (command[0].compare("delete") == 0) {
            if (delete_key(command[1])) {
                std::cout << "Deleted key: " << command[1] << std::endl;
            } else {
                std::cout << "Delete failed. Key not found: " << command[1] << std::endl;
            }
        } else {
            std::cout << "Unknown command: " << command[0] << std::endl;
        }
    }

    return 0;
}

