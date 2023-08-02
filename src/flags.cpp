#include "include/flags.h"
#include <gflags/gflags.h>
#include <limits>
#include <array>

//Validator for byte size value range.
static bool CheckByteValue(const char *flagname, const uint64_t value) {
    if (value >= 0 && value <= 10737418240) { //10 Gibibytes.
        return true;
    }
    printf("Invalid value for --%s: %d\n", flagname, (int)value);
    return false;
}

//Validator for selection of byte value preset option.
static bool CheckSelectValue(const char *flagname, const uint32_t value) {
    if (value >= 0 && value < 6) {
        return true;
    }
    printf("Invalid value for --%s: %d\n", flagname, (int)value);
    return false;
}

//Flag for file size in bytes.
DEFINE_uint64(fsize, 0, "Flag for file size in bytes.");
DEFINE_validator(fsize, &CheckByteValue);

//Flag for using preset values instead of typing in byte value.
DEFINE_bool(use_presets, false, "Flag for using preset values instead of typing in byte value.");

//Flag for selecting which preset value to use.
DEFINE_uint32(byte_select, 0, "Flag for selecting which preset value to use.");
DEFINE_validator(byte_select, &CheckSelectValue);