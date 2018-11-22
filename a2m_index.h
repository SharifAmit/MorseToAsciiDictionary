#ifndef A2M_INDEX_h
#define A2M_INDEX_h

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NB_CHARS 26
#define MORSE_MAX 4

#define MIN_ASCII 97
#define MAX_ASCII 122

/**
 * Table mapping the 26 ascii characters 
 * from the English alphabet to
 * their corresponding morse code strings
 */
typedef struct a2m_lookup_table {
    char table[NB_CHARS][MORSE_MAX+1]; 

} A2MLookupTable;


/**
 * Creates the ascii-to-morse lookup table
 * from a file containing the mapping between letters
 * in the English alphabet and morse code strings
 * This function assumes that if reading from the file
 * succeeds, the content of the file is valid: it actually
 * contains the mappings for all letters from 'a' to 'z'. 
 * @param filename The name of the file containing the ascii
 * to morse-code mappings
 * @return Pointer to a heap-allocated lookup table
 * or NULL if the table could not be created 
 **/
A2MLookupTable* create_lookup_table(char *filename);


/**
 * Frees the space associated with an A2MLookupTable structure
 * @param pointer to a heap-allocated lookup table
 * @return nothing
 **/
void destroy_lookup_table(A2MLookupTable *lookup_table);


/**
 * Pretty-prints the content of an A2MLookupTable structure
 * @param table Pointer to the A2MLookupTable structure to display 
 */
void print_lookup_table(A2MLookupTable *lookup_table);


/**
 * Verifies that a given string contains only characters
 * between MIN_ASCII and MAX_ASCII (inclusive)
 * Prints a message if it enounters an invalid character
 * @param ascii The null terminated string to check
 * @return true if the string contains only valid characters
 * and false otherwise
 */
bool check_ascii_string(char* ascii);


/**
 * Converts a valid ascii string into a morse-code string
 * Writes only as many ascii letters as can fit in the buffer
 * Adds a null character at the end of the morse-code string
 * Assumes all characters are valid.
 * @param lookup_table The lookup table with mappings from ascii to morse-code
 * @param morse The buffer where the morse-code string should be written
 * @param morse_buffer_size The size of the morse buffer
 * @param ascii The null terminated ascii string to convert
 * @return nothing
 */
void ascii_to_morse(A2MLookupTable *lookup_table, 
                    char* morse, int morse_buffer_size,
                    char* ascii);



#endif
