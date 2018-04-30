#ifndef MAZE_H_
#define MAZE_H_

/* Prints a 2D array */
void printArr(int row, int col,int arr[][col]);

/* Find elements being used in order to get side length of matrix */
int findNumMazeElements(char * array, int length); 

/* Fills 1D array full of all of the different characters in text file */
void loadCharArrFromFile(char * buff);

/* Fill array with '~'s, a blank character */
void arrayFill(char * arr);

/* Create a 2D maze array by taken in array from input */
void createMazeMatrix(char * arr, int length, int sideLength, int mz[][sideLength]);

/* Takes in user input to run traceMaze given starting row and column */
void doTraceMaze(int length,int mz[][length]);

/* Traces maze recursively, keeps track of number of steps needed to solve */
void traceMaze(int length, int mz[][length], int row, int col, int count);

#endif
