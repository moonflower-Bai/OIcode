#include<bits/stdc++.h>
using namespace std;

#define test solve()
#define testm int T; cin >> T; while(T--) solve()

#define rep(i, k, n) for(int i = (k); i <= (n); i++) 
#define srep(i, k, n) for(int i = (k); i >= (n); i--)
#define ms(a, b) memset(a, (b), sizeof(a))
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;

#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#define quit(x) {cout << (x) << endl; return;}



void solve() {
    int n;
    cin >> n;
    vector<vector<int>> graph(n + 1);
    vector<int> d(n + 1);
    rep(i, 1, n) {
        cin >> d[i];
        graph[i].resize(d[i] + 1);
        rep(j, 1, d[i]) {
            cin >> graph[i][j];
        }
    }
    auto find_next = [&](int px, int v) {
        rep(i, 1, d[v]) {
            if(graph[v][i] == px) {
                return i % d[v] + 1;
            }
        }
        return 1;
    };
    set<pii> vis;
    set<int> ca, visx;
    vector<int> ans(n + 1, -1);
    rep(s, 1, n) {
        if(ans[s] != -1)
            continue;
        int cx = s, cy = 1;
        while(!vis.count({cx, cy})) {
            vis.insert({cx, cy});
            if(d[cx] == 1)
                visx.insert(cx);
            if(cy == 1)
                ca.insert(cx);
            int nx = graph[cx][cy], ny = find_next(cx, nx);
            cx = nx, cy = ny;
        }
        int cans = vis.size() - visx.size();
        for(int x: ca)
            ans[x] = cans;
        vis.clear();
        ca.clear();
        visx.clear();
    }
    rep(i, 1, n) {
        cout << ans[i] << '\n';
    }
    
}   

int main() {
    IOS;
    test;
}