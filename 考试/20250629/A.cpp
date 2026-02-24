#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int n;
string s;
int main(){
    cin >> s;
    n = s.length();
    n--;
    int ans = 0;
    for(int i = 0; i <= n; i++){
        if((n & i) == i){
            ans ^= (int)(s[i] - '0');
        }
    }
    cout << ans << endl;
    return 0;
}