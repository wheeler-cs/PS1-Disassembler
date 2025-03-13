#include "bin_load.h"
#include "executable.h"
#include "psx_exe.h"

int main(int argc, char ** argv)
{
    Executable ps1_exe;
    blankinit_exe(&ps1_exe);
    load_exe(argv[1], &ps1_exe);
    uint32_t failed_checks;
    failed_checks = validate_exe(&ps1_exe);
    dealloc_exe(&ps1_exe);

    printf("Check Return Code: %d", failed_checks);
    getchar();

    return 0;
}