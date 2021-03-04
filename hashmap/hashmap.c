#include<stdio.h>
#include<stdlib.h>
#include "hashmap.h"


// Initializes a new hashmap node
hashmap* inithashmap(int size){
    hashmap *map = (hashmap*) malloc(sizeof(hashmap));
    map->array = (node**) calloc(size, sizeof(node*));
    int i;
    for(i = 0; i < size; i++){
        map->array[i] = (node*)malloc(sizeof(node));
        map->array[i]->key = '\0';
        map->array[i]->val = NULL;
        map->array[i]->next = NULL;
    }
    map->size = size;
    map->count = 0;
    return map;
}

// Gives a hashcode corresponding to given key
int gethashcode(char key, int size){
    int primeno = 47;
    return ((int) key + primeno) % size;
}

// Finds whether the given (key, value) pair exists in the map
node* findnode(node** array, char key, int index){
    node *current = array[index];
    while(current!=NULL){
        if(current->key == key)
            return current;
        current = current->next;
    }
    return NULL;
}

// Gets the value for the given key from the hashmap
void* get(hashmap *map, char key){
    node *current;
    int index = gethashcode(key, map->size);
    current = (node*)findnode(map->array, key, index);
    if(current == NULL)
        return NULL;
    return current->val;
}

// Adds a new (key, value) pair to the hashmap
void add(hashmap* map, char key, void* value){
    int index = gethashcode(key, map->size);
    node* curr = findnode(map->array, key, index);
    
    if (curr == NULL){
        node *newnode, *head;

        head = map->array[index];
        newnode = (node*) malloc(sizeof(node));

        newnode->key = key;
        newnode->val = value;
        newnode->next = head->next;
        head->next = newnode;

        map->count++;
    }

    else{
        curr->val = value;
    }

}

// Removes a (key, value) pair from the hashmap
// Unused currently
void del(hashmap* map, char key){
    int index = gethashcode(key, map->size);
    node* delnode = findnode(map->array, key, index);
    if(delnode!=NULL){
        node *curr = map->array[index];
        while(curr->next != delnode){
            curr = curr->next;
        }
        curr->next = delnode->next;
        free(delnode);
        map->count--;

    }
}