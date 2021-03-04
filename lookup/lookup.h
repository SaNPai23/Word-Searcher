#ifndef LOOKUP_H_
#define LOOKUP_H_
#include "../trie/trie.h"

void dfs_lookup(trienode*, char**, int, int, int, int, char*, int, char**, int*);
char** findwords(char**, int, int, char **, int, int*);

#endif