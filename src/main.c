#include "bin_load.h"
#include "executable.h"
#include "mips.h"
#include "psx_exe.h"

int main(int argc, char ** argv)
{
    Executable ps1_exe;
    blankinit_exe(&ps1_exe);
    load_exe(argv[1], &ps1_exe);
    uint32_t failed_checks;
    failed_checks = validate_exe(&ps1_exe);
    ExeHeader header_data;
    if(!(failed_checks))
    {
        header_data = get_header(&ps1_exe);
        printf("Addr Start: 0x%x\n", header_data.addr_start);
        printf("Addr Text:  0x%x\n", header_data.addr_text);
        printf("Size Text:  0x%x\n", header_data.size_text);
        printf("Addr Stack: 0x%x\n", header_data.addr_stack);
    }
    dealloc_exe(&ps1_exe);

    printf("<Press Any Key to Exit>");
    getchar();

    return 0;
}