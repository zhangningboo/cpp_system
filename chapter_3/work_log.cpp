#include <iostream>
#include <string>
#include <fstream>

using namespace std;

enum class LogLevel { DEBUG, INFO, WARN, ERROR };

void record_debug_content(string content, string current_file, int current_line, const LogLevel& log_level, const string& log_fmt);

void record_info_content(string content, string current_file, int current_line, const LogLevel& log_level, const string& log_fmt);

string fmt_content(string content, string current_file, int current_line, const string& log_fmt);
// g++ work_log.cpp && ./a.out
int main(int argc, char* argv[]) { 
    LogLevel level{LogLevel::DEBUG};
    if (argc > 1) {
        string level_str = argv[1];
        transform(level_str.begin(), level_str.end(), level_str.begin(), ::toupper);
        if (level_str == "DEBUG") {
            level = LogLevel::DEBUG;
        } else if (level_str == "INFO") {
            level = LogLevel::INFO;
        } else if (level_str == "WARN") {
            level = LogLevel::WARN;
        } else if (level_str == "ERROR") {
            level = LogLevel::ERROR;
        } else {
            cout << "Unknown log level: " << level_str << ", default to DEBUG: " << static_cast<int>(level) << endl;
        }
    }

    // string log_fmt = "{context} {file}:{line}";
    string log_fmt = R"(
        <log>
            <context>{context}</context>
            <file>{file}</file>
            <line>{line}</line>
        </log>
    )";
    record_info_content("This is an info message.", __FILE__, __LINE__, level, log_fmt);
    record_debug_content("This is a debug message.", __FILE__, __LINE__, level, log_fmt);
    return 0;
}

void record_debug_content(string content, string current_file, int current_line, const LogLevel& log_level, const string& log_fmt) {
    if (log_level <= LogLevel::DEBUG) {
        auto res = fmt_content(content, current_file, current_line, log_fmt);
        cout << res << endl;
    }
}

void record_info_content(string content, string current_file, int current_line, const LogLevel& log_level, const string& log_fmt) {
    if (log_level <= LogLevel::INFO) {
        auto res = fmt_content(content, current_file, current_line, log_fmt);
        cout << res << endl;
    }
}

string fmt_content(string content, string current_file, int current_line, const string& log_fmt) {
    string content_template = "{context}";
    string log_content = log_fmt;
    auto content_pos = log_content.find(content_template);
    if (content_pos != string::npos) {
        log_content.replace(content_pos, content_template.size(), content);
    }

    auto file_pos = log_content.find("{file}");
    if (file_pos != string::npos) {
        log_content.replace(file_pos, 6, current_file);
    }

    auto line_pos = log_content.find("{line}");
    if (line_pos != string::npos) {
        log_content.replace(line_pos, 6, to_string(current_line));
    }

    // 格式化内容，添加时间戳等
    return log_content; // 简单返回
}