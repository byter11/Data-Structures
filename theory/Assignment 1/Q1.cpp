#include <iostream>
#include<vector>
#include<fstream>
using namespace std;


int is_scrambled(string orig, string scrambled){
    char c;
    for(int i=0; i<scrambled.length(); i++){
        c = scrambled.at(i);
        int idx = orig.find(c);
        if(idx > orig.length()){
            return 0;
        }
        orig.replace(idx,1, " ");
    }
    if(orig.length() != scrambled.length())
        return -1;
    return 1;
}
int find_word(char** arr, int rows, int cols, int i, int j, string word, string res, vector<vector<bool>> visitedCopy, vector<vector<bool>>* visited, int* found){
    //Multiple words along different paths from the same head are Allowed
    if(res.length() == 1){
        *found = 0; //To make sure same path from the same head doesn't get repeated
    }
    if(i >= rows || j >= cols || j<0 || i<0 || res.size() > word.size()){
        res.erase(res.length() - 1);
        return 0;
    }
    res+=arr[i][j];
    
    //If visited during last search OR during current search, return 0
    if( visitedCopy[i][j] or (*visited)[i][j]){
        if(res.length()>0)
            res.erase(res.length() - 1);
        return 0;
    }

    
    visitedCopy[i][j] = true;
    //return if first letter doesn't match
    if(res[0] != word[0])
        return 0;

    //CHECK IF WORD FOUND SCRAMBLED OR NOT
    int scrambled = is_scrambled(word,res);
    if( scrambled == 0){
        res.erase(res.length()-1);
        return false;
    }
    
     if( scrambled == 1){
        //cout << res << "\n";
        res.erase(res.length()-1);
        if(*found==0){
            *visited = visitedCopy;
            *found = 1;
            return 1000;
        }
    }
    
    //Traverse four directions using backtracking
    return(
        find_word(arr,rows, cols, i+1, j, word, res, visitedCopy, visited,found) +
        find_word(arr,rows, cols, i, j+1, word, res, visitedCopy, visited,found) +
        find_word(arr,rows, cols, i-1, j, word, res, visitedCopy, visited,found) +
        find_word(arr,rows, cols, i, j-1, word, res, visitedCopy, visited,found)
    );

}

void boggle(char** arr,int n,int m, vector<string> words, fstream& ofile){
    vector< vector<bool> > visited(n);

    int res =0;
    for(string word: words){
        for(int i=0;i<n;i++){
            visited[i] = vector<bool>(m);
            visited[i].assign(m,false);
        }
        for(int i=0; i<n; i++){
            for(int j=0;j<m;j++){
                int found=0;
                res += find_word(arr, n,m,i,j, word, "", visited, &visited, &found);
            }
        }
        string score = word + ' ' + to_string(res);
        string filescore;
        getline(ofile, filescore);
        if(filescore.length() <= 0)
            filescore = word + " 0";
        bool test_passed = score == filescore;
        cout << score << (test_passed? " OK": " FAILED") << '\n';
        res = 0;
    }
    cout << "\n"; 
}

void input_and_run(istream& in, fstream& fs){
    int n,m;
    in >> n >> m;
    n++;
    m++;
    char** arr = new char*[n];
    for(int i=0;i<n;i++)
        arr[i] = new char[m];
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            in >> arr[i][j];
    }
    int size;
    in >> size;
    vector<string> words(size);
    for(int i=0;i<size;i++)
        in >> words[i];
    
    boggle(arr, n, m, words, fs);
}
void test(){
    
    string dir = "./A1Testcases/Boggle Boggle/";
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
    //Manual input alternative
    // int n,m;
    // cin >> n >> m;
    // n++;
    // m++;
    // char** arr = new char*[n];
    // for(int i=0;i<n;i++)
    //     arr[i] = new char[m];
    
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<n;j++)
    //         cin >> arr[i][j];
    // }
    // int size;
    // cin >> size;
    // vector<string> words(size);
    // for(int i=0;i<size;i++)
    //     cin >> words[i];
    // fstream of = fstream("./A1Testcases/Boggle Boggle", ios::in);
    // boggle(arr, n, m, words, of);
    return 0;
}