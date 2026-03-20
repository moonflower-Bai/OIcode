#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t;
    cin >> t;
    
    while (t--) {
        int n, q;
        cin >> n >> q;
        
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        
        while (q--) {
            int l, r;
            cin >> l >> r;
            
            int len = r - l + 1;
            
            if (len % 3 != 0) {
                cout << -1 << "\n";
                continue;
            }
            
            int cnt0 = 0, cnt1 = 0;
            for (int i = l; i <= r; i++) {
                if (a[i] == 0) cnt0++;
                else cnt1++;
            }
            
            if (cnt0 % 3 != 0 || cnt1 % 3 != 0) {
                cout << -1 << "\n";
                continue;
            }
            
            vector<int> b(len);
            for (int i = 0; i < len; i++) {
                b[i] = a[l + i];
            }
            
            // dp[i][j] = 清空 b[i..j] 的最小代价
            vector<vector<int>> dp(len, vector<int>(len, INF));
            
            // 空区间
            for (int i = 0; i < len; i++) {
                if (i > 0) dp[i][i-1] = 0;
            }
            
            // 枚举区间长度
            for (int length = 3; length <= len; length += 3) {
                for (int i = 0; i + length - 1 < len; i++) {
                    int j = i + length - 1;
                    
                    // 枚举 b[i] 与哪两个配对
                    for (int k1 = i + 1; k1 <= j - 1; k1++) {
                        if (b[k1] != b[i]) continue;
                        
                        for (int k2 = k1 + 1; k2 <= j; k2++) {
                            if (b[k2] != b[i]) continue;
                            
                            int cost = min(k2 - k1, k1 - i);
                            
                            int left = (k1 - 1 >= i + 1) ? dp[i + 1][k1 - 1] : 0;
                            int mid = (k2 - 1 >= k1 + 1) ? dp[k1 + 1][k2 - 1] : 0;
                            int right = (j >= k2 + 1) ? dp[k2 + 1][j] : 0;
                            
                            if (left < INF && mid < INF && right < INF) {
                                dp[i][j] = min(dp[i][j], left + mid + cost + right);
                            }
                        }
                    }
                }
            }
            
            cout << (dp[0][len - 1] >= INF ? -1 : dp[0][len - 1]) << "\n";
        }
    }
    
    return 0;
}