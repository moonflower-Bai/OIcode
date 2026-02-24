#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
const int mod = 998244353;
int T;
int n; 
int a[qwe];
int main(){
    cin >> T;
    while(T--){
        cin >> n;
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
            if(a[i - 1] == 1 && a[i] == -1 && a[i + 1] == 1){
                cnt ++;
            }
        }
    }
}