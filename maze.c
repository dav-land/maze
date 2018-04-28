#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "maze.h"


#define MAXMAZESIZE 900
#define SIZE 1


/**
The is a function that prints out the array that has been made with given dimention
 */
void printArr(int row, int col,int arr[][col]){
  for(int i = 0; i < row; i ++){
    for(int j = 0; j < col; j++){
      if(arr[i][j]==2)
	printf("%s%c","\x1B[32m",175);
      else if(arr[i][j] == 1)
	printf("%s0","\x1B[31m");
      else if(arr[i][j] == 0)
	printf("%s0","\x1B[0m");
      if(j+1 == col)
	printf("\n");
    }
  }
  printf("%s\n","\x1B[0m");
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

/* 
Finds if the maze contains a 2, which means there is a solution
*/
int solutionFound(int length, int mz[][length]) {
  for (int i=0; i<length; i++) {
    for (int j=0;j<length; j++) {
      if (mz[i][j] == 2) return 1;
    }
  }

  return 0;
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
  
  fread(buff,SIZE,MAXMAZESIZE,mazeFile);
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

/**
function to take in user input for the entrance to the maze.
 */
void doTraceMaze(int length, int mz[][length]){
  int startRow,startCol;
  printf("Please enter starting row.\n");
  scanf("%d",&startRow);
  printf("Please enter starting column.\n");
  scanf("%d",&startCol);
  traceMaze(length,mz,startRow,startCol,0);
}

/**
this function recursivly finds the solution to a maze
 */
void traceMaze(int length,int mz[][length],int row,int col,int count){
  if(row == length  || col == -1 || col == length || row ==-1){
    printArr(length,length,mz);
    printf("%d, %d\n",row,col);
    printf("Number of steps: %d\n\n",count-1);
    printf("Success!!\n");
  }else if(mz[row][col] != 0){
    //do nothing
  }else{
    mz[row][col] = 2;
    //  printf("%d, %d\n",row,col);
    traceMaze(length,mz,row + 1,col,count+1);
    traceMaze(length,mz,row,col + 1,count+1);
    traceMaze(length,mz,row,col - 1,count+1);
    traceMaze(length,mz,row - 1,col,count+1);
    mz[row][col] = 0;
  }
}
