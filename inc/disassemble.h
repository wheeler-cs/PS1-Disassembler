#ifndef DISASSEMBLE_H
#define DISASSEMBLE_H

#include "executable.h"
#include "mips.h"
#include "psx_exe.h"


typedef struct
{
    Instruction ** instructions;
    unsigned int instr_size;
} Disassembler;


Disassembler * disassemble(Executable *);


#endif
