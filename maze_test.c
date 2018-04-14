#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "maze.h"


int main(){

  FILE * maze;
  int const ROW = 8, COL = 8;
  int mz[ROW][COL];
  char c;
  int row = 0, col = 0;
  char fileName[30];

  //asks for user to imput file
  printf("Please Enter Maze File then Press Enter\n");
  scanf("%s",fileName);

  //opens the given file and reassignes it to a 2 Dimmentional array
  maze = fopen(fileName,"r");
  assert(maze);
  if(maze){
    while((c = getc(maze)) != EOF){
      if(c == '\n')
	continue;
      if(c == '.')
	mz[row][col] = 0;
      else
	mz[row][col] = 1;
      col++;
      if(col == 8){
	row++;
	col = 0;
      }
    }
  }
  printArr(mz,ROW,COL);
  fclose(maze);

}
