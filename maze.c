#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "maze.h"

#define MAXMAZESIZE 900
#define SIZE 1
#define NUMELEM 900

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
int findNumMazeElements(char * array, int length) {
  int i,count = 0;
  for(i=0;i<length;i++) {
    if(array[i] != '\n')
      count ++;
    if(array[i]=='~')
      break;
  }
  return count-1;
}

void loadCharArrFromFile(char * buff){
  FILE * mazeFile = NULL;
  char fileName[30];
  
  arrayFill(buff);

  //asks for user to imput file
  printf("Please Enter Maze File then Press Enter\n");
  scanf("%s",fileName);

  mazeFile = fopen(fileName,"r");
  if(!mazeFile){
    printf("File was not correctly oppened");
   
  }

  fread(buff,SIZE,NUMELEM,mazeFile);
  
  /*
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
  fclose(maze);
  return mz;
  */
}

void arrayFill(char * arr){
  for(int i = 0; i < MAXMAZESIZE; i ++)
    arr[i] = '~';
}
