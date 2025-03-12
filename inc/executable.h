#ifndef EXECUTABLE_H
#define EXECUTABLE_H

#include <stdint.h>

typedef struct
{
    uint8_t * bin_data;
    long data_size;
} Executable;


void blankinit_exe(Executable *);
long load_exe(char *, Executable *);
void dealloc_exe(Executable *);


#endif
