#include <bits/stdc++.h>
using namespace std;
const int qwe = 4e5+5;
// const int qwe = 1e2+5;
int n, m;
string s, t;
bitset<qwe> bs, bt, bq, tmp, ans;
bool flag = 0;
int main(){
    freopen("/home/bai/code/test.in", "r", stdin);
    freopen("/home/bai/code/test.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    cin >> s;
    cin >> t;
    for(int i = 0; i < n; i++){
        if(s[i] == '1'){
            bs[i + n] = 1;
        }
        else{
            bs[i + n] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        if(t[i] == '1'){
            bt[i] = 1;
            bt[i + n] = 1;
        }
        else{
            bt[i] = 0;
            bt[i + n] = 0;
        }
        if(t[i] == '?'){
            bq[i] = 0;
            bq[i + n] = 0;
        }
        else{
            bq[i] = 1;
            bq[i + n] = 1;
        }
    }
    m = bt.count() / 2;
    for(int i = 1; i <= n; i++){
        tmp = (bs >> i) & bq;
        ans = tmp & bt;
        // int cnt = ans.count();
        // if(cnt == m && (ans & tmp) == 0){
        if(((ans & bt) == 0) && (ans & tmp) == 0){
            cout << i << ' ';
            flag = 1;
            continue;
        }
    }
    // auto tag_2 = time(nullptr);
    if(!flag){
        cout << "ChiNaTsu*Mission!!!" << endl;
    }
    else{
        cout << endl;
    }
    return 0;
}
/* error tests:
 * 4
 * 1010
 * 1?0?
 * 
 * expected output:
 * ChiNaTsu*Mission!!!
 * 
 * actual output:
 * 0 2
 */