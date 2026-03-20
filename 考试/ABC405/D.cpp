#include <bits/stdc++.h>
using namespace std;
int n, m;
const int N = 2001;
char mp[N][N];
struct node {
	int x, y;
};
queue <node> q;
int dis[N][N];
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
int dir[N][N];
int main() {
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		cin >> (mp[i] + 1);
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			dis[i][j] = n + m + 1;
			dir[i][j] = -1;
		}	
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(mp[i][j] == 'E') {
				dis[i][j] = 0;
				q.push((node){i, j});
			}
		}
	}
	while(!q.empty()) {
		node tmp = q.front(); q.pop();
		for(int i = 0; i < 4; ++i) {
			int nx = tmp.x + dx[i];
			int ny = tmp.y + dy[i];
			if(nx < 1 || ny < 1 || nx > n || ny > m) continue;
			if(mp[nx][ny] == '#') continue;
			if(dir[nx][ny] != -1) continue;
			if(dis[nx][ny] >= n + m + 1) {
				dis[nx][ny] = dis[tmp.x][tmp.y] + 1;
				dir[nx][ny] = i;
				q.push((node){nx, ny});
			}
		}
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			if(mp[i][j] != '.') {
				cout << mp[i][j];
			}
			else {
				if(dir[i][j] == 0) {
					cout << "<";
				}
				if(dir[i][j] == 1) {
					cout << "^";
				}
				if(dir[i][j] == 2) {
					cout << ">";
				}
				if(dir[i][j] == 3) {
					cout << "v";
				}
			}
		}
		cout << '\n';
	}
	return 0;
}