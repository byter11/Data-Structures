#include<iostream>

using namespace std;
class twoway{
	int *arr;
	int start,end;
	size_t size;
	public:
	twoway(const int size):size(size){
		start = 0;
		end = size-1;
		arr = new int[size];
	}
	void create(int num, bool isReverse){
		if(isReverse)
			arr[end--] = num;
		else
			arr[start++] = num;
	}
	int read(int index, bool isReverse){
		if(isReverse)
			return arr[size-index];
		else
			return arr[index];
	}
	void update(int index, int num, bool isReverse){
		if(isReverse)
			arr[size-index] = num;
		else
			arr[size] = num;
	}
	void delete_(int index, bool isReverse){
		if(isReverse)
			arr[size-index] = 0;
		else
			arr[index] = 0;
	}
	bool search(int num){
		int e = end;
		for(int i=0;i<size/2;i++){
			if(arr[i] == num || arr[size-i] == num)
				return true;
			return false;	
		}
	}
};
int main(){
	twoway arr(50);
	
	while(1){
		int choice;
		cout << "1. CREATE\n2. READ\n3. UPDATE\n4. DELETE\n5. SEARCH\n";
		cin >> choice;
		bool isReverse = false;
		cout << "Mode? choose 1 for beginning, 2 for end: ";
		int c;
		cin >> c;
		if(c==2) isReverse = true;
		int num;
		
		switch(choice){
			case 1:{
				int num;
				cout << "Number: ";
				cin >> num;
				arr.create(num,isReverse);
				break;
			}
			case 2:{
				int index;
				cout << "Index: ";
				cin >> index;
				cout << arr.read(index, isReverse) << endl;
				break;
			}
			case 3:{
				int index,num;
				cout << "Index: ";
				cin >> index;
				cout << "Number: ";
				cin >> num;
				arr.update(index,num, isReverse);
				break;
			}
			case 4:{
				int index;
				cout << "Index: ";
				cin >> index;
				arr.delete_(index, isReverse);
				break;
			}
			case 5:{
				int num;
				cout << "Num: ";
				cin >> num;
				cout << "Number ";
				if(!arr.search(num))
					cout << "Not ";
				cout << "Found\n";
			}
		}
	}
	
}
