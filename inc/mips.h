#ifndef MIPS_H
#define MIPS_H

#include <stdint.h>

typedef struct
{
    uint8_t upper6;
    char * mnemonic;
} Instr;

typedef struct
{
    uint8_t lower6;
    char * mnemonic;
} SpecInstr;

typedef struct
{
    uint32_t;
} Instr_IType;

// NOTE: Octals are used for the opcode because each is 6 bits
// Also the reference I'm using uses octals,
// see https://stuff.mit.edu/afs/sipb/contrib/doc/specs/ic/cpu/mips/r3051.pdf

const Instr INSTR[] =
{
    {.upper6 = 011, .mnemonic = "addiu"},
    {.upper6 = 004, .mnemonic = "beq"},
    {.upper6 = 005, .mnemonic = "bne"},
    {.upper6 = 003, .mnemonic = "jal"},
    {.upper6 = 002, .mnemonic = "j"},
    {.upper6 = 001, .mnemonic = "li"},
    {.upper6 = 017, .mnemonic = "lui"},
    {.upper6 = 043, .mnemonic = "lw"},
    {.upper6 = 053, .mnemonic = "sw"},
};


const SpecInstr SPECIAL_INSTR[] =
{
    {.lower6 = 010, .mnemonic = "jr"},
    {.lower6 = 000, .mnemonic = "nop"},
};

#endif
