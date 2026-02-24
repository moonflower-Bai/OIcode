
#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
const int mod = 998244353;
#define ll long long
int T;
int n;
int a[qwe];
int cont[qwe], cnt = 0;
int pow2[qwe];
auto init = []{
    pow2[0] = 1;
    // rep(i, 1, qwe - 1) {
    for(int i = 1; i < qwe; i++){
        pow2[i] = 1ll * pow2[i - 1] * 2 % mod;
    }
    return 0;
}();
vector<int> odd;
bool vis[qwe];
void Debug(string msg, int val = 0){
    #ifdef _Debug
    cerr <<"[Debug] "<< msg << val << endl;
    #endif
}
int dfs(int u, int c){
    vis[u] = 1;
    if(!vis[a[u]]){
        return dfs(a[u], c + 1);
    }
    else{
        return c;
    }
}
int main(){
    cin >> T;
    while(T--){
        ll ans = 0;
        cin >> n;
        odd.clear();
        cnt = 0;
        int even_cnt = 0;
        memset(vis, 0, sizeof(vis));
        memset(cont, 0, sizeof(cont));
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++){
            if(!vis[i]){
                cont[++cnt] = dfs(i, 1);
                // Debug("count:",cont[cnt]);
                if(cont[cnt]%2) odd.push_back(cnt);
                if(cont[cnt] == 2) even_cnt ++;
            }
        }
        // Debug("odd size:", odd.size());
        // Debug("ring size = ", cnt);
        if(odd.size() >= 3 || odd.size() == 1){
            // Debug("1st ");
            ans = 0;
        }
        else if(odd.size() == 2){
            // Debug("2nd ");
            // ll even = (1 << ((cnt - 2) % 31)) % mod;
            ll even = pow2[cnt - 2 - even_cnt];
            // Debug("even = ", even);
            ll o1 = cont[odd[0]], o2 = cont[odd[1]];
            ans = (1ll * (o1 * o2) % mod * even) % mod;
        }
        else{
            // Debug("3rd ");
            for(int i = 1; i <= cnt; i++){
                ll k = cont[i] / 2;
                // ll even = (1 << ((cnt - 1) % 31)) % mod;
                ll even = pow2[cnt - 1 - even_cnt + (cont[i] == 2 ? 1 : 0)];
                // Debug("even = ", even);
                ans = (1ll * ans + ((1ll * k * k) % mod * even) % mod) % mod;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
/*
2
4 
1 3 4 2
6
3 4 5 6 2 1

2
12
1 3 4 2 6 7 8 5 10 11 12 9
12
2 3 4 5 6 1 8 9 10 7 12 11

1
12
2 1 4 3 6 5 8 7 10 9 12 11
*/