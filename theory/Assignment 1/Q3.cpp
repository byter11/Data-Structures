#include <iostream>
#include <fstream>
using namespace std;

bool sum_of_subsets(int* arr, int sum, int i ,int size, int target, bool result){
    if(sum == target)
        result = true;
    if(i>=size)
        return result;
    result =  sum_of_subsets(arr, sum, i+1, size, target, result);
    result =  sum_of_subsets(arr,  sum+arr[i],i+1, size, target, result);
    return result;
}
void input_and_run(istream& in, fstream& fs){
    int size;
    in >> size;
    int* arr = new int[size];
    for(int i=0; i<size; i++)
        in >> arr[i];
    int target;
    in >> target;
    string result_str;
    string test_str;
    getline(fs, test_str);
    if( sum_of_subsets(arr, 0, 0, size, target, false) )
        result_str = "YES";
    else
        result_str = "NO";
    cout << result_str << (result_str==test_str ? " OK" : " Failed") << '\n';
}

void test(){
    string dir = "./A1Testcases/SumOfSubsets/";
    filebuf ifile;
    fstream ofile;
    for(int i=0; i<5; i++){
        string file = dir + "input00" + to_string(i) + ".txt";
        ifile.open(file, ios::in);
        ofile.open(dir + "output00" + to_string(i) + ".txt");
        istream is(&ifile);
        cout << "Test Case " << i << ":\n";
        input_and_run(is,ofile);
        ifile.close();
        ofile.close();
    }
    
}
int main(){
    test();
    return 0; 
}