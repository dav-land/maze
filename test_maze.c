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
  doTraceMaze(sideLength, mz);
  if (solutionFound(sideLength, mz)) {
      printf("Found a solution\n");
    }
  else {
    printf("No solution found\n");
  }

  printf("Done\n");

}
