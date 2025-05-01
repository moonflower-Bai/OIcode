#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
// #define int long long
const int qwe = 1e6 + 5;
int n, m;
struct Edge
{
    int w, u, v;
} edge[qwe];
int cnt = 0;
void add(int u, int v, int w)
{
    edge[++cnt].w = w;
    edge[cnt].u = u;
    edge[cnt].v = v;
}
int fa[qwe];
int fnd(int x)
{
    if (fa[x] == x)
    {
        return x;
    }
    return fa[x] = fnd(fa[x]);
}
void add(int u, int v)
{
    int x = fnd(u), y = fnd(v);
    if (x == y)
    {
        return;
    }
    fa[x] = y;
    return;
}
int cost = 0;
bool cmp(Edge x, Edge y)
{
    return x.w < y.w;
}
signed main()
{
    while (scanf("%d", &n) != EOF)
    {
        // scanf("%lld", &n);
        for (int i = 1; i <= n; i++)
        {
            fa[i] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                int w;
                cin >> w;
                if (i == j)
                {
                    continue;
                }
                add(i, j, w);
            }
        }
        scanf("%d", &m);
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            scanf("%d %d", &u, &v);
            add(u, v);
        }
        // sort(edge + 1, edge + cnt + 1, [](Edge x, Edge y){
        //     return x.w < y.w;
        // });
        sort(edge + 1, edge + cnt + 1, cmp);
        for (int i = 1; i <= cnt; i++)
        {
            int u = edge[i].u, v = edge[i].v;
            int x = fnd(fa[u]), y = fnd(fa[v]);
            if (x == y)
            {
                continue;
            }
            add(u, v);
            cost += edge[i].w;
        }
        cout << cost << endl;
        cnt=0;
        cost = 0;
    }
}