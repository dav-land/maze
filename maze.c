#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "maze.h"


/*
The is a function that prints out the array that has been made
 */
void printArr(int arr[8][8],int row, int col){
  for(int i = 0; i < row; i ++){
    for(int j = 0; j < col; j++){
      printf("%d",arr[i][j]);
      if(j+1 == col)
	printf("\n");
    }
  }
}

/* 
Finds which elements are used in the array, we defined '~' to be unused
*/
int findNumMazeElements(int * array, int length) {
  int i;
  for(i=0;i<length;i++) {
    if(array[i]=='~') break;
  }
  return i;
}
