#ifndef HASHMAP_H_
#define HASHMAP_H_ "hashmap.h"
typedef struct node{
    char key;
    void* val;
    struct node *next;
} node;

typedef struct hashmap{
    int size;
    int count;
    node **array;
}hashmap;

hashmap* inithashmap(int);
void* get(hashmap*, char);
void add(hashmap*, char, void*);
void del(hashmap*, char);

#endif