class Employee{
	int age;
	int exp;
	int hours;
	
	public:
		Employee(){}
		Employee(int a, int e, int h):age(a),exp(e),hours(h){}
		int calc_wage(){
			if(age>50 && exp>10 && hours>240) return 500;
			if(age<=50 && age>40 && exp<=10 && exp>=6 && hours>200 && hours<=240) return 425;
			if(age<=40 && age>30 && exp<=6 && exp>3 && hours>160 && hours<=200) return 375;
			if(age<=30 && age>22 && exp<=3 && exp>1 && hours>120 && hours<=160) return 300;
			return 0;
		}
};