#include <bits/stdc++.h>
using namespace std;
#define int long long
int gcd(int x, int y){
    return y == 0 ? x : gcd(y, x%y);
}
int T;
int a, b, k;
signed main(){
    cin >> T;
    while(T--){
        cin >> a >> b >> k;
        if(a == 0 && b == 0){
            cout << 0 << endl;
            continue;
        }
        int g = gcd(a, b);
        cerr << "[debug] " << g << endl;
        a /= g;
        b /= g;
        if(a <= k && b <= k){
            cout << 1 << endl;
        }
        else{
            cout << 2 << endl;
        }
    }
    return 0;
}