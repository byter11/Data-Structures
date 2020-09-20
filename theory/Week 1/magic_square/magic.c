#include <stdio.h>

void goupright(int*,int*);
const int num = 13;
int main(){
	int arr[num][num] = {0};
	int val =  1;
	int row=0, col= num/2 ;
	arr[row][col] = val;
	for(int i=0; i<(num*num)-1; i++){
		int altrow = row==num-1 ? 0 : row+1;
		int altcol = col;
     		goupright(&row, &col);
		val = val+1;
     		if(!arr[row][col])
		 arr[row][col] = val;
 		else{
		 arr[altrow][altcol] = val;
		 row = altrow;
		 col = altcol;
}
	 }
printf("\n");
	for(int i=0;i<num;i++){
		for(int j=0;j<num;j++)
			printf("%3d ",arr[i][j]);
		printf("\n");
	}
return 0;
}

void goupright(int* startrow, int* startcol){
  if((--(*startrow)) < 0) *startrow = num-1;
  if((++(*startcol)) > num-1) *startcol = 0;
}




