#include <bits/stdc++.h>
using namespace std;
// #define int long long
const int qwe = 1e6+5;
int n, m;
int deg[qwe];
vector<int> p[qwe];
struct Edge{
    int to, nxt;
    long long w;
} edge[qwe];
int cnt = 0, hd[qwe];
void add(int u, int v, long long w){
    cnt++;
    edge[cnt] = {v, hd[u], w};
    hd[u] = cnt;
}

struct Node{
    int id;
    long long w;
    Node(int id, long long w): id(id), w(w) {};
    bool operator<(const Node& a) const{
        return w > a.w;
    }
};
priority_queue<Node> q;
long long dis1[qwe], dis2[qwe];
bool vis[qwe];
void dij(){
    for(int i = 1; i <= n; i++){
        dis1[i] = (1ll << 60);
        dis2[i] = 0;
        vis[i] = 0;
    }
    dis1[1] = dis2[1] = 0;
    q.emplace(Node(1, 0));
    while(!q.empty()){
        auto tmp = q.top();
        q.pop();
        int u = tmp.id;
        long long dis = tmp.w;
        /*
        1 13 12 12 11 7 7 2 2 3 3 3 3 3 9 9 9 9 10 5 9 5 4 14 14 8 14 14 6 6 6 6 6 15 2 2 2 9 9 3 11 7 7 6 6 6 6 6 6 4 4
        1 13 12 12 11 7 7 2 2 3 3 3 3 3 9 9 9 9 10 5 9 5 4 6 6 15 6 14 14 14 14 14 14 8 2 2 2 9 9 3 11 7 7 6 6 6 6 6 6 4 4
        */
       if(vis[u]){
           continue;
        }
        // cerr << u << ' ';
        /*
        1 13 12 11 7 2 3 9 10 5 4 14 8 6 15
        1 13 12 11 7 2 3 9 10 5 4 6 15 14 8

        */
        vis[u] = 1;
        // cerr << "[debug] hd[u] = " << hd[u] << endl;
        for(int i = hd[u]; i; i = edge[i].nxt){
            int v = edge[i].to;
            // cerr << "v = " << v << endl;
            // if(dis1[v] > dis1[u] + edge[i].w){
            //     dis1[v] = dis1[u] + edge[i].w;
            // }
            dis1[v] = min(dis1[v], dis + edge[i].w);
        }
        for(int i = 0; i < p[u].size(); i++){
            int v = p[u][i];
            deg[v]--;
            dis2[v] = max(dis2[v], dis);
        }
        for(int i = 1; i <= n; i++){
            if(!vis[i] && deg[i] == 0){
                // cerr << "add " << i << " in queue" << endl;
                q.push(Node(i, max(dis1[i], dis2[i])));
                // cerr << max(dis1[i], dis2[i]) << ' ';
                /*
                0 774781 4677433 7041916 854448 499 361 361 774781 1232 7041916 854448 6461009 499 499 774781 1232 7989193 880 1248 639 499 639 992 1232 7989193 880 1248 880 992 1232 7989193 1248 880 992 1232 7989193 1248 992 1232 7989193 1248 1232 1232 1232 1232 1248 8331780 1248 7989193 1248 1489 1248 1248 1248 1248 8331780 1248 1667 1489 1248 1370 1667 1489 1248 1248 1370 1667 1489 1489 1667 1489 1489 1489 1667 1489 1489 1667 1957 1667 1667 1667 1667 1957 774781 774781 774781 854448 854448 4677433 6461009 7041916 7041916 7989193 7989193 7989193 7989193 7989193 7989193 8331780 8331780
                774781 4677433 7041916 854448 499 361 774781 1232 7041916 854448 6461009 499 774781 1232 7989193 880 1248 639 992 1232 7989193 880 1248 992 1232 7989193 1248 1232 7989193 1248 7989193 1248 8331780 1248 7989193 1248 1489 8331780 1248 1420 1489 1248 1420 1489 1420 1489 1489 1420 1489 1489
                */
            }
        }
        // for(int i = 1; i <= n ;i++){
        //     cerr << deg[i] <<  ' ';
        // }
        // cerr << endl;
    }
}

// void dij()
// {
//     for (int i = 1; i <= n; i++)
//         dis1[i] = 1LL << 60, dis2[i] = 0;
//     dis1[1] = dis2[1] = 0;
//     q.push(Node(1, 0));
//     while (!q.empty())
//     {
//         Node u = q.top();
//         q.pop();
//         if (vis[u.id])
//             continue;
//         vis[u.id] = true;
//         for (int i = hd[u.id]; i; i = edge[i].nxt)
//         {
//             int v = edge[i].to;
//             dis1[v] = min(dis1[v], u.w + edge[i].nxt);
//             //  printf( "%d(%I64d) to %d(%I64d)  len = %d\n" , u.x , u.dis , v , dis1[v] , p[i].len ) ;
//         }
//         for (int i = 0, siz = p[u.id].size(); i < siz; i++)
//         {
//             int v = p[u.id][i];
//             deg[v]--;
//             dis2[v] = max(dis2[v], u.w);
//             //  printf( "%d(%I64d) to %d(%I64d)\n" , u.x , u.dis , v , dis2[v] ) ;
//         }
//         for (int i = 1; i <= n; i++)
//             if (!vis[i] && deg[i] == 0)
//                 q.push(Node(i, max(dis1[i], dis2[i])));
//     }
//     printf("%lld", max(dis1[n], dis2[n]));
// }

signed main(){
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int u, v;
        long long w;
        cin >> u >> v >> w;
        // cerr << "[debug] " << u << ' ' << v << ' ' << w << endl;
        add(u, v, w);
    }
    // for(int i = 1; i <= n; i++){
    //     cerr << hd[i] << ' ';
    // }
    for(int i = 1; i <= n; i++){
        cin >> deg[i];
        for(int j = 1; j <= deg[i]; j++){
            int x;
            cin >> x;
            p[x].push_back(i);
        }
    }
    dij();
    cout << max(dis1[n], dis2[n]) << endl;
    return 0;
}