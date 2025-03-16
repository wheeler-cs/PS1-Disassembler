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
    uint64_t unk_0x08;
    uint32_t addr_start,
             unk_0x14,
             addr_text,
             size_text;
    uint32_t unk_0x30[4];
    uint32_t addr_stack;
} ExeHeader;


ExeHeader    get_header  (Executable *);
unsigned int validate_exe(Executable *);


#endif
