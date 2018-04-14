#ifndef MAZE_H_
#define MAZE_H_

/* Prints a 2D array */
void printArr(int arr[8][8],int row, int col);

/* load maze from file */
int loadMaze();

/* fill array with '~' */
void arrayFill(char * arr);

/* find elements being used */
int findNumMazeElements(char * array, int length); 

#endif
