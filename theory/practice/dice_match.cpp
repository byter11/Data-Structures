#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

double dice_match(const string& s1, string s2) {
        //check fast cases
        if(s1 == s2)
            return 1;
        if(s1.length() < 2 || s2.length() < 2)
            return 0;

        set<string> s1_bigrams;
        set<string> s2_bigrams;

        for(unsigned int i = 0; i < (s1.length() - 1); i++)       // extract character bigrams from string1
                s1_bigrams.insert(s1.substr(i, 2));
        for(unsigned int i = 0; i < (s2.length() - 1); i++)      // extract character bigrams from string2
                s2_bigrams.insert(s2.substr(i, 2));

        double matches = 0;
        int i = 0, j = 0;

        //get bigrams and compare
        for(const string& a : s1_bigrams){
            for(const string& b : s2_bigrams){
                cout << a << ':' << b << endl;
                if(a==b){
                    matches += 2;
                    s2_bigrams.erase(b);
                }
            }
        }
        return matches / (s1.length() + s2.length() - 2);
    }

int main(){
    cout << dice_match("FRANCE", "REPUBLIC OF FRANCE");
}