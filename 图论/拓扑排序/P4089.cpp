#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
struct Edge {
	int nxt, to;
} edge[N];
int cnt = 0;
int hd[N];
void add(int u, int v)
{
	edge[++cnt] = {hd[u], v};
	hd[u] = cnt;
}
int n;
int a[N];
int in[N];
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		add(i, a[i]);
		in[a[i]]++;
	}
	queue<int> q;
	while (q.size()) {
		q.pop();
	}
	for (int i = 1; i <= n; i++) {
		if (in[i] == 0) {
			q.push(i);
		}
	}
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = hd[u]; i; i = edge[i].nxt) {
			int v = edge[i].to;
			if (v != u) {
				in[v]--;
				if (in[v] == 0) {
					q.push(v);
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (in[i] != 0) {
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}