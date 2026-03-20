#include <bits/stdc++.h>
#include <cstring>
using namespace std;
const int qwe = 1e6 + 5;
int n, m;
int a[qwe];
int cnt[qwe];
int f[qwe][3][3];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	memset(f, -0x3f, sizeof(f));
	f[0][0][0] = 0;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j <= 2; j++) {
			for (int k = 0; k <= 2; k++) {
				for (int l = 0; l <= 2; l++) {
					if (cnt[i] < l + j + k)
						continue;
					// if (cnt[i + 2] < l || cnt[i + 1] < l) {
					// 	continue;
					// }
					f[i][j][k] = max(f[i][j][k], l + (cnt[i] - l - j - k) / 3 +
					                                 f[i - 1][l][j]);
					// cerr << std::format(
					//     "i = {}, j = {}, k = {}, l = {}, f[i][j][k] = {}\n",
					//     i, j, k, l, f[i][j][k]);
				}
			}
		}
	}
	cout << f[m][0][0] << endl;
	return 0;
}
/*
f[i][][] i-st
cnt[i + 1] cnt[i + 2]
f[i] [cnt[i + 1]] [cnt[i + 2]]
f[i][j][k] : 第i大的作为右顶点，还需要j个i+1和k个i+2。

-------------------------------
|i - 2|i - 1|  i  |i + 1|i + 2|
-------------------------------
|     |     |  l  |  j  |  k  |
|     |     |     |j - min(l, k)|min(l, k)|
-------------------------------

k <= 2
j - k <= 2 && j >= k
j <= 4
取 l 个 i 加入顺子
f[i][j][k] = max(f[i - 1][][])

input:
13 5
1 1 5 1 2 3 3 2 4 2 3 4 5
sort:
1 1 1 2 2 2 3 3 3 4 4 5 5
ans:
1 1 1
2 2 2
3 4 5
3 4 5

input:
12 5
1 1 1 2 2 2 3 3 4 4 5 5

*/