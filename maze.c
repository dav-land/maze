#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "maze.h"

// hard coded max length to be read and size of each char input
#define MAXMAZESIZE 900
#define SIZE 1


/*
The is a function that prints out the array that has been made with given dimention
 */
void printArr(int row, int col,int arr[][col]){
  // loop through each element
  for(int i = 0; i < row; i ++){
    for(int j = 0; j < col; j++){
      if(arr[i][j]==2)
	printf("%sO","\x1B[32m"); // green 0
      else if(arr[i][j] == 1){
        if (i == 0 || i == row-1)
	  printf("%s_","\x1B[31m");
	else
	  printf("%s|","\x1B[31m"); // red line
      }
      else if(arr[i][j] == 0)
	printf("%sO","\x1B[0m"); // white 0
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
    if(array[i]=='~') break; // first unsed element, stop looping through
  }
  return i;
}


/**
This is a function that asks the user for the name of the text file of the maze
then loads up the array full of chars in the order they are read from the file.
 */
void loadCharArrFromFile(char * buff){
  FILE * mazeFile = NULL;
  char fileName[30];
  arrayFill(buff);

  //asks for user to imput file
  printf("Please Enter Maze File then Press Enter. The maze file must contain
  .'s for empty spaces and 1's for walls. The file must also be a square that is
  up to 29x29.\n");
  scanf("%s",fileName);

  mazeFile = fopen(fileName,"r");

  // make sure mazeFile was opened
  if(!mazeFile) {
    printf("File was not correctly oppened");
    return;
  }

  // read into the buffer array
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
This takes the input parameters and then makes and fills a 2D array in order to
use when solving the Maze.
 */
void createMazeMatrix(char * arr, int length, int sideLength, int mz[][sideLength]) {
  int row=0, col=0;
  char c;

  // loop through
  for (int i = 0; i < length; i++){
    c = arr[i];

    if(c == '\n') continue;
    if(c == '.') mz[row][col] = 0; // open path
    else mz[row][col] = 1; // wall

    col++;
    if(col == sideLength){
      row++;
      col = 0;
    }
  }
}

/**
function to take in user input for the entrance to the maze, and then calls
function to solve maze
 */
void doTraceMaze(int length, int mz[][length]){
  int startRow,startCol;
  printf("Please enter starting row.\n");
  scanf("%d",&startRow);
  printf("Please enter starting column.\n");
  scanf("%d",&startCol);
  if(mz[startRow][startCol] != 0){
    printf("Invalid Starting Point.\n");
    return;
  }
  // solve the maze
  traceMaze(length,mz,startRow,startCol,0);
}

/**
this function recursivly finds the solution to a maze
 */
void traceMaze(int length,int mz[][length],int row,int col,int count){
  // end of maze has been reached
  if((row == length  || col == -1 || col == length || row ==-1)){
    if(count > 1){ // make sure movement did occur, starting poisition is not a solution
      printArr(length,length,mz);
      printf("Number of steps: %d\n\n",count-1);
      printf("Success!!\n");
    }
  }else if(mz[row][col] != 0){
    //do nothing
  }else{
    // position has been visited
    mz[row][col] = 2;
    // order of movemement: Down, Right, Left, Up
    traceMaze(length,mz,row + 1,col,count+1);
    traceMaze(length,mz,row,col + 1,count+1);
    traceMaze(length,mz,row,col - 1,count+1);
    traceMaze(length,mz,row - 1,col,count+1);
    //    mz[row][col] = 0; //uncomment in order to find all solutions, does not show dead ends tried.
  }
}
