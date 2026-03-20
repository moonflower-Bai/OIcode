#include <bits/stdc++.h>
using namespace std;
const int N = 1e2 + 5;
const int M = 15;
const int mod = 1e8;
int n_1, n_2, k_1, k_2;
int f[N * 2][M][M];
int main()
{
	cin >> n_1 >> n_2 >> k_1 >> k_2;
    int m_1 = min(n_1, k_1);
    int m_2 = min(n_2, k_2);
	for(int i = 1; i <= n_1 + n_2; i++){
        f[i][0][0] = 0;
        for(int j = 1; j <= )
    }
	for (int i = 2; i <= n_1 + n_2; i++) {
		for (int j = 1; j <= m_1; j++) {
			for (int k = 1; k <= m_2; k++) {
				f[i][j][k] = f[i - 1][j][k - 1] + f[i - 1][j - 1][k]
                    + f[i - ]
			}
		}
	}
	for (int i = 1; i <= n_1 + n_2; i++) {
		for (int j = 0; j <= m_1; j++) {
			for (int k = 0; k <= m_2; k++) {
				cout << format("f[{}][{}][{}] = {}\n", i, j, k, f[i][j][k]);
			}
		}
	}
	cout << f[n_1 + n_2][m_1][m_2] << endl;
    return 0;
}