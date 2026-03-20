#include <bits/stdc++.h>
using namespace std;
int T;
int n, cnt = 0;
bool a[105];
int main(){
    cin >> T;
    while(T--){
        cin >> n;
        cnt = 0;
        for(int i = 1; i <= n; i++){
            int x;
            cin >> x;
            if(a[x] == 0){
                a[x] = 1;
                cnt++;
            }
        }
        cout << cnt * 2 - 1 << endl;
        memset(a, 0, sizeof(a));
    }
    return 0;
}