#ifndef BIN_LOAD_H
#define BIN_LOAD_H

#include <stdint.h>
#include <stdio.h>


/**
 * @brief Load binary data from disk into memory.
 * 
 * @param file_name: Fully-qualified or relative path to file to be loaded.
 * @param data_buffer: Unallocated pointer set to point to data loaded from file.
 * 
 * @return The size of the file (in bytes) loaded into memory.
 * @retval 0: Nothing was loaded from the file.
 */
long load_data(char *, uint8_t **);

/**
 * @brief Get the size of the file referenced by the pointer, in bytes.
 * 
 * @param file_ptr: Pointer to valid file stream.
 * 
 * @return The size of the file referenced by the provided pointer, in bytes.
 * @retval 0: File was empty or the pointer provided was NULL.
 * 
 * @warning This currently uses a non-portable call to fseek using SEEK_END.
 */
long get_file_size(FILE *);

#endif
