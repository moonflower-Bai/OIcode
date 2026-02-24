#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
const int ed = 1e6 + 1;
int T, n, m;
vector<pair<int, int> > ee;
int hd[qwe], cnt = 1;
struct Edge{
    int to, nxt, w, from;
} e[qwe];
void add(int u, int v, int w){
    e[++cnt] = {v, hd[u], w, u};
    hd[u] = cnt;
}

Edge edge[qwe];
int cntNew = 0;
int head[qwe];
void add_new(int u, int v, int w){
    edge[++cntNew] = {v, head[u], w};
    head[u] = cntNew;
}
namespace Tarjan{
    int dfn[qwe], low[qwe];
    bool b[qwe]; // bridge
    int cnt;
    int k = 0;
    int c[qwe];
    stack<int> s;
    int vis[qwe];
    void init(){
        for(int i = 1; i <= n; i++){
            dfn[i] = 0;
            low[i] = 0;
        }
        cnt = 0;
        k = 0;
        while(!s.empty()) s.pop();
    }
    void tarjan(int u, int in_edge){
        dfn[u] = low[u] = ++cnt;
        s.push(u);
        vis[u] = 1;
        for(int i = hd[u]; i; i = e[i].nxt){
            int v = e[i].to;
            if(!dfn[v]){
                tarjan(v, i);
                low[u] = min(low[u], low[v]);
            }
            else if(vis[v] && (i != (in_edge ^ 1))){
                low[u]=min(low[u],dfn[v]);
            }
        }
        if(dfn[u] == low[u]){
            k++;
            int y;
            do{
                y = s.top();
                s.pop();
                c[y] = k;
                vis[y] = 0;
            }while(y!=u);
        }
    }
}

namespace ShortestPath{
    struct Node
    {
        int pid, eid, w;
        Node(int pid, int eid, int w) : pid(pid), eid(eid), w(w) {};
        bool operator<(const Node& a) const {
            return w > a.w;
        }
    };
    
    priority_queue<Node> q;
    int dis[qwe], ans[qwe];
    set<int> path;
    void init(){
        while(q.size()) q.pop();
        memset(dis, 0x3f, sizeof(dis));
        for(int i = 1; i <= n; i++){
            ans[i] = 0;
        }
        path.clear();
    }
    bool dfs(int u, int fa){
        if(u == Tarjan::c[n]) return 1;
        for(int i = head[u]; i; i = edge[i].nxt){
            int v = edge[i].to;
            if(v == fa) continue;
            if(dfs(v, u)){
                path.insert(edge[i].w);
                return true;
            }

        }
        return false;
    }

    void dij(){
        for(auto x: path){
            int u = ee[x].first, v = ee[x].second;
            if(ans[u] == 0){
                q.emplace(u, x, 0);
                ans[u] = x;
                dis[u] = 0;
            }
            if(ans[v] == 0){
                q.emplace(v, x, 0);
                ans[v] = x;
                dis[v] = 0;
            }
        }
        while(!q.empty()){
            auto pnt = q.top();
            int u = pnt.pid;
            q.pop();
            if(dis[u] != pnt.w){
                continue;
            }
            for(int i = hd[u]; i; i = e[i].nxt){
                int v = e[i].to;
                if(dis[u] + 1 < dis[v] || (dis[u] + 1 == dis[v] && ans[u] < ans[v])){
                    dis[v] = dis[u] + 1;
                    ans[v] = ans[u];
                    q.emplace(v, ans[v], dis[v]);
                }
            }
        }
    }
}

void init(){
    ee.clear();
    cnt = 1;
    cntNew = 1;
    for(int i = 1; i <= n; i++){
        hd[i] = head[i] = 0;
    }
    Tarjan::init();
    ShortestPath::init();
}

int main(){
    cin >> T;
    while(T--){
        init();
        cin >> n >> m;
        ee.reserve(m + 1);
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            ee[i] = {u, v};
            add(u, v, 1);
            add(v, u, 1);
        }
        {
            using namespace Tarjan;
            for(int i = 1; i <= n; i++){
                if(!dfn[i]){
                    tarjan(i, 0);
                }
            }
            for(int i = 1; i <= m; i++){
                int x = ee[i].first, y = ee[i].second;
                if(c[x] != c[y]){
                    add_new(c[x], c[y], i);
                    add_new(c[y], c[x], i);
                }
            }
        }
        {
            using namespace ShortestPath;
            dfs(Tarjan::c[1], 0);
            dij();
            int q;
            cin >> q;
            for(int i = 1; i <= q; i++){
                int c;
                cin >> c;
                cout << (ans[c] == 0 ? -1 : ans[c]) << ' ';
            }
            cout << endl;
        }
    }
    return 0;
}
/*
2
5 4
1 2
2 3
3 4
4 5
3
1
2
3
7 6
1 2
1 5
2 3
3 4
5 7
6 7
7
1
2
3
4
5
6
7

*/