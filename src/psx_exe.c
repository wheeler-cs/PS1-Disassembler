#include "psx_exe.h"

#include <string.h>

uint32_t validate_exe(Executable * exe)
{
    uint32_t failed_checks;
    failed_checks = 0x00000000;
    // Executable should be divisible by 2048
    if(exe->data_size % 2048)
    {
        failed_checks += CHECK_MOD_2048;
    }
    // Magic string should be at start
    char magic[8];
    strncpy(magic, (char *)exe->bin_data, 8);
    if(strcmp(magic, PSX_MAGIC))
    {
        failed_checks += CHECK_MAGIC;
    }

    return failed_checks;
}
