#ifndef MAZE_H_
#define MAZE_H_

/* Prints a 2D array */
void printArr(int row, int col,int arr[][col]);

/* Fills 1D array full of all of the different characters in text file*/
void loadCharArrFromFile(char * buff);

/* fill array with '~', a blank character*/
void arrayFill(char * arr);

/* find elements being used in order to get side length of matrix */
int findNumMazeElements(char * array, int length); 

/* create a 2D maze array */
void createMazeMatrix(char * arr, int length, int sideLength, int mz[][sideLength]);

#endif
