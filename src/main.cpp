#include "include/prefixes.h"
#include "include/round_to.h"
#include "include/replace.h"
#include "include/timestamp.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <array>
#include <chrono>

int main() {
    std::array<int, 3> valid_modes = {0, 1, 2};
    int mode_select = 0;

    auto UTC_prog_start_time = std::chrono::system_clock::now();
    std::string test_file_name_str = "";
    try {
        test_file_name_str = replace::replace_char(' ', '_', timestamp::to_UTC(UTC_prog_start_time));
    } catch (std::invalid_argument const& ex) {
        std::cout << ex.what() << '\n';
    }

    std::string file_path_str = "test_files/File_Gen_Test_File_" + test_file_name_str + ".txt";

    while (true) {
        std::cout << "Select test file generation mode from list below:" << '\n';
        std::cout << "0. Write out full byte value (in decimal form)." << '\n';
        std::cout << "1. Select from a range of preset values." << '\n';
        std::cout << "2. Exit program." << '\n';
        std::cout << "Enter one of the listed values: ";
        std::cin >> mode_select;
        if (!std::cin) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "\n\nThat's an invalid input! Please try again." << '\n';
        } else if (std::find(std::begin(valid_modes), std::end(valid_modes), mode_select) != std::end(valid_modes)) {
            break;
        } else {
            std::cout << "\nInvalid mode select, try again!" << '\n';
        }
    }

    std::cout << "\n    ****    \n";

    switch (mode_select) {
        case 0: {
            //Write out full byte value (in decimal form).
            uint64_t byte_val = 0;
            while (true) {
                std::cout << "Enter byte value greater than or equal to 0 and less than or equal to 10737418240: ";
                std::cin >> byte_val;
                if (byte_val >= 0 && byte_val <= 10737418240) { //10 Gibibytes.
                    break;
                } else if (!(byte_val >= 0 && byte_val <= 10737418240)) {
                    std::cout << "\nByte value either negative or larger than 10737418240!" << '\n';
                } else if (!std::cin) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cerr << "Byte value was out of range!" << '\n';
                }
            }

            std::fstream test_fs{file_path_str, std::ios::out}; //Creating a file stream object to output to.
            test_fs.put('a'); //Puts a single character into the test file.

            std::filesystem::path p = file_path_str;
            std::filesystem::resize_file(p, byte_val); //Resize file to specified size.
            std::cout << "File size after resize (binary prefix): " << prefix::to_binary_prefix(std::filesystem::file_size(p)) << '\n';
            std::cout << "File size after resize (decimal prefix): " << prefix::to_decimal_prefix(std::filesystem::file_size(p)) << '\n';

            break;
        }
        case 1: {
            //Select from a range of preset values.

            break;
        }
        case 2: {
            //Exit program.
            std::cout << "Exited program." << '\n';
            break;
        }
        default: {
            std::cout << "Defaulted to exiting program since no valid input was made." << '\n';
            std::exit(EXIT_FAILURE);
        }
    }
    
    return 0;
}