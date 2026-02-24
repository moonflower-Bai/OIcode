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

const int MAXN = 5e5 + 1;
void solve() {
    int n, t;
    cin >> n >> t;
    string s;
    cin >> s;
    int i = 0;
    while(s[i] == '0')
        i++;
    int b = i;
    int ans = 0;
    do {
        while(s[i] == '1') {
            i = (i + 1) % n;
        }
        int j = i;
        int cnt = 1;
        while(s[(j + 1) % n] == '0') {
            j = (j + 1) % n;
            cnt++;
        }
        ans = max(ans, cnt - t - 1);
        i = (j + 1) % n;
    } while(i != b);
    quit(ans);
}

int main() {
    IOS;
    testm;
}