#include <bits/stdc++.h>
using namespace std;
int T;
int n; 
int xk, yk, xd, yd;
int main(){
    cin >> T;
    while(T--){
        cin >> n >> xk >> yk >> xd >> yd;
        int mx = 0;
        if(xk - xd >0){
            mx = n - xd;
        }
        else if(xk - xd < 0){
            mx = xd;
        }
        else{
            mx = 0;
        }
        if(yk - yd > 0){
            mx = max(mx, n - yd);
        }
        else if(yk - yd < 0){
            mx = max(mx, yd);
        }
        else{
            mx = max(mx, 0);
        }
        cout << mx << endl;
    }
    return 0;
}