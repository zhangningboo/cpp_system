#include <iostream>

using namespace std;

enum class LogLevel { DEBUG, INFO, WARN, ERROR };

void logMessage(LogLevel level, const string& message) {
    switch (level) {
        case LogLevel::DEBUG:
            cout << "[DEBUG] " << message << endl;
            break;
        case LogLevel::INFO:
            cout << "[INFO] " << message << endl;
            break;
        case LogLevel::WARN:
            cout << "[WARN] " << message << endl;
            break;
        case LogLevel::ERROR:
            cout << "[ERROR] " << message << endl;
            break;
    }
}

// g++ chapter_3/log_demo.cpp && ./a.out
int main() {
    logMessage(LogLevel::DEBUG, "This is a debug message.");
    logMessage(LogLevel::INFO, "This is an info message.");
    logMessage(LogLevel::WARN, "This is a warning message.");
    logMessage(LogLevel::ERROR, "This is an error message.");
    return 0;
}