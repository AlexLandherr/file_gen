#include <string>

#ifndef PREFIXES_H
#define PREFIXES_H

namespace prefix {
    std::string to_binary_prefix(uintmax_t bytes);
    std::string to_decimal_prefix(uintmax_t bytes);
}

#endif