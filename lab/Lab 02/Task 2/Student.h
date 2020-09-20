class Student{
    int id;
    int batch;
    string discipline;
    int grad_year;
    string courses[5];

    public:
        Student(){}
        istream& input(istream& in){
            cout << "ID: ";
            in >> id;
            cout << "Batch: ";
            in >> batch;
            cout << "Discipline: ";
            in >> discipline;
            cout <<"Graduation year: ";
            in >> grad_year;
            cout << "Enter 5 courses:\n";
            for(int i=0; i<5; i++)
                in >> courses[i];
        }
        ostream& output(ostream& o){
            cout << "ID: " << id << "\n" << "Batch: " << batch << "\n";
            cout << "Discipline: " << discipline+"\n" << "Graduation Year: " << grad_year << "\n";
            cout << "Courses:\n";
            for(int i=0; i<5; i++)
                cout << courses[i] << "\n";
        }
        friend istream& operator>>(istream& in, Student& s){
            s.input(in);
        }
        friend ostream& operator<<(ostream& o, Student& s){
            s.output(o);
        }
};

class s_Array{
    Student* arr;
    int size;
    public:
    s_Array(size_t size){
        arr = new Student[size];
    }
    Student& operator[](int i){
        if(i<0 || i>size){
            cout << "Index out of range! exiting";
            exit(1);
        }
        return arr[i];
    }
};