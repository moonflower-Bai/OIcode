#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe = 1e5+5;
const int mod = 1e9+7;
ll pw(ll x, ll y){
    ll ans = 1;
    while(y > 0){
        if(y & 1 == 1){
            ans *= x;
            ans %= mod;
        }
        x *= x;
        x %= mod;
        y >>= 1;
    }
    return ans;
}

int n, ans;
int main(){
    cin >> n;
    ans = 1ll * n * pw(2, n - 1) % mod;
    cout << ans << endl;
    return 0;  
}