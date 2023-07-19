#include <string>

#ifndef PREFIXES_H
#define PREFIXES_H

namespace prefix {
    std::string to_binary_prefix(uint64_t bytes);
    std::string to_decimal_prefix(uint64_t bytes);
}

#endif