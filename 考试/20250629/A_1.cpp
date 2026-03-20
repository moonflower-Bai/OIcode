#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
string s;
int n;
bitset<qwe> s1,s2;
int main(){
    freopen("/home/bai/code/test.in","r",stdin);
    cin >> s;
    int ans = 0;
    n = s.length();
    for(int i = 0; i < n; i++){
        if(s[i] == '0'){
            s1[i] = 0;
        }
        else{
            s1[i] = 1;
        }
    }
    for(int i = 1; i <= n  - 1; i++){
        s2 = s1 >> 1;
        s1 = s2 ^ s1;
    }
    cout << s1[0] << endl;
    return 0;
}
