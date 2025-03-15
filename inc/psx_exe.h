#ifndef PSX_EXE_H
#define PSX_EXE_H

#include "executable.h"

// Checks for data integrity
#define CHECK_EXE_SIZE  0x01
#define CHECK_MAGIC     0x02


#define PSX_MAGIC "PS-X EXE"

typedef struct
{
    uint8_t  magic[8];
    uint32_t addr_start,
             addr_text,
             size_text,
             addr_stack;
} ExeHeader;


unsigned int validate_exe(Executable *);


#endif
