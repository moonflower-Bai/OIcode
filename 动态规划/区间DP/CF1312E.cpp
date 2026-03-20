#include <bits/stdc++.h>
#include <cstring>
using namespace std;
const int qwe = 1e3 + 5;
int n;
int a[qwe];
int w[qwe][qwe];
int f[qwe];
int main()
{
	cin >> n;
	memset(f, 0x3f, sizeof(f));
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		w[i][i] = a[i];
	}

	for (int len = 2; len <= n; len++) { // 从小区间向大区间转移
		for (int l = 1; l + len - 1 <= n; l++) {
            int r = l + len - 1;
			for (int mid = l; mid <= r; mid++) {
				if (w[l][mid] == w[mid + 1][r] && w[l][mid] != 0) {
					w[l][r] = w[l][mid] + 1;
				}
			}
		}
	}
	f[0] = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
			if (w[j][i]) {
				f[i] = min(f[i], f[j - 1] + 1);
			}
		}
    }
	cout << f[n] << endl;
	return 0;
}