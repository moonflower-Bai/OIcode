#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
const int M = 1e6 + 5;
const int P = 5e5;
int n, k;
int a[N], w[N];
int f[M];
int main()
{
    ios::sync_with_stdio(false);
	cin >> n >> k;
	for (int i = 1; i <= k; i++) {
		cin >> a[i];
	}
    sort(a + 1, a + k + 1);
    int m = unique(a + 1, a + k + 1) - a - 1;
	for (int i = 1; i <= m; i++) {
		w[i] = a[i] - n;
	}
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= m; i++) {
		f[P + w[i]] = 1;
		if (w[i] >= 0) {
			for (int j = w[i]; j <= M - 5; j++) {
				f[j] = min(f[j], f[j - w[i]] + 1);
			}
		} else {
			for (int j = M - 5 + w[i]; j >= 0; j--) {
				f[j] = min(f[j], f[j - w[i]] + 1);
			}
		}
	}
	if (f[P] == 0x3f3f3f3f) {
		cout << -1 << endl;
	} else {
		cout << f[P] << endl;
	}
	return 0;
}
