#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include "maze.h"


int main(){
  char arr[900];
  loadCharArrFromFile(arr);
  for(int i = 0; i < 900; i ++)
    printf("%c", arr[i]);
  printf("\n");
  int numMazeElements;
  numMazeElements = findNumMazeElements(arr,900);
  int sideLength;
  sideLength = (int)(sqrt(numMazeElements));
  
  int mz[sideLength][sideLength];
  
  createMazeMatrix(arr, numMazeElements, sideLength, mz);
  printArr(mz,sideLength,sideLength);
  
}
