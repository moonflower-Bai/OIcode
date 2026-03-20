#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e2+5;
int n;
string s[qwe];
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> s[i];
    }
    string temp;
    unordered_set<string> mp;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(i == j){
                continue;
            }
            temp = s[i] + s[j];
            mp.insert(temp);
        }
    }
    cout << mp.size() << endl;
    return 0;
}