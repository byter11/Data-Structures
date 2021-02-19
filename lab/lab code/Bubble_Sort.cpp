 
#include <bits/stdc++.h> 
using namespace std; 
  
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
// A function to implement bubble sort  
void bubbleSort(int arr[], int n)  
{
	//static int m = 0;  
    int i, j;  
    for (i = 0; i < n-1; i++)      
    {
    //m++;
    //cout<<m<<endl;
    // Last i elements are already in place  
    for (j = 0; j < n-i-1; j++)
	{
	//m++;
	//cout<<m<<endl;   
        if (arr[j] > arr[j+1])
			{
		//	m++;
		//	cout<<m<<endl; 
            swap(&arr[j], &arr[j+1]); 
        	}
	}
	}
}  
  
/* Function to print an array */
void printArray(int arr[], int size)  
{  
    int i;  
    for (i = 0; i < size; i++)  
        cout << arr[i] << " ";  
    cout << endl;  
}  
  
// Driver code  
int main()  
{  
    int arr[] = {2, 8, 1, 3, 4, 5, 1};  
    int n = sizeof(arr)/sizeof(arr[0]);  
    bubbleSort(arr, n);  
    cout<<"Sorted array: \n";  
    printArray(arr, n);  
    getchar();
    return 0;  
}  
  

