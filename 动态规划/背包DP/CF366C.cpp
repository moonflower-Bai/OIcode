#include <bits/stdc++.h>
#include <cstring>
#include <ostream>
using namespace std;
const int N = 1e5 + 5;
const int M = 1e2 + 5;
const int P = 1e4;
int n, k;
int a[N], b[N], w[N];
int f[M][N];
int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	for (int i = 1; i <= n; i++) {
		w[i] = a[i] - k * b[i];
	}
	memset(f, -1, sizeof(f));
	f[0][P] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = N - 5; j >= 0; j--) {
			if (j - w[i] <= N - 5 && j - w[i] > 0) {
				if (f[i - 1][j - w[i]] == -1) {
					f[i][j] = f[i - 1][j];
				} else {
					f[i][j] = max(f[i - 1][j], f[i - 1][j - w[i]] + a[i]);
				}
			}
		}
	}
	if (f[n][P] != 0) {
		cout << f[n][P] << endl;
	} else {
		cout << -1 << endl;
	}
	return 0;
}
