#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "maze.h"


#define MAXMAZESIZE 900
#define SIZE 1
#define NUMELEM 900


/**
The is a function that prints out the array that has been made with given dimention
 */
void printArr(int row, int col,int arr[][col]){
  for(int i = 0; i < row; i ++){
    for(int j = 0; j < col; j++){
      printf("%d",arr[i][j]);
      if(j+1 == col)
	printf("\n");
    }
  }
}


/** 
Finds which elements are used in the array, we defined '~' to be unused.
*/
int findNumMazeElements(char * array, int length) {
  int i,count = 0;
  for(i=0;i<length;i++) {
    if(array[i] != '\n') count ++;
    if(array[i]=='~') break;
  }
  return i;
}


/**
This is a function that asks the user for the name of the text file of the maze then loads up the array full of chars in the order they are read from the file.
 */
void loadCharArrFromFile(char * buff){
  FILE * mazeFile = NULL;
  char fileName[30];
  arrayFill(buff);

  //asks for user to imput file
  printf("Please Enter Maze File then Press Enter\n");
  scanf("%s",fileName);

  mazeFile = fopen(fileName,"r");
  
  if(!mazeFile)
    printf("File was not correctly oppened");
  
  fread(buff,SIZE,NUMELEM,mazeFile);
  fclose(mazeFile);
}


/**
Fills the initial array, so we know what is inside
 */
void arrayFill(char * arr){
  for(int i = 0; i < MAXMAZESIZE; i ++) arr[i] = '~';
}


/**
This takes the input parameters and then makes and fills a 2D array in order to use when solving the Maze.
 */
void createMazeMatrix(char * arr, int length, int sideLength, int mz[][sideLength]) {
  int row=0, col=0;
  char c;
  
  for (int i = 0; i < length; i++){
    c = arr[i];
    
    if(c == '\n') continue;
    if(c == '.') mz[row][col] = 0;
    else mz[row][col] = 1;
    
    col++;
    if(col == sideLength){
      row++;
      col = 0;
    }
  }
}
