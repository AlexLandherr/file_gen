#include <string>
#include <chrono>

#ifndef TIMESTAMP_H
#define TIMESTAMP_H

namespace timestamp {
    std::string to_UTC(std::chrono::system_clock::time_point now);
}

#endif