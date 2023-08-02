#include "include/prefixes.h"
#include "include/round_to.h"
#include "include/replace.h"
#include "include/timestamp.h"
#include "include/flags.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <array>
#include <chrono>
#include <gflags/gflags.h>

int main(int argc, char *argv[]) {
    int argcc = argc;
    gflags::ParseCommandLineFlags(&argcc, &argv, true);
    
    std::cout << "argc: " << argc << '\n';

    const std::array<uint64_t, 6> preset_byte_values = {1000, 1024, 1000000, 1048576, 1000000000, 1073741824};

    auto UTC_prog_start_time = std::chrono::system_clock::now();
    std::string test_file_name_str = "";
    try {
        test_file_name_str = replace::replace_char(' ', '_', timestamp::to_UTC(UTC_prog_start_time));
    } catch (const std::invalid_argument& ex) {
        std::cout << ex.what() << '\n';
    }

    std::string file_path_str = "test_files/File_Gen_Test_File_" + test_file_name_str + ".txt";

    if (argc > argcc) {
        std::cout << argcc - argc << " arguments were given.\n";
        if (FLAGS_use_presets) {
            std::cout << "Using preset values." << '\n';
            //Using preset values.
            try {
                std::fstream test_fs{file_path_str, std::ios::out}; //Creating a file stream object to output to.
                test_fs.put('a'); //Puts a single character into the test file.
            } catch (const std::exception& e) {
                std::cout << e.what() << '\n';
            }

            std::filesystem::path path = file_path_str;
            try {
                std::filesystem::resize_file(path, preset_byte_values[FLAGS_byte_select]); //Resize file to specified size.
            } catch (const std::filesystem::filesystem_error& e) {
                std::cout << e.what() << '\n';
            }

            try {
                std::cout << "File size (binary prefix): " << prefix::to_binary_prefix(std::filesystem::file_size(path)) << '\n';
            } catch (const std::filesystem::filesystem_error& e) {
                std::cout << e.what() << '\n';
            } catch (const std::invalid_argument& e) {
                std::cout << e.what() << '\n';
            }

            try {
                std::cout << "File size (decimal prefix): " << prefix::to_decimal_prefix(std::filesystem::file_size(path)) << '\n';
            } catch (const std::filesystem::filesystem_error& e) {
                std::cout << e.what() << '\n';
            } catch (const std::invalid_argument& e) {
                std::cout << e.what() << '\n';
            }
        } else {
            std::cout << "Not using preset values." << '\n';
            //Not using preset values.
            try {
                std::fstream test_fs{file_path_str, std::ios::out}; //Creating a file stream object to output to.
                test_fs.put('a'); //Puts a single character into the test file.
            } catch (const std::exception& e) {
                std::cout << e.what() << '\n';
            }

            std::filesystem::path path = file_path_str;
            try {
                std::filesystem::resize_file(path, FLAGS_fsize); //Resize file to specified size.
            } catch (const std::filesystem::filesystem_error& e) {
                std::cout << e.what() << '\n';
            }

            try {
                std::cout << "File size (binary prefix): " << prefix::to_binary_prefix(std::filesystem::file_size(path)) << '\n';
            } catch (const std::filesystem::filesystem_error& e) {
                std::cout << e.what() << '\n';
            } catch (const std::invalid_argument& e) {
                std::cout << e.what() << '\n';
            }

            try {
                std::cout << "File size (decimal prefix): " << prefix::to_decimal_prefix(std::filesystem::file_size(path)) << '\n';
            } catch (const std::filesystem::filesystem_error& e) {
                std::cout << e.what() << '\n';
            } catch (const std::invalid_argument& e) {
                std::cout << e.what() << '\n';
            }
        }
    } else {
        std::cout << "No arguments were given." << '\n';
        std::exit(EXIT_FAILURE);
    }

    /* while (true) {
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

            try {
                std::fstream test_fs{file_path_str, std::ios::out}; //Creating a file stream object to output to.
                test_fs.put('a'); //Puts a single character into the test file.
            } catch (const std::exception& e) {
                std::cout << e.what() << '\n';
            }

            std::filesystem::path p = file_path_str;
            try {
                std::filesystem::resize_file(p, byte_val); //Resize file to specified size.
            } catch (const std::filesystem::filesystem_error& e) {
                std::cout << e.what() << '\n';
            }

            try {
                std::cout << "File size (binary prefix): " << prefix::to_binary_prefix(std::filesystem::file_size(p)) << '\n';
            } catch (const std::filesystem::filesystem_error& e) {
                std::cout << e.what() << '\n';
            } catch (const std::invalid_argument& e) {
                std::cout << e.what() << '\n';
            }

            try {
                std::cout << "File size (decimal prefix): " << prefix::to_decimal_prefix(std::filesystem::file_size(p)) << '\n';
            } catch (const std::filesystem::filesystem_error& e) {
                std::cout << e.what() << '\n';
            } catch (const std::invalid_argument& e) {
                std::cout << e.what() << '\n';
            }

            break;
        }
        case 1: {
            //Select from a range of preset values.
            std::array<uint64_t, 6> preset_byte_values = {1000, 1024, 1000000, 1048576, 1000000000, 1073741824};
            unsigned int byte_select = 0;

            while (true) {
                    std::cout << "Select one of the preset byte values from the list below:" << '\n';
                    std::cout << "0. " << prefix::to_decimal_prefix(preset_byte_values[0]) << " (1000 B)." << '\n';
                    std::cout << "1. " << prefix::to_binary_prefix(preset_byte_values[1]) << " (1024 B)." << '\n';
                    std::cout << "2. " << prefix::to_decimal_prefix(preset_byte_values[2]) << " (1000000 B)." << '\n';
                    std::cout << "3. " << prefix::to_binary_prefix(preset_byte_values[3]) << " (1048576 B)." << '\n';
                    std::cout << "4. " << prefix::to_decimal_prefix(preset_byte_values[4]) << " (1000000000 B)." << '\n';
                    std::cout << "5. " << prefix::to_binary_prefix(preset_byte_values[5]) << " (1073741824 B)." << '\n';
                    std::cout << "Enter one of the listed values: ";
                    std::cin >> byte_select;
                if (!std::cin) {
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    std::cerr << "\n\nThat's an invalid input! Please try again." << '\n';
                } else if (byte_select >= 0 && byte_select < preset_byte_values.size()) {
                    break;
                } else {
                    std::cout << "\nInvalid selection, try again!" << '\n';
                }
            }

            try {
                std::fstream test_fs{file_path_str, std::ios::out}; //Creating a file stream object to output to.
                test_fs.put('a'); //Puts a single character into the test file.
            } catch (const std::exception& e) {
                std::cout << e.what() << '\n';
            }

            std::filesystem::path p = file_path_str;
            try {
                std::filesystem::resize_file(p, preset_byte_values[byte_select]); //Resize file to specified size.
            } catch (const std::filesystem::filesystem_error& e) {
                std::cout << e.what() << '\n';
            }

            try {
                std::cout << "File size (binary prefix): " << prefix::to_binary_prefix(std::filesystem::file_size(p)) << '\n';
            } catch (const std::filesystem::filesystem_error& e) {
                std::cout << e.what() << '\n';
            } catch (const std::invalid_argument& e) {
                std::cout << e.what() << '\n';
            }

            try {
                std::cout << "File size (decimal prefix): " << prefix::to_decimal_prefix(std::filesystem::file_size(p)) << '\n';
            } catch (const std::filesystem::filesystem_error& e) {
                std::cout << e.what() << '\n';
            } catch (const std::invalid_argument& e) {
                std::cout << e.what() << '\n';
            }

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
    } */
    
    return 0;
}