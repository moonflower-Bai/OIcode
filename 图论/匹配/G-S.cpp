#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
int n;
int man[N][N], woman[N][N];
queue<int> q;
int vis[N];
int nxt[N];
int ans[N];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> man[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> woman[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (q.size()) {
		int u = q.front();
		q.pop();
		int i = ++nxt[u];
		int v = man[u][i];
		// nxt[u]++;
		// for (int i = ++nxt[u]; i <= n; i++) {
		if (!vis[v]) {
			vis[v] = u;
		} else if (vis[v]) {
			bool flag = 0;
			int w = vis[v];
			for (int j = 1; j <= n; j++) {
				if (woman[v][j] == w) {
					flag = 0;
					break;
				} else if (woman[v][j] == u) {
					flag = 1;
					break;
				}
			}
			if (flag) {
				vis[v] = u;
				q.push(w);
			} else
				q.push(u);
		}
		// }
	}
	for (int i = 1; i <= n; i++) {
		ans[vis[i]] = i;
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
	return 0;
}