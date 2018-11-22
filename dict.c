#include "dict.h"

void dict_insert (DictNode **head, char *original, char *translation) {

    DictNode *node = (DictNode*)malloc(sizeof(DictNode));

    if ( !node ) {
        printf("Out of memmory\n");
        return;
    }

    strncpy(node->original,original,BUF_SIZE);
    strncpy(node->translation,translation,BUF_SIZE);
    node->next = NULL;

    DictNode *previous = NULL;
    DictNode *current = *head;

    // Find the appropriate location in the list where to add the new element
    while ( current != NULL && (strncmp(current->original,original,BUF_SIZE) <= 0) ) {
        previous = current;
        current = current->next;
    }

    // Inserting at the beginning of the list
    if ( previous == NULL ) {

        node->next = *head;
        *head = node;

    } else {

        previous->next = node;
        node->next = current;
    }

}


void dict_remove (DictNode **head, char *original) {

    // First check if you need to delete the first element
    // in the list. The element pointed to by *head. 
    // If so, handle that case
    // Remember to reclaim the space of the deleted element


    // XXX Write your code here XXX


    // Second, find the element to remove
    DictNode *previous = NULL;
    DictNode *current = *head;

    // XXX Write your code here. You should iterate through the list looking for the element XXX


    // Third, check if found element
    if ( !current ) {
        printf("Element not found\n");
    } 

    // Fourth, if you found it, remove it    
    else {
        // XXX Write your code here XXX
    }

}


void dict_print (DictNode *head) {
    
    DictNode *current = head;

    while (current) {
        printf ("%20s -> %s\n",current->original,current->translation);
        current = current->next;
    }

}
