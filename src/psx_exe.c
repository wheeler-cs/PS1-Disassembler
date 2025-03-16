#include "psx_exe.h"

#include <stdio.h>
#include <string.h>


ExeHeader get_header(Executable * exe)
{
    ExeHeader header_data;
    if((long unsigned int)exe->data_size >= sizeof(ExeHeader))
    {
        memcpy(&header_data, exe->bin_data, sizeof(ExeHeader));
    }
    return header_data;
}


uint32_t validate_exe(Executable * exe)
{
    uint32_t failed_checks;
    failed_checks = 0x00000000;
    // Executable should be divisible by 2048
    if((exe->data_size % 2048) && !(exe->data_size > 0))
    {
        failed_checks += CHECK_EXE_SIZE;
    }

    if(!(failed_checks & CHECK_EXE_SIZE))
    {
        ExeHeader header_check;
        // Copy header data into struct
        memcpy(&header_check, exe->bin_data, sizeof(ExeHeader));
        if(memcmp(header_check.magic, PSX_MAGIC, 8))
        {
            failed_checks += CHECK_MAGIC;
        }
    }

    return failed_checks;
}
