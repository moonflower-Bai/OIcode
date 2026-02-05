#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
const int MOD = 1e9 + 7;
int n;
int a[qwe];
int f[qwe];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	f[0] = 1;
	vector<int> q;
	for (int i = 1; i <= n; i++) {
		q.clear();
		for (int j = 1; j <= sqrt(a[i]); j++) {
			if (a[i] % j == 0) {
				int k = a[i] / j;
				q.push_back(k);
				if (k != j)
					q.push_back(j);
				// q.push_back(k);
			}
		}
		sort(q.begin(), q.end());
		for (int j = q.size() - 1; j >= 0; j--) {
			if (a[i] % q[j] == 0)
				f[q[j]] = (f[q[j]] + f[q[j] - 1]) % MOD;
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = (ans + f[i]) % MOD;
	}
	cout << ans << endl;
	return 0;
}