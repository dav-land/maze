#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


void printArr(char arr[8][8],int row, int col){
  for(int i = 0; i < row; i ++){
    for(int j = 0; j < col; j++){
      printf("%c",arr[i][j]);
      if(j+1 == col)
	printf("\n");
    }
  }
}


int main(){
  //import the mazep just to start
  FILE * maze;
  int const ROW = 8, COL = 8;
  char mz[ROW][COL];
  char c;
  int row = 0, col = 0;
  char fileName[30];

  printf("Please Enter Maze File then Press Enter\n");
  scanf("%s",fileName);
  
  maze = fopen(fileName,"r");
  if(maze){
    while((c = getc(maze)) != EOF){
      if(c == '\n')
	continue;
      mz[row][col] = c;
      col++;
      if(col == 8){
	row++;
	col = 0;
      }
    }
  }
  printArr(mz,ROW,COL);
}
