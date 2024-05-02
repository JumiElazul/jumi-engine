#include "engine_core/utility/utility.h"
#include <fstream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <vector>

namespace jumi
{
    namespace utility
    {

        std::string& left_trim(std::string& str, const char* trim_)
        {
            str.erase(0, str.find_first_not_of(trim_));
            return str;
        }

        std::string& right_trim(std::string& str, const char* trim_)
        {
            str.erase(str.find_last_not_of(trim_) + 1);
            return str;
        }

        std::string& trim(std::string& str, const char* trim_)
        {
            return left_trim(right_trim(str, trim_), trim_);
        }

        std::string left_trim_copy(std::string str, const char* trim_)
        {
            return left_trim(str, trim_);
        }

        std::string right_trim_copy(std::string str, const char* trim_)
        {
            return right_trim(str, trim_);
        }

        std::string trim_copy(std::string str, const char* trim_)
        {
            return trim(str, trim_);
        }

        std::vector<std::string> split(const std::string& str, char delimiter)
        {
            std::vector<std::string> tokens;
            std::string token;

            size_t current_pos = 0;
            size_t end_pos = 0;
            while ((end_pos = str.find(delimiter, current_pos)) != std::string::npos)
            {
                token = str.substr(current_pos, end_pos - current_pos);
                tokens.push_back(token);
                current_pos = end_pos + 1;
            }

            if (current_pos <= str.length())
            {
                tokens.push_back(str.substr(current_pos, str.length() - current_pos));
            }

            return tokens;
        }

        std::vector<std::string> split(const std::string& str, const std::string& delimiter)
        {
            std::vector<std::string> tokens;
            std::string token;

            size_t current_pos = 0;
            size_t end_pos = 0;

            while ((end_pos = str.find(delimiter, current_pos)) != std::string::npos)
            {
                token = str.substr(current_pos, end_pos - current_pos);
                tokens.push_back(token);
                current_pos = end_pos + delimiter.length();
            }

            if (current_pos <= str.length())
            {
                tokens.push_back(str.substr(current_pos, str.length() - current_pos));
            }

            return tokens;
        }

        std::fstream open_file(const std::string& filepath)
        {
            std::fstream file(filepath);

            if (!file)
            {
                std::string message = "File " + filepath + " could not be opened";
                throw std::runtime_error(message);
            }

            return file;
        }

        std::vector<std::string> read_lines(std::fstream& file)
        {
            std::vector<std::string> contents;
            std::stringstream ss;
            ss << file.rdbuf();

            std::string line;
            while (std::getline(ss, line, '\n'))
            {
                contents.push_back(line);
            }

            return contents;
        }

        std::string stringify_file(std::fstream& file)
        {
            std::stringstream ss;
            ss << file.rdbuf();
            std::string contents = ss.str();
            return contents;
        }

    }
}
