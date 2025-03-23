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


extern const Instr INSTR[];
extern const SpecInstr SPECIAL_INSTR[];


#endif
