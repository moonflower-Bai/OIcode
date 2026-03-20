#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 5;
int n;
string s;
int f[N][N];

int main()
{
	cin >> s;
	n = s.length();
	memset(f, 0, sizeof(f));
	for (int i = 1; i <= n; i++) {
		for (int j = i, k = i; j > 0 && k <= n; j--, k++) {
			if (s[j - 1] == s[k - 1]) {
				f[j][k]++;
			} else {
				break;
			}
		}
		for (int j = i, k = i + 1; j > 0 && k <= n; j--, k++) {
			if (s[j - 1] == s[k - 1]) {
				f[j][k]++;
			} else {
				break;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			f[i][j] = (f[i][j] + f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1]);
			// cerr << f[i][j] << ' ';
		}
		// cerr << endl;
	}
	int q, l, r;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		cin >> l >> r;
		cout << f[r][r] - f[l - 1][r] - f[r][l - 1] + f[l - 1][l - 1] << endl;
	}
	return 0;
}