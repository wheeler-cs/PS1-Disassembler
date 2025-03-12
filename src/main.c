#include "bin_load.h"
#include "executable.h"

int main(int argc, char ** argv)
{
    Executable ps1_exe;
    blankinit_exe(&ps1_exe);
    load_exe(argv[1], &ps1_exe);
    dealloc_exe(&ps1_exe);

    getchar();

    return 0;
}