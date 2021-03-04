#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../trie/trie.h"
#include "lookup.h"

#define resultsize 100
// Driver function for dfs lookup, called from main
char** findwords(char** grid, int rowsize, int colsize, char **words, int wordssize, int* returnsize){
    *returnsize = 0;
    int i, j;
    trienode *root = inittrienode('*');


    // Add all words to be found into the trie
    for(i = 0; i < wordssize; i++){
        addtotrie(root, words[i]);
    }

    // Allocating a high amount of memory for number of results, can be modified to use realloc depending on number of words found
    char **result = calloc(resultsize, sizeof *result);
    for (int i = 0; i < resultsize; i++) {
        // Allocating the max possible length for each word
        result[i] = calloc(rowsize * colsize + 1, sizeof(char));
    }

    // Call the recursive function to perform a dfs for each cell of the grid and record the results in 'result'
    for (i = 0; i < rowsize; i++) {
        for (j = 0; j < colsize; j++) {
            int cap = (rowsize * colsize) + 1;
            char word[cap];
            dfs_lookup(root, grid, rowsize, colsize, i, j, word, 0, result, returnsize);
        }
    }
    return result;
}


// Recursive function which performs the dfs
void dfs_lookup(trienode *node, char **grid, int rowsize, int colsize, int row, int col, char *word, int wordindex, char **result, int *returnsize){

    char current_char = grid[row][col];
    trienode *child = (trienode*)get(node->children, current_char);
    
    // Base case of recursion: the grid cell is already explored OR the character is not present in this location of the trie
    if(grid[row][col] == '#' || node->children->count == 0 || child == NULL){
        return;
    }

    // Add current grid character to the word being formed
    word[wordindex] = current_char;

    // If this character marks the end of a word in the trie, it means we have found the word in the grid. Add it to results.
    if(child->endofword){
        word[wordindex+1] = '\0';
        
        memcpy(result[(*returnsize)++], word, wordindex + 2); // Accounting for null character in the end
        child->endofword = false;
    }

    // Mark this grid cell as visited, so we don't reuse it for the same word.
    grid[row][col] = '#';

    // Call the function recursively on vertically and horizontally adjacent grid cells, if within bounds.
    if (row < rowsize - 1) dfs_lookup(child, grid, rowsize, colsize, row + 1, col, word, wordindex+1, result, returnsize); 
    if (row > 0) dfs_lookup(child, grid, rowsize, colsize, row - 1, col, word, wordindex+1, result, returnsize);
    if (col < colsize - 1) dfs_lookup(child, grid, rowsize, colsize, row, col + 1, word, wordindex+1, result, returnsize);
    if (col > 0) dfs_lookup(child, grid, rowsize, colsize, row, col - 1, word, wordindex+1, result, returnsize);

    // Restore the current grid character for the next search.
    grid[row][col] = current_char;
}

