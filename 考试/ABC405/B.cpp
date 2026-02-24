#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int n, m;
string s, t;
int a[qwe];
int cnt[qwe], rnk[qwe];
int main(){
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(rnk[a[i]] == 0){
            rnk[a[i]] = i;
        }
        cnt[a[i]]++;
    }
    int mx = 0;
    for(int i = 1; i <= m; i++){
        mx = max(rnk[i], mx);
        // cerr << "rnk[i] = " << rnk[i] << ", cnt[i]";
        if(cnt[i] == 0){
            cout << 0 << endl;
            return 0;
        }
    }
    cout << n - mx + 1 << endl;
    return 0;
}