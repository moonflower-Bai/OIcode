#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int qwe = 1e5+5;
const int R = 1e3+5;
struct Edge{
    int nxt, to, w;
} edge[qwe];
int hd[qwe], cnt = 0;
void add(int u, int v, int w){
    edge[++cnt].nxt = hd[u];
    edge[cnt].to = v;
    edge[cnt].w = w;
    hd[u] = cnt++;
}

int n, m, r, k, c;
int w[qwe];
map<pair<int, int>, bool> firewall;

int s,t;
priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> q;
ll dis[qwe];
bool vis[qwe];
bool dij_aviliable(int m_k){
    while(q.size()) q.pop();
    q.push({0, s});
    dis[s] = 0;
    if(w[s] < m_k){
        return 0;
    }
    while(!q.empty()){
        int u = q.top().second;
        q.pop();
        if(vis[u]) continue;
        vis[u] = 1;
        for(int i = hd[u]; i; i = edge[i].nxt){
            int v = edge[i].to;
            if(!firewall[{u, v}] && dis[v] > dis[u] + edge[i].w && w[v] >= m_k){
                dis[v] = dis[u] + edge[i].w;
                // cerr << "Update the distance from " << u << " to " << v << " :" << dis[v] << endl;
                q.push({dis[v], v});
            }
        }
    }
    if(dis[t] < c){
        return 1;
    }
    else{
        return 0;
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m >> r >> k >> c;
    for(int i = 1; i <= n; i++){
        cin >> w[i];
    }
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        add(u, v, w);
        add(v, u, w);
    }
    for(int i = 1; i <= r; i++){
        int u, v;
        cin >> u >> v;
        firewall[{u, v}] = 1;
    }
    cin >> s >> t;
    for(int i = 1; i <= n; i++){
        dis[i] = 0x7f7f7f7f;
        vis[i] = 0;
    }
    if(dij_aviliable(k)){
        // cerr << "dis[t] = " << dis[t] << endl;
        cout << "OK";
        return 0;
    }
    int m_l = 0, m_r = k, m_mid;
    while(m_l < m_r){
        m_mid = (m_l + m_r + 1) >> 1;
        // cerr << "l = " << m_l << ", r = " << m_r << ", mid = " << m_mid << endl;
        for(int i = 1; i <= n; i++){
            dis[i] = 0x7f7f7f7f;
            vis[i] = 0;
        }
        if(dij_aviliable(m_mid)){
            m_l = m_mid;
        }
        else{
            m_r = m_mid - 1;
        }
    }
    if(m_l == 0){
        cout << "nkuImpact";
    }
    else{
        cout << m_l;
    }
    return 0;
}