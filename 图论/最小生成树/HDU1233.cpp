#include <cstdio>
#include <algorithm>
using namespace std;
const int qwe = 1e6+5;
int n;
class Graph{
public:
    struct Edge{
        int u, v, w;
    };
    Edge* edge;
    int* hd;
    int cnt = 0;
    Graph(int w){
        edge = new Edge[w];
        hd = new int[w];
    }
    void add(int u, int v, int w){
        edge[++cnt].u = u;
        edge[cnt].v = v;
        edge[cnt].w = w;
    }
    ~Graph(){
        delete[] edge;
        delete[] hd;
    }
} g(qwe);
int main(){
    scanf("%d", &n);
    if(n == 0){
        return 0;
    }
    for(int i = 1; i <= n; i++){
        int u, v ,w;
        scanf("%d %d %d", &u, &v, &w);
        g.add(u, v, w);
        g.add(v, u, w);
    }
    sort(g.edge + 1, g.edge + g.cnt + 1, [](Graph::Edge x, Graph::Edge y){
        return x.w < y.w;
    });
    for(int i = 1; i <= n; i++){
        
    }
}