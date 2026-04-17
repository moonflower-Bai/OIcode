#include <bits/stdc++.h>
#include <vector>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
ll n, p, k;
struct matrix {
	vector<vector<ll>> a;
	int n;
	matrix(int n)
	{
		a = vector<vector<ll>>(n, vector<ll>(n));
		this->n = n;
	}
	vector<ll>& operator[](int i)
	{
		return a[i];
	}
	matrix operator*(matrix &b) const
	{
		matrix res(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					res[i][j] = (res[i][j] + a[i][k] * b[k][j]) % p;
				}
			}
		}
		return res;
	}
};

matrix m_pow(matrix a, ll b)
{
	matrix res(a.n);
	for (int i = 0; i < a.n; i++) {
		res[i][i] = 1;
	}
	while (b) {
		if (b & 1) {
			res = res * a;
		}
		a = a * a;
		b >>= 1;
	}
	return res;
}

bool check(ull state){
	ull x = state;
	bool vis[10] = {0};
	int num[10] = {0};
	int cnt = 0;
	while(x){
		int a = x % 10;
		if(vis[a]) return false;
		num[++cnt] = a;
		if(abs(num[cnt - 1] - a) > 5) return false;
		vis[a] = 1;
		x /= 10;
	}
	int cnt_up = 0, cnt_down = 0;
	for(int i = 1; i <= cnt; i++){
		if(num[i] > num[i-1] && num[i] > num[i+1]) cnt_up++;
		else if(num[i] < num[i-1] && num[i] < num[i+1]) cnt_down++;
	}
	if(cnt_up + cnt_down > 1) return false;
	return true;
	
}

int main()
{
	cin >> n >> p;
	cin >> k;
	
	// 暴搜所有合法状态
	dfs();

	
	return 0;
}