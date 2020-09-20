#include "personal.cpp"
#include "student.cpp"
#include "database.h"
#include <vector>
template<class T>
Database<T>::Database() {
}

template<class T>
void Database<T>::add(T& d) {
    database.open(fName,ios::in|ios::out|ios::binary);
	fstream temp = fstream("temp.file", ios::out); //make new temp file straem
    database.clear();
	T tmp; //make temp personal object
	bool written = false;
	while( !database.eof() ){
		tmp.readFromFile(database); //get personal obj from old file
		if(!written && tmp < d ){  //Sort by Highest Salary
			d.writeToFile(temp); //if salary lower put new obj there
			written = true;		//done thing
		}
		if(!database.eof())
			tmp.writeToFile(temp); //else put the temp in new file
	}
	if(!written) d.writeToFile(temp);
		
	database.close();
	temp.close();
	remove(fName);	//delete old file
	rename("temp.file",fName); //rename new file to old
    //database.seekp(0,ios::end); 
}

template<class T>
void Database<T>::modify(const T& d) {
    T tmp;
    database.open(fName,ios::in|ios::out|ios::binary);
    database.clear();
    while (!database.eof()) {
        tmp.readFromFile(database);
		if (tmp < d) 
			break;	//stop search when passed the suitable position
        if (tmp == d) {  // overloaded ==
             cin >> tmp; // overloaded >>
             database.seekp(-d.size(),ios::cur);
             tmp.writeToFile(database);
             database.close();
             return;
        }
    }
    database.close();
    cout << "The record to be modified is not in the database\n";
}

template<class T>
bool Database<T>::find(const T& d) {
    vector<T> recs;
	T newrec;
    database.open(fName,ios::in|ios::binary);
    database.clear();
    while (!database.eof()) {
		newrec.readFromFile(database);
		if(!database.eof())
			recs.push_back(newrec);
    }
    database.close();
    return binarySearch(recs, d);
}

template<class T>
bool binarySearch(vector<T> recs, T key){
	size_t m, l=0;
	size_t r = recs.size();
	while (l<r) {
		m = (l+r)/2;
		if(recs[m] == key)
			return true;
		else if( key < recs[m])
			l = m+1;
		else
			r = m;
	}
	return false;
}
template<class T>
ostream& Database<T>::print(ostream& out) {
    T tmp;
    database.open(fName,ios::in|ios::binary);
    database.clear();
    while (true) { 
        tmp.readFromFile(database);
        if (database.eof())
            break;
        out << tmp << endl; // overloaded <<
    }
    database.close();
    return out;
}

template<class T>
void Database<T>::run() {
    cout << "File name: ";
    cin >> fName;
    cin.ignore();	// skip '\n';
    database.open(fName,ios::in);
    if (database.fail())
        database.open(fName,ios::out);
    database.close();
    char option[5];
    T rec;
    cout << "1. Add 2. Find 3. Modify a record; 4. Exit\n";
    cout << "Enter an option: ";
    while (cin.getline(option,5)) {
        if (*option == '1') {
             cin >> rec;   // overloaded >>
             add(rec);
        }
        else if (*option == '2') {
             rec.readKey();
             cout << "The record is ";
             if (find(rec) == false)
                 cout << "not ";
             cout << "in the database\n";
        }
        else if (*option == '3') {
             rec.readKey();
             modify(rec);
        }
        else if (*option != '4')
             cout << "Wrong option\n";
        else return;
        cout << *this;   // overloaded <<
        cout << "Enter an option: ";
    }
}

int main() {
	cout << "\nPERSONAL:\n";
    Database<Personal>().run();
	cout << "\nSTUDENT: \n";
	Database<Student>().run();
    return 0;
}
