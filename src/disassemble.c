#include "disassemble.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


Disassembler * disassemble(Executable * exe)
{
    long i;
    uint32_t word;

    for(i = 2047; i < exe->data_size; i += 4)
    {
        memcpy(&word, &exe->bin_data[i], sizeof(Instruction));
    }

    return NULL;
}
