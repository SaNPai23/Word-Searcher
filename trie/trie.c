#include <stdio.h>
#include <stdlib.h>
#include "trie.h"


// Initialize a new trie node
trienode* inittrienode(char ch){
    trienode *node = (trienode*) malloc(sizeof(trienode));
    node->ch = ch;
    node->children = inithashmap(26);
    node->endofword = false;
}


// Add given word to the trie
void addtotrie(trienode* root, char word[]){
    trienode *curr, *child;
    int i = 0;
    curr = root;
    while (word[i] != '\0'){
        trienode *node = (trienode*)get(curr->children, word[i]);

        if(node == NULL){
            trienode *newnode = inittrienode(word[i]);
            add(curr->children, word[i], newnode);
            curr = newnode;
        }
        else{
            curr = node;
        }
        i++;
    }
    curr->endofword = true;
}

