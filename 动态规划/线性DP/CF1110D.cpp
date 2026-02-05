#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
int n, m;
int a[qwe];
int cnt[qwe];
int f[qwe];
int main()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	for(int i = 1; i <= m; i++){

	}
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
*/