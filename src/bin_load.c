#include "bin_load.h"

#include <stdlib.h>


long load_data(char * file_name, uint8_t * data_buffer)
{
    FILE * file_in;
    long file_size;
    file_size = 0;

    // Attempt to load file data
    if((file_in = fopen(file_name, "rb")) != NULL)
    {
        // Allocate memory for loading
        long file_size;
        file_size = get_file_size(file_in);
        data_buffer = malloc(file_size);

        // Couldn't read file
        if(fread(data_buffer, 1, file_size, file_in) <= 0)
        {
            free(data_buffer);
            data_buffer = NULL;
            file_size = 0;
        }

        fclose(file_in);
    }

    return file_size;
}


long get_file_size(FILE * file_ptr)
{
    // Error-checking
    if(file_ptr == NULL)
    {
        return 0;
    }

    // Store current file pointer position
    long current_pos;
    current_pos = ftell(file_ptr);

    // Get size of file
    // TODO: Change this to a more portable way of checking size
    long file_size;
    fseek(file_ptr, 0, SEEK_END); // Not portable
    file_size = ftell(file_ptr);

    // Reset file pointer and return size
    fseek(file_ptr, current_pos, SEEK_SET);
    return file_size;
}
