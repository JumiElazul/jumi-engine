#ifndef JUMI_ENGINE_UTILITY_UTILITY_H
#define JUMI_ENGINE_UTILITY_UTILITY_H

#include <fstream>
#include <string>
#include <vector>

namespace jumi
{
    namespace utility
    {
        std::string& left_trim(std::string& str, const char* trim_ = " \t\n\r\f\v");
        std::string& right_trim(std::string& str, const char* trim_ = " \t\n\r\f\v");
        std::string& trim(std::string& str, const char* trim_ = " \t\n\r\f\v");
        std::string left_trim_copy(std::string str, const char* trim_ = " \t\n\r\f\v");
        std::string right_trim_copy(std::string str, const char* trim_ = " \t\n\r\f\v");
        std::string trim_copy(std::string str, const char* trim_ = " \t\n\r\f\v");
        std::vector<std::string> split(const std::string& str, char delimiter);
        std::vector<std::string> split(const std::string& str, const std::string& delimiter);
        std::fstream open_file(const std::string& filepath);
        std::vector<std::string> read_lines(std::fstream& file);
        std::string stringify_file(std::fstream& file);
    }
}

#endif
