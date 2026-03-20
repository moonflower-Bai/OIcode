#include <bits/stdc++.h>
#include <cstring>
using namespace std;
const int N = 1e6 + 5;
int n, a, b, c;
int w[5];
int f[N];
int main()
{
	cin >> n >> a >> b >> c;
	w[1] = a;
	w[2] = b;
	w[3] = c;
    memset(f, -1, sizeof(f));
	f[0] = 0;
	for (int i = 1; i <= 3; i++) {
		for (int j = w[i]; j <= n; j++) {
            if(f[j - w[i]] != -1)
			    f[j] = max(f[j], f[j - w[i]] + 1);
		}
	}
	cout << f[n] << endl;
	return 0;
}
