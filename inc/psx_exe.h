#ifndef PSX_EXE_H
#define PSX_EXE_H

#include "executable.h"

// Checks for data integrity
#define CHECK_MOD_2048 0x01
#define CHECK_MAGIC    0x02

#define PSX_MAGIC "PS-X EXE"


unsigned int validate_exe(Executable *);


#endif
