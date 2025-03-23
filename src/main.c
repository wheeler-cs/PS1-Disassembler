#include "bin_load.h"
#include "disassemble.h"
#include "executable.h"
#include "psx_exe.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    Executable ps1_exe;
    blankinit_exe(&ps1_exe);
    load_exe(argv[1], &ps1_exe);

    Disassembler * disasm;
    disasm = disassemble(&ps1_exe);

    if(disasm != NULL)
    {
        free(disasm);
    }
    dealloc_exe(&ps1_exe);

    printf("<Press Any Key to Exit>");
    getchar();

    return 0;
}