#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include "maze.h"


int main(){
  char arr[900];
  loadCharArrFromFile(arr);
  int numMazeElements  = findNumMazeElements(arr,900);
  int sideLength = (int)(sqrt(numMazeElements));
  int mz[sideLength][sideLength];
  createMazeMatrix(arr, numMazeElements, sideLength, mz);
  printArr(sideLength,sideLength,mz);
  traceMaze(sideLength,mz,0,1,-1);
}
