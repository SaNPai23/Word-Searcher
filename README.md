# Word-Searcher
Implemented a word finder in C using Trie and DFS Backtracking

Problem Statement:
Design an algorithm which finds a given list of words in a grid (matrix of characters), returns the words which were found in the grid.
The letters for each word can be connected horizontally or vertically. The same letter can be used for multiple words.
Constraints: the grid and the list of words both contain lowercase english alphabets.



Example:

From the list of words: {"cat","apple","ball","dog"} find the ones that are present in the following grid:

a c a d
t x p p
o g e l
b a l l

Result: {"cat", "apple", "ball"}

Explanantion:

Each word's location is highlighted (using capitalisation) below:

"cat":
A C a d
T x p p
o g e l
b a l l

"apple"
a c A d
t x P P
o g E L
b a l l

"ball":
a c a d
t x p p
o g e l
B A L L




Algorithms and Data Structures used:

We make use of backtracking, using a recursive depth-first search (DFS) starting from each cell and simultaneously traverse through all the words which match. Iterating through each word for all the cells of the grid is inefficient.
So, we use a Trie data structure to store all the words that we need to find in the grid, and we traverse through the trie for each cell of the grid.
This increases the efficiency of our searches as we can match all the words simultaneously whilst iterating through the grid.
The trie has been implemented using a hashmap data structure to keep track of each trienode's children. Both, the trie and the hashmap data structures have been implemented in this code.



Time Complexity:

Assumptions: There are 'N' cells in the grid, 'K' words, and the maximum length of a word is 'L'.

Each insertion in the trie takes 'L' time in the worst case, so all insertions take O(L*K) time.

For the backtracking process, in the worst case, we start a DFS from each cell of the grid and traverse the entire grid for each search.
The time for traversal starting from a particular cell would be (4*3^(L-1)). This is beacuse there are 4 directions to explore from the starting cell, and 3 directions for each subsequent cell. This is done assuming the maximum length of a word is 'L', so we match 'L' cells.
Since we do this for each cell in the grid (as we start a DFS traversal from each cell), the time complexity for the complete backtracking algorithm is O(N*(4*3^(L-1))).

SO, the total time complexity is O(L*K + N*(4*3^(L-1))).



Space Complexity:
We store 'K' words, all of maximum length 'L' in a trie for the process. In the worst case, there is no overlap between the words, so there is a trie node for each letter. Hence, the Space Complexity is:
O(L*K).
This space is excluding the grid and list of words themselves, since they are a part of the problem statement.


Instructions to execute the code:
1>$ make
2>$ ./main


Input and output expected:
First, the grid and then the list of words will be taken as user input. The output will be a list of words that were found in the grid.




Sample run of the code (console input and output):



Enter the number of rows in the grid:4

Enter the number of columns in the grid:4

Enter row # 1 of the grid (as a single word of length = 4):acad

Enter row # 2 of the grid (as a single word of length = 4):txpp

Enter row # 3 of the grid (as a single word of length = 4):ogel

Enter row # 4 of the grid (as a single word of length = 4):ball

Matrix:
a c a d
t x p p
o g e l
b a l l

Enter the number of words to find in the grid:4

Enter word # 1
cat

Enter word # 2
apple

Enter word # 3
ball

Enter word # 4
dog

Words Entered:
cat
apple
ball
dog

Words from the list found in the grid:
cat
apple
ball
