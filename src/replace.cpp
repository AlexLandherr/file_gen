#include "include/replace.h"
#include <string>
#include <limits>
#include <stdexcept>

namespace replace {
    std::string replace_char(char target_char, char replacement_char, std::string target_str) {
        //Replace all occurrences of a given char in a std::string with another.
        if (target_char > std::numeric_limits<char>::max() || target_char < std::numeric_limits<char>::min()) {
            throw std::invalid_argument("Argument 'target_char' is out of range for 'char' type.");
        } else if (replacement_char > std::numeric_limits<char>::max() || replacement_char < std::numeric_limits<char>::min()) {
            throw std::invalid_argument("Argument 'target_char' is out of range for 'char' type.");
        }
        std::replace(target_str.begin(), target_str.end(), target_char, replacement_char);
        return target_str;
    }
}