#include<bits/stdc++.h>
using namespace std;

#define test solve()
#define testm int T; cin >> T; while(T--) solve()

#define rep(i, k, n) for(int i = (k); i <= (n); i++) 
#define srep(i, k, n) for(int i = (k); i >= (n); i--)
#define ump unordered_map
#define ust unordered_set
#define ms(a, b) memset(a, (b), sizeof(a))
using ll = long long;
using pii = pair<int, int>;

#define IOS ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr)

#define quit(x) {cout << (x) << endl; return;}


void solve() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    s = '1' + s;
    string ans;
    int l1 = n - k + 2, l2 = n - k + 3;
    int f1 = 1;
    rep(i, 1, l1 - 1) {
        if(s[i] < s[f1]) {
            f1 = i;
        }
    }
    ans += s[f1];
    if(k == 1)
        quit(ans);
    // --------------- 确定 ---------------------
    int f2 = f1 + 1; // 定义i
    rep(i, f1 + 1, l2 - 1) { // 从l + 1循环到n - k + 3以获取最小字符串
        if(s[i] < s[f2] // 第一位更优
            || (i + 1 <= n && s[i] == s[f2] && s[i + 1] < s[f2 + 1])) { // 第一位相同，比较第二位
            f2 = i; // 更新
        }
    }
    // BUG: 如果前两位都相同，则无法保证选择到更优的情况
    ans += s[f2];
    if(k == 2)
        quit(ans);
    int r1 = f2 + k - 3;
    int fk = n;
    srep(i, n, r1 + 1) {
        if(s[i] < s[fk]) {
            fk = i;
        }
    }
    rep(i, f2 + 1, r1)
        ans += s[i];
    ans += s[fk];
    cout << ans;
}


int main() {
    IOS;
    test;
}