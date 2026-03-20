#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define _x first
#define _y second
const int N = 1e6+5;
const int M = 1e6+5;
#define ll long long
int n, m, q;
PII lne[N], qur[N];
struct SegmentTree{
    struct Tree{
        int l, r, a, b;
    } t[N];
    int cnt = 0;
    int build(int l, int r){
        int rt = ++ cnt;
        if(l == r){
            return rt;
        }
        int mid = (l + r) >> 1;
        t[rt].l = build(l, mid);
        t[rt].r = build(mid + 1, r);
        return rt;
    }
    int update(int k, int l, int r, int root){
        
    }
};
int main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        cin >> lne[i]._x >> lne[i]._y;
        a[lne[i]._x] ++;
        a[lne[i]._y + 1] --;
        b[lne[i]._y] --;

    }
    cin >> q;
    for(int i = 1; i <= q; i++){
        int l, r;
        cin >> l >> r;

    }
    return 0;
}