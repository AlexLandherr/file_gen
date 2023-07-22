#include "include/round_to.h"
#include <string>
#include <iomanip>
#include <stdexcept>
#include <limits>

namespace round_to {
    std::string round_to_str(double value, int precision) {
        //Round double value to given number of decimals places, default precision is 2.
        if (value > std::numeric_limits<double>::max() || value < 0.) {
            throw std::invalid_argument("Argument 'value' is out of range/too large for 'double' type or is less than zero.");
        } else if (precision > std::numeric_limits<int>::max() || precision < 0) {
            throw std::invalid_argument("Argument 'precision' is out of range for 'int' type.");
        }
        std::ostringstream stream_obj; //creates output string stream.
        stream_obj << std::fixed; //Set fixed-point notation.
        stream_obj << std::setprecision(precision); //Set precision to precision argument's number of digits/decimal places.
        stream_obj << value; //Add double to output string stream.
        return stream_obj.str();
    }
}