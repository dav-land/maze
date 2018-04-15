#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "maze.h"


int main(){
  char arr[900];
  loadCharArrFromFile(arr);
  for(int i = 0; i < 900; i ++)
    printf("%c", arr[i]);
  printf("\n");
  printf("%d",findNumMazeElements(arr,900));
  
}
