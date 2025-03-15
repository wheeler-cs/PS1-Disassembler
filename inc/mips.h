#ifndef MIPS_H
#define MIPS_H

#include <stdint.h>

// Instruction data
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


/**
 * Instruction Types
 * -----------------
 * op: Opcode
 * rs: Source register
 * rt: Destination register/branch condition
 * immediate: Immediate value
 * target: Target jump address
 * rd: Destination register
 * shamt: Bitwise shift quantity
 * funct: Function
 */
typedef struct
{
    uint32_t data;
} Instr_Generic;

typedef struct
{
    uint32_t op: 6;
    uint32_t rs: 5;
    uint32_t rt: 5;
    uint32_t immediate: 16;
} Instr_IType;

typedef struct
{
    uint32_t op: 6;
    uint32_t target: 26;
} Instr_JType;

typedef struct
{
    uint32_t op: 6;
    uint32_t rs: 5;
    uint32_t rt: 5;
    uint32_t rd: 5;
    uint32_t shamt: 5;
    uint32_t funct: 6;
} Instr_RType;

// All instructions in MIPS are 32 bits in size
typedef union
{
    Instr_Generic generic;
    Instr_IType i_type;
    Instr_JType j_type;
    Instr_RType r_type;
} Instruction;


// NOTE: Octals are used for the opcode because each is 6 bits
// Also the reference I'm using uses octals,
// see https://stuff.mit.edu/afs/sipb/contrib/doc/specs/ic/cpu/mips/r3051.pdf
const Instr INSTR[] =
{
    {.upper6 = 010, .mnemonic = "addi"},
    {.upper6 = 011, .mnemonic = "addiu"},
    {.upper6 = 014, .mnemonic = "andi"},
    {.upper6 = 001, .mnemonic = "bcond"},
    {.upper6 = 004, .mnemonic = "beq"},
    {.upper6 = 007, .mnemonic = "bgtz"},
    {.upper6 = 006, .mnemonic = "blez"},
    {.upper6 = 005, .mnemonic = "bne"},
    {.upper6 = 020, .mnemonic = "cop0"},
    {.upper6 = 021, .mnemonic = "cop1"},
    {.upper6 = 022, .mnemonic = "cop2"},
    {.upper6 = 023, .mnemonic = "cop3"},
    {.upper6 = 002, .mnemonic = "j"},
    {.upper6 = 003, .mnemonic = "jal"},
    {.upper6 = 040, .mnemonic = "lb"},
    {.upper6 = 044, .mnemonic = "lbu"},
    {.upper6 = 041, .mnemonic = "lh"},
    {.upper6 = 045, .mnemonic = "lhu"},
    {.upper6 = 017, .mnemonic = "lui"},
    {.upper6 = 043, .mnemonic = "lw"},
    {.upper6 = 060, .mnemonic = "lwc0"},
    {.upper6 = 061, .mnemonic = "lwc1"},
    {.upper6 = 062, .mnemonic = "lwc2"},
    {.upper6 = 063, .mnemonic = "lwc3"},
    {.upper6 = 042, .mnemonic = "lwl"},
    {.upper6 = 046, .mnemonic = "lwr"},
    {.upper6 = 015, .mnemonic = "ori"},
    {.upper6 = 050, .mnemonic = "sb"},
    {.upper6 = 051, .mnemonic = "sh"},
    {.upper6 = 012, .mnemonic = "slti"},
    {.upper6 = 013, .mnemonic = "sltiu"},
    {.upper6 = 000, .mnemonic = "special"},
    {.upper6 = 053, .mnemonic = "sw"},
    {.upper6 = 070, .mnemonic = "swc0"},
    {.upper6 = 071, .mnemonic = "swc1"},
    {.upper6 = 072, .mnemonic = "swc2"},
    {.upper6 = 073, .mnemonic = "swc3"},
    {.upper6 = 052, .mnemonic = "swl"},
    {.upper6 = 056, .mnemonic = "swr"},
    {.upper6 = 016, .mnemonic = "xori"},
};


const SpecInstr SPECIAL_INSTR[] =
{
    {.lower6 = 040, .mnemonic = "add"},
    {.lower6 = 041, .mnemonic = "addu"},
    {.lower6 = 044, .mnemonic = "and"},
    {.lower6 = 015, .mnemonic = "break"},
    {.lower6 = 032, .mnemonic = "div"},
    {.lower6 = 033, .mnemonic = "divu"},
    {.lower6 = 011, .mnemonic = "jalr"},
    {.lower6 = 010, .mnemonic = "jr"},
    {.lower6 = 020, .mnemonic = "mfhi"},
    {.lower6 = 022, .mnemonic = "mflo"},
    {.lower6 = 021, .mnemonic = "mthi"},
    {.lower6 = 023, .mnemonic = "mtlo"},
    {.lower6 = 030, .mnemonic = "mult"},
    {.lower6 = 031, .mnemonic = "multu"},
    {.lower6 = 047, .mnemonic = "nor"},
    {.lower6 = 045, .mnemonic = "or"},
    {.lower6 = 000, .mnemonic = "sll"},
    {.lower6 = 004, .mnemonic = "sllv"},
    {.lower6 = 052, .mnemonic = "slt"},
    {.lower6 = 053, .mnemonic = "sltu"},
    {.lower6 = 003, .mnemonic = "sra"},
    {.lower6 = 007, .mnemonic = "srav"},
    {.lower6 = 002, .mnemonic = "srl"},
    {.lower6 = 006, .mnemonic = "srlv"},
    {.lower6 = 042, .mnemonic = "sub"},
    {.lower6 = 043, .mnemonic = "subu"},
    {.lower6 = 014, .mnemonic = "syscall"},
    {.lower6 = 046, .mnemonic = "xor"},
};

#endif
