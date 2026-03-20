#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
ll a, b;
ll f(ll cnt){
    ll ans = 0;
    ans += cnt / 2;
    ans += cnt / 3;
    ans += cnt / 5;
    ans += cnt / 7;
    ans -= cnt / 6;
    ans -= cnt / 10;
    ans -= cnt / 14;
    ans -= cnt / 15;
    ans -= cnt / 21;
    ans -= cnt / 35;
    ans += cnt / 30;
    ans += cnt / 42;
    ans += cnt / 70;
    ans += cnt / 105;
    ans -= cnt / 210;
    return ans;
}
int main(){
    cin >> T;
    while(T--){
        cin >> a >> b;
        ll cnt = b - a;
        ll ans = f(b) - f(a - 1);
        
        cout << cnt - ans + 1 << endl;
    }
}