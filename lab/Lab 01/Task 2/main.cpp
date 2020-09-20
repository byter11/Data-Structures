#include<iostream>
using namespace std;

#include "Employee.h"

int main(){
	int n = 0;
	Employee* e = new Employee[5];
	while(1){
		cout << "1. Add Employee\n2. Get wages\n3. Reset\n";
		int choice;
		cin >>  choice;
		switch(choice){
			case 1: {
				if(n >= 5){
					cout << "Database full.\n";
					break;
				}
				int age, exp, hours;
				cout << "Enter Details: (age, exp,  hours): ";
				cin >> age >> exp >>  hours;
				Employee e1(age,exp,hours);
				e[n] = e1;
				n++;
				cout << "Added\n\n";
				break;
			}
			case 2:{
				int i;
				for(i = 0; i<n; i++){
					cout << "Employee #" << i+1 << ": " << (e+i)->calc_wage() << "\n";
				}
				break;
			}
			case 3:{
				delete [] e;
				n = 0;
				e = new Employee[25];
			}
		}
	}
	delete [] e;
	return 0;
}