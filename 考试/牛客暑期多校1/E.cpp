#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe = 1e6+5;
int T;
int main(){
    cin >> T;
    while(T--){
        ll a, b;
        cin >> a >> b;
        ll x = 1ll * a * a - 1ll * b * b;
        x = abs(x);
        ll ans = 0;
        if(x == 3){
            cout << 1 << endl;
            continue;
        }
        if(x % 4 == 0){
            ans = 3 * x / 4 - 2;
        }
        else if(x % 4 == 1){
            ans = (3 * x + 1) / 4 - 2;
        }
        else if(x % 4 == 3){
            ans = (3 * x - 1) / 4 - 2;
        }
        cout << ans << endl;
    }
    return 0;
}