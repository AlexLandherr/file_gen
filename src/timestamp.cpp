#include "include/timestamp.h"
#include <string>
#include <chrono>

namespace timestamp {
    std::string to_UTC(std::chrono::system_clock::time_point now) {
        //Convert a system clock time point to UTC and return time as a std::string with format "yyyy-mm-dd hh:mm:ss".
        std::time_t time = std::chrono::system_clock::to_time_t(now);
        char timeString[std::size("yyyy-mm-dd hh:mm:ss UTC")];
        std::strftime(std::data(timeString), std::size(timeString), "%F %T UTC", std::gmtime(&time));
        return timeString;
    }
}