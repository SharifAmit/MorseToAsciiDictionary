#include <stdio.h>
#include "a2m_index.h"

int main(int argc, char* argv[]) {

    if ( argc <=1 ) {
        fprintf(stderr,"Usage: please specify the name of the file with the ascii-to-morse mappings\n");
        return 1;
    }

    char *filename = argv[1];
    A2MLookupTable *t = create_lookup_table(filename);

    if ( t ) {

        // Test if creating the table worked
        print_lookup_table(t);
    
        // We are done with the lookup table
        destroy_lookup_table(t);

    }

    // Success
    return 0;

}
