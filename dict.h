#ifndef DICT_H
#define DICT_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define BUF_SIZE 4096

typedef struct distNode {

    char original[BUF_SIZE];
    char translation[BUF_SIZE];

    struct distNode *next;

} DictNode;


void dict_insert (DictNode **head, char *original, char *translation);

void dict_remove (DictNode **head, char *original);

void dict_print (DictNode *head);


#endif
