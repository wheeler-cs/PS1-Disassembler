#include "bin_load.h"
#include "executable.h"

#include <stdlib.h>


void blankinit_exe(Executable * exe)
{
    exe->bin_data = NULL;
    exe->data_size = 0;
}


void dealloc_exe(Executable * exe)
{
    if(exe->bin_data != NULL)
    {
        free(exe->bin_data);
        exe->bin_data = NULL;
    }

    exe->data_size = 0;
}


long load_exe(char * file_name, Executable * exe)
{
    exe->data_size = load_data(file_name, exe->bin_data);

    return exe->data_size;
}
