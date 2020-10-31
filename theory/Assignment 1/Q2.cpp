//UPDATED Test Case #5 output to NO

#include<iostream>
#include<cmath>
#include<fstream>
using namespace std;

int reverse(int num){
    int no_of_digits = (int)log10(num);
    if(num == 0)
        return 0;
    return (num%10 * pow(10,no_of_digits)) + reverse(num/10);
}

bool is_array_palindrome(int* arr, int l,int r){
    if( l>=r )
        return true;
    if( arr[l] == reverse(arr[r]))
        is_array_palindrome(arr, l+1, r-1);
    else
        return false;
}
void input_and_run(istream& in, fstream& fs){
    int size;
    int* arr = new int[size];
    in >> size;
    for(int i=0; i<size;i++)
        in >> arr[i];
    string result_str;
    string test_str;
    getline(fs, test_str);
    if(is_array_palindrome(arr, 0, size-1))
        result_str = "YES";
    else
        result_str = "NO";
    cout << result_str << (result_str==test_str ? " OK" : " Failed") << '\n';
}
void test(){
    string dir = "./A1Testcases/Array Palindrome/";
    filebuf ifile;
    fstream ofile;
    for(int i=0; i<6; i++){
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