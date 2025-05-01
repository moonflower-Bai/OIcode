#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e5+5;
char t[] = "0NKPC20";
char s[qwe];
int n;
int f[qwe][10];
int main(){
    cin >> s + 1;
    n = strlen(s + 1);
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= 6; j++){
            f[i][j] = j;
        }
    }
    if(s[1] == t[1]){
        f[1][1] = 0;
    }
    else{
        f[1][1] = 1;
    }
    for(int i = 1; i <= n; i++){
        f[i][0] = min(f[i][0], f[i - 1][0]);
        for(int j = 1; j <= 6; j++){
            f[i][j] = min(f[i - 1][j], f[i - 1][j - 1] + 1);
            if(s[i] == t[j]){
                // cerr << "equal on " << i << ", " << j << ". \n";
                f[i][j] = min(f[i][j], f[i - 1][j - 1]);
            }
            // cerr << "f[" << i << "][" << j << "] = " << f[i][j] << endl;
        }
    }
    cout << f[n][6];
    return 0;
}