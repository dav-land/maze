#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <math.h>
#include "maze.h"
/*
 * A solution to the maze is defined as getting off of the maze in any directio
 * does not include if a starting point is on the side.
 */

int main(){
  char arr[900];
  loadCharArrFromFile(arr);

  int numMazeElements  = findNumMazeElements(arr,900);
  int sideLength = (int)(sqrt(numMazeElements));
  int mz[sideLength][sideLength];

  createMazeMatrix(arr, numMazeElements, sideLength, mz);
  printArr(sideLength,sideLength,mz);

  doTraceMaze(sideLength, mz);
  printf("Done, if solution couldn't be found nothing is printed\n");
}
