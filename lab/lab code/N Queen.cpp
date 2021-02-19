#include <iostream>
using namespace std;
#include <stdio.h> 



bool checkSafety(int board[4][4], int row, int col)
{
	int i, j;

	// check row
	for(j = 0; j < col; j++)
	{
		if(board[row][j])
			return false;
	}

	// check upper left diagonal
	for(i = row, j = col; i >= 0 && j >= 0; i--, j--)
	{
		if(board[i][j])
			return false;
	}

	// check for lower left diagonal
	for(i = row, j = col; i < 4 && j >= 0; i++, j--)
	{
		if(board[i][j])
			return false;
	}

	// no violation then return true
	return true;
}



bool NQueen(int board[4][4], int col)
{
	//base case
	if(col >= 4)
		return true;

	for(int i = 0; i < 4; i++)
	{

		if(checkSafety(board, i, col))
		{
			// place queen
			board[i][col] = 1;

			// recursive call
			if(NQueen(board, col + 1))
				return true;

			// undo queen placement and do backtracking
			board[i][col] = 0;
		}

	}


	// no solution exists for this problem even after we backtracked
	return false;
}




  
int main() 
{ 
	 int board[4][4] = { { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 }, 
                        { 0, 0, 0, 0 } }; 

	
	// printing grid
	 if(NQueen(board, 0))
	 {
		 for(int i = 0; i < 4; i++)
		 {
			 for(int j = 0; j < 4; j++)
			 {
				 cout << board[i][j] << " ";
			 }

			 cout << endl;
		 }
		 getchar();
	 }
}
