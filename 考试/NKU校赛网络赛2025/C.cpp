#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e3+5;
int mn, cnt = 0;
string s, tmp;
string t = "NKPC20";
int main(){
    cin >> s;
    mn = INT_MAX;
    for(int i = 0; i < s.size(); i++){
        for(int j = 0 ;j < 6; j++){
            tmp += s[i + j];
        }
        // cerr << tmp << endl;
        for(int j = 0; j < 6; j++){
            // cerr << j << ':' << tmp[j] << " " << t[j] << endl;
            if(tmp[j] == t[j]){
                cnt++;
            }
        }
        // cerr << "cnt: " << cnt << endl;
        mn = min(mn, 6 - cnt);
        tmp = "";
        cnt = 0;
    }
    cout << mn << endl;
    return 0;
}