#include<iostream>
using namespace std;
#define SIZE 5

#include "Student.h"
void addStudent(Student* s){
	Student student;
	student.readData();
	
	for(int i=0;i<SIZE;i++){
		if( s[i] < student ){
			Student temp = s[i];
			for(int j=i+1;j<SIZE;j++){
				Student next = s[j];
				s[j] = temp;
				temp = next;
			}
			s[i] = student;
			break;
		}	
	}
}
int main(){
	int i;
	Student *s = new Student[SIZE];
	for(i=0;i<5;i++){
		cout << "Student#" << i+1 << endl;
		addStudent(s);
	}
	cout << "RESULT:\n";
	for(i=0;i<5;i++){
		cout << s[i];
	}
}
