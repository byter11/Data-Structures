class Student{
	int id;
	string name;
	int age;
	int grade;
	public:
		Student(){ name="\0"; }
		void readData(){
			cout << "ID: ";
			cin >> id;
			cout << "Name: ";
			cin >> name;
			cout << "Age: ";
			cin >> age;
			cout << "Grade: ";
			cin >> grade;
		}
		
		friend ostream& operator<<(ostream& out, Student& s){
			out << "ID: " << s.id << "  Name: " << s.name << "  Age: " << s.age << "  Grade: " << s.grade << endl;
			return out;
		}
		
		bool operator<(Student& s){
			return name<s.name;
		}
		
};