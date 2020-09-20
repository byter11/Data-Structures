#include<stdio.h>
#include<stdlib.h>

int **arr;

void magic(int val, const int side, int squares, int row, int col){
  if(!(squares)) return;
  arr[row][col] = val;
  int newrow = row==0 ? side-1 : row-1;
  int newcol = col==side-1 ? 0 : col+1;
  if(arr[newrow][newcol]){
    newrow = row == side-1? 0 : row+1;
    return magic(val+1, side, squares-1,newrow, col);
  }
  return magic(val+1, side, squares-1, newrow, newcol);
}

int main(){
  const int side = 3;
  arr =(int **) malloc(side * sizeof(int *));
  for(int i=0; i<side; i++)
    arr[i] = (int *)calloc(side , sizeof(int));
  magic(1, side, side*side, 0, 1);
  int i, j;
  for(i=0;i<side;i++){
    for(j=0;j<side;j++)
      printf("%d ", arr[i][j]);
    printf("\n");
  }
  return 0;
}