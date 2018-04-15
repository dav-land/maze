#ifndef MAZE_H_
#define MAZE_H_

/* Prints a 2D array */
void printArr(int row, int col,int arr[][col]);

/* load maze from file */
void loadCharArrFromFile(char * buff);

/* fill array with '~', a blank character*/
void arrayFill(char * arr);

/* find elements being used */
int findNumMazeElements(char * array, int length); 

/* create maze array */
void createMazeMatrix(char * arr, int length, int sideLength, int mz[][sideLength]);

#endif
