#include <string.h>
#include <ctype.h>
#include "a2m_index.h"
#define del " " 

// --------------------------------------------------
/**
 * Convert an ascii character into an integer between 0 and NB_CHARS
 * @param ascii The ascii character to convert
 * @return The index for the given ascii character
 */
int hash(char ascii) {
   int a [27];
   int x= (int)ascii-96;
   int a[x]=x;
   return a[x];
    // Write your code here
}


// --------------------------------------------------
/**
 * Insert a mapping between an ascii character and a morse-code
 * string into the A2MLookupTable.
 * Careful: this function should make a copy of the morse
 * code string into the lookup table 
 * @param lookup_table Pointer to the lookup table
 * @param ascii The ascii character
 * @param morese The morse code string
 */
void put_ascii_morse(A2MLookupTable *lookup_table, char ascii, char *morse) {

    // Write your code here
}


// --------------------------------------------------
A2MLookupTable* create_lookup_table(char *filename) {

    // Allocating the lookup table on the heap
    A2MLookupTable *lookup_table = (A2MLookupTable*)malloc(sizeof(A2MLookupTable));    

    // Write your code here
    int max=8
    
    char c[max];
    char ascii[max-1]; 
    FILE *fp1 =fopen(filename,"r");
    while(fgets(c,max,fp1) !=NULL)
    {
     ascii = strtok(c, del);
     put_ascii_morse(lookup_table, ascii,  morse);
     
    
    }
    fclose(fp1);
    return lookup_table;
}


// --------------------------------------------------
void destroy_lookup_table(A2MLookupTable *lookup_table) {

    if ( lookup_table ) {
        free (lookup_table);
    }

}

// --------------------------------------------------
void print_lookup_table(A2MLookupTable *table) {

    // Write your code here
}


// --------------------------------------------------
/**
 * Given an ascii character, returns a pointer to the
 * string with the corresponding morse code translation
 * @param lookup_table Pointer to the lookup table
 * @param ascii The ascii character
 * @return Pointer to the morse code string
 */
char* get_morse(A2MLookupTable *lookup_table, char ascii) {

    // Write your code here

}

// --------------------------------------------------
bool check_ascii_string(char* ascii) {

    // Write your code here
}


// --------------------------------------------------
void ascii_to_morse(A2MLookupTable *lookup_table, 
                    char* morse, int morse_buffer_size,
                    char* ascii) {
   
    // Write your code here

}


