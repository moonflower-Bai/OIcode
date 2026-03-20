#include<bits/stdc++.h>
#define MAXN 200010
#define lson now << 1
#define rson now << 1 | 1
using namespace std;
typedef long long ll;
struct node{
    int l, r;
    int val;
};
int n, q, m, t;
ll a[MAXN], b[MAXN], disc[MAXN << 1], ask[MAXN][2];

// --------------- 权值线段树 -------------
node tree[MAXN << 3];
void push_up(int now){
    tree[now].val = tree[lson].val + tree[rson].val;
}
void build(int now, int l, int r){
    tree[now].l = l; tree[now].r = r;
    if(l == r){
        tree[now].val = 0;
        return ;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    push_up(now);
}
void update(int now, int k, int x){
    if(tree[now].l == k && tree[now].r == k){
        tree[now].val += x;
        return ;
    }
    int mid = (tree[now].l + tree[now].r) >> 1;
    if(k <= mid) update(lson, k, x);
    else update(rson, k, x);
    push_up(now);
}
int query_kth(int now, int k){
    if(tree[now].l == tree[now].r) return tree[now].l;
    if(k <= tree[rson].val) return query_kth(rson, k);
    else return query_kth(lson, k - tree[rson].val);
}
int query_rank(int now, int x){
    if(tree[now].r <= x) return tree[now].val;
    int mid = (tree[now].l + tree[now].r) >> 1;
    if(x <= mid) return query_rank(lson, x);
    else return tree[lson].val + query_rank(rson, x);
}

// 
int get_id(ll x){
    return lower_bound(disc + 1, disc + m + 1, x) - disc;
}
int main(){
    // freopen("in.txt", "r", stdin);
    scanf("%d",&t);
    while(t--){
        m = 0;
        scanf("%d%d",&n,&q);
        for(int i = 1; i <= n; i++) scanf("%lld",&a[i]), disc[++m] = a[i], b[i] = a[i];
        for(int i = 1; i <= q; i++) scanf("%lld%lld",&ask[i][0],&ask[i][1]);
        for(int i = 1; i <= q; i++){
            b[ask[i][0]] += ask[i][1];
            disc[++m] = b[ask[i][0]];
        }
        sort(disc + 1, disc + m + 1);
        m = unique(disc + 1, disc + m + 1) - disc - 1;
        // for(int i = 1; i <= m; i++) printf("%lld ",disc[i]);
        // printf("\n");
        build(1, 1, m);
        for(int i = 1; i <= n; i++) update(1, get_id(a[i]), 1);
        int k = ceil(n / 2);
        for(int i = 1; i <= q; i++){
            int p = ask[i][0]; ll v = ask[i][1];
            update(1, get_id(a[p]), -1);
            a[p] += v;
            update(1, get_id(a[p]), +1);
            int x = query_kth(1, k);
            int res = query_rank(1, x - 1);
            printf("%d\n",res);
        }
    }
    return 0;
}
/*
 2
 5 3
 1 2 3 4 5
 2 1
 3 2
 2 1
 4 2
 4 5 2 3
 4 1
 4 3
*/