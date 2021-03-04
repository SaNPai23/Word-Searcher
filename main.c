#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./trie/trie.h"
#include "./lookup/lookup.h"


// Initializes the grid 
char** init_grid(int row, int col){
    int i;
    char **grid = (char**) calloc(row, sizeof(char*));
    for(i = 0; i < row; i++){
        *(grid + i) = (char *) calloc(col, sizeof(char)); 
    }
    return grid;
}


// Convert word to a row of the grid
void parse_input(char **grid, int row, char *buf){
    int col = 0;
    while(buf[col] != '\0'){
        grid[row][col] = (char)buf[col];
        col++;
    }
}

// Accepts the grid as user input
char** get_grid(int *row, int *col){
    
    
    printf("\nEnter the number of rows in the grid:");
    scanf("\n%d", row);
    fflush(stdin);
    printf("\nEnter the number of columns in the grid:");
    scanf("\n%d", col);

    int i, j;
    char buf[*col];
    int c;
    char **grid = init_grid(*row, *col);
    for(i=0; i<*row; i++){
        
        do{
            printf("\nEnter row # %d of the grid (as a single word of length = %d):", i+1, *col);
            
            fflush(stdin);
            scanf("%s", buf);

            if(strlen(buf) != *col)
            printf("\nPlease enter word of length = %d (the number of columns)\n", *col);
        }while(strlen(buf) != *col);
        

        parse_input(grid, i, buf);
    }
    return grid;
}

// Accepts the list of words to be found as user input
char** get_words(int *numwords, int lenword){
    int i;
    printf("\nEnter the number of words to find in the grid:");
    scanf("\n%d", numwords);
    char** words = malloc(*numwords * sizeof(char*));

    for(i = 0; i < *numwords; i++){
        words[i] = malloc(lenword * sizeof(char));
        do{
            fflush(stdin);
            printf("\nEnter word # %d\n", i+1);
            scanf("%s", words[i]);
            
            if(strlen(words[i]) < 1 || strlen(words[i]) >= lenword)
            printf("\nPlease enter a searchable word (0 < length of word <= number of cells in the grid)");

        }while(strlen(words[i]) < 1 || strlen(words[i]) >= lenword);
    }
    return words;
}

// Displays the character grid
void display_grid(char **grid, int row, int col){
  printf("\nMatrix: \n");
    int i,j;
    for(i=0; i<row; i++){
        for(j=0; j<col;j++){
            printf("%c ",grid[i][j]);
        }
        printf("\n");
    }  
}

// Displays the word list
void display_words(char** words, int numwords){
    int i;
    printf("\nWords Entered:");
    for(i=0; i<numwords; i++){
        printf("\n%s", words[i]);
    }
    printf("\n");
}

// Displays the list of words which were found in the gris from the original list of words
void display_result(char** result, int retsize){
    int i;

    printf("\nWords from the list found in the grid:");

    if(retsize == 0)
    printf("\nNone of the given words are in the grid");

    for(i=0; i<retsize; i++){
        printf("\n%s", result[i]);
    }
    printf("\n");
}


void main(){
    int row, col, numwords, returnsize;
    char **grid = get_grid(&row, &col);
    display_grid(grid, row, col);
    char **words = get_words(&numwords, row*col+1);
    display_words(words, numwords);

    char **result = findwords(grid, row, col, words, numwords, &returnsize);
    display_result(result, returnsize);
}