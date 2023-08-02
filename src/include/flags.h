#include <gflags/gflags.h>

//Flag for file size in bytes.
DECLARE_uint64(fsize);

//Flag for using preset values instead of typing in byte value.
DECLARE_bool(use_presets);

//Flag for selecting which preset value to use.
DECLARE_uint32(byte_select);