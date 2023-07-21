#include "include/prefixes.h"
#include "include/round_to.h"
#include <string>
#include <cmath>
#include <stdexcept>
#include <limits>
#include <array>

namespace prefix {
    std::string to_binary_prefix(uintmax_t bytes) {
        //Convert byte value to std::string with appropriate binary prefix rounded to 2 decimal places.
        if (bytes > std::numeric_limits<uintmax_t>::max() || bytes < std::numeric_limits<uintmax_t>::min()) {
            throw std::invalid_argument("Argument 'bytes' is out of range for 'uintmax_t' type.");
        }
        constexpr uint64_t KiB = 1ull << 10; //kibibyte
        constexpr uint64_t MiB = 1ull << 20; //mebibyte
        constexpr uint64_t GiB = 1ull << 30; //gibibyte
        constexpr uint64_t TiB = 1ull << 40; //tebibyte
        constexpr uint64_t PiB = 1ull << 50; //pebibyte
        constexpr uint64_t EiB = 1ull << 60; //exbibyte
        if (bytes < KiB) {
            return round_to::round_to_str(bytes, 0) + " B";
        } else if (KiB <= bytes && bytes < MiB) {
            return round_to::round_to_str(bytes / (KiB / 1.0)) + " KiB";
        } else if (MiB <= bytes && bytes < GiB) {
            return round_to::round_to_str(bytes / (MiB / 1.0)) + " MiB";
        } else if (GiB <= bytes && bytes < TiB) {
            return round_to::round_to_str(bytes / (GiB / 1.0)) + " GiB";
        } else if (TiB <= bytes && bytes < PiB) {
            return round_to::round_to_str(bytes / (TiB / 1.0)) + " TiB";
        } else if (PiB <= bytes && bytes < EiB) {
            return round_to::round_to_str(bytes / (PiB / 1.0)) + " PiB";
        } else {
            return round_to::round_to_str(bytes / (EiB / 1.0)) + " EiB";
        }
    }

    std::string to_decimal_prefix(uintmax_t bytes) {
        //Convert byte value to std::string with appropriate decimal prefix rounded to 2 decimal places.
        if (bytes > std::numeric_limits<uintmax_t>::max() || bytes < std::numeric_limits<uintmax_t>::min()) {
            throw std::invalid_argument("Argument 'bytes' is out of range for 'uintmax_t' type.");
        }
        constexpr uint64_t kB = 1000; //kilobyte
        constexpr uint64_t MB = 1000000; //megabyte
        constexpr uint64_t GB = 1000000000; //gigabyte
        constexpr uint64_t TB = 1000000000000; //terabyte
        constexpr uint64_t PB = 1000000000000000; //petabyte
        constexpr uint64_t EB = 1000000000000000000; //exabyte
        if (bytes < kB) {
            return round_to::round_to_str(bytes, 0) + " B";
        } else if (kB <= bytes && bytes < MB) {
            return round_to::round_to_str(bytes / (kB / 1.0)) + " kB";
        } else if (MB <= bytes && bytes < GB) {
            return round_to::round_to_str(bytes / (MB / 1.0)) + " MB";
        } else if (GB <= bytes && bytes < TB) {
            return round_to::round_to_str(bytes / (GB / 1.0)) + " GB";
        } else if (TB <= bytes && bytes < PB) {
            return round_to::round_to_str(bytes / (TB / 1.0)) + " TB";
        } else if (PB <= bytes && bytes < EB) {
            return round_to::round_to_str(bytes / (PB / 1.0)) + " PB";
        } else {
            return round_to::round_to_str(bytes / (EB / 1.0)) + " EB";
        }
    }
}