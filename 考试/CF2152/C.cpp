#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int T;
int n, q;
int a[qwe];
int s[qwe];
int diff[qwe], pre[qwe];
int diff1[qwe], pre1[qwe];
int main(){
    cin >> T;
    while(T--){
        cin >> n >> q;
        s[0] = 0;
        pre[0] = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            s[i] = s[i - 1] + a[i];
            if(a[i] == a[i - 1]){
                diff[i] = 0;
            }
            else{
                diff[i] = 1;
            }
            pre[i] = pre[i - 1] + diff[i];
        }
        for(int i = 1; i <= n; i++){
            if(a[i] == a[i + 1]){
                diff1[i] = 0;
            }
            else{
                diff1[i] = 1;
            }
            pre1[i] = pre1[i - 1] + diff1[i];
        }
        for(int i = 1; i <= q; i++){
            int x, y;
            cin >> x >> y;
            int flag = 0;
            if((pre[y] - pre[x - 1]) == (y - x + 1)){
                flag = 1;
            }
            else if((pre1[y] - pre1[x - 1]) == (y - x + 1)){
                flag = 1;
            }
            int cnt1 = s[y] - s[x - 1];
            int cnt0 = (y - x + 1) - cnt1;
            if(cnt1 % 3 != 0 || cnt0 % 3 != 0){
                cout << -1 << endl;
                continue;
            }
            cout << cnt1 / 3 + cnt0 / 3 + flag << endl;
        }
    }
    return 0;
}
/*
2
12 4
0 0 1 1 0 1 0 1 0 1 1 0
1 12
2 7
4 9
6 11
6 3
0 0 0 1 1 1
1 3
4 6
1 6

*/