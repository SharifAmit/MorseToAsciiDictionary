#include <string.h>
#include <ctype.h>
#include "a2m_index.h" 

// --------------------------------------------------
/**
 * Convert an ascii character into an integer between 0 and NB_CHARS
 * @param ascii The ascii character to convert
 * @return The index for the given ascii character
 */
int hash(char ascii) {
   int x= (int)ascii-97;
   return x;
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
    int i = hash(ascii);
    int j;
    for(j=0;j<4;j++)
    {
    lookup_table->table[i][j]=*(morse+j);
    }
    
}


// --------------------------------------------------
A2MLookupTable* create_lookup_table(char *filename) {

    // Allocating the lookup table on the heap
    A2MLookupTable *lookup_table = (A2MLookupTable*)malloc(sizeof(A2MLookupTable));    

    // Write your code here
    int max=6;
    char c[max];
    char ascii;
    char *morse; 
    FILE *fp1 =fopen(filename,"r");
    while(fgets(c,max,fp1) !=NULL)
    {
     ascii = c[0];
     morse = &c[2];
     put_ascii_morse(lookup_table, ascii, morse);
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
    int i;
    int j;
    for(i=0;i<26;i++)
    {
     for(j=0;j<5;j++)
     {
      printf("%c",table->table[i][j]);
     }
     printf("\n");
    }
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
    int i = hash(ascii);
    char *morse = &lookup_table->table[i][0];
    return morse;
}

// --------------------------------------------------
bool check_ascii_string(char* ascii) {
    int i=0;
    int flag=0;
    // Write your code here
    while(*(ascii + i) !=0){
     if( (*(ascii + i) >= 97 && *(ascii + i) <=122) || (*(ascii+i)==' ') )
      {
        i++;
      }
      i++;
      flag++;
    }
    if(flag==0){
     return true;
   }
   else{
    return false;
   }
}


// --------------------------------------------------
void ascii_to_morse(A2MLookupTable *lookup_table, 
                    char* morse, int morse_buffer_size,
                    char* ascii) {
       // Write your code here
       char x[morse_buffer_size);
       if(check_ascii_string(ascii)==true){
         int i=0;
         while(*(ascii + i) !=0){
                  if(*(ascii+i)==32)
                  {
                   strcat("/");
                  }
                  else{
                   strcat(x,get_morse(lookup_table, ascii);
            }
        }
     }
     else{

     }  
}


