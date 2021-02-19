#include<bits/stdc++.h>
using namespace std;
typedef vector<pair<int, int>> pathvec;

vector<pathvec> paths;

void printpath(pathvec path){
    cout << '{';
    string pathstr;

    for(pair<int,int> p : path)
        cout << '(' << p.first << ',' << p.second << "),";

    cout << "\b} Cost=" << path.size() << '\n';
}

void findpath(char** arr, int i, int j, int n, int m, pathvec path){
    if( i>=n || j>=m || j<0 || i<0)
        return;
    if( arr[i][j] == '1' || arr[i][j] == '!')
        return;
    
    path.push_back( pair<int,int>(j,i) );
    
    if( arr[i][j] == 'e' || arr[i][j] == 'E'){
        paths.push_back(path);
        return;
    }
    char old = arr[i][j];

    arr[i][j] = '!';
    findpath(arr, i, j+1, n, m, path);
    findpath(arr, i+1, j, n, m, path);
    findpath(arr, i-1, j, n, m, path);
    findpath(arr, i, j-1, n, m, path);
    arr[i][j] = old;
}

int main(){
    for(int i=0;i<=4;i++){
        fstream infile = fstream("./A2UpdatedTestCases/A2P1/input00"+to_string(i)+".txt", ios::in);

        int n, m;
        infile >> n >> m;

        char** arr = new char*[n];
        for(int i=0;i<n;i++)
            arr[i] = new char[m];
            
        int si, sj;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                infile >> arr[i][j];
                if (arr[i][j] == 's' || arr[i][j] == 'S'){
                    si = i;
                    sj = j;
                }
            }
        }
        
        pathvec path;
        
        findpath(arr, si, sj, n, m,  path);
        sort(paths.begin(), paths.end(), [](pathvec p1, pathvec p2) {return p1.size() < p2.size();});
        
        cout << "Test Case " << i << ":\n";
        for(pathvec path : paths){
            printpath(path);
        }
        cout << '\n';
        paths.clear();
        infile.close();
    }
    return 0;
}