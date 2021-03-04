#ifndef TRIE_H_
#define TRIE_H_
#include "../hashmap/hashmap.h"
#include <stdbool.h>

typedef struct trienode{
    char ch;
    bool endofword;
    hashmap *children;
}trienode;

trienode* inittrienode(char);
void addtotrie(trienode*, char[]);

#endif