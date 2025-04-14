#include <iostream>
using namespace std;
const int qwe = 1e6+5;
int T;
int n, m, cnt;

int fa[qwe];
int fnd(int x){
    if(fa[x] == x){
        return x;
    }
    return fa[x] = fnd(fa[x]);
}
void add(int u, int v){
    int x = fnd(fa[u]), y = fnd(fa[v]);
    if(x == y){
        return;
    }
    fa[x] = fnd(fa[y]);
    cnt--;
}
void init(){
    cnt = n;
    for(int i = 1; i <= n; i++){
        fa[i] = i;
    }
}
int main(){
    cin >> T;
    while(T--){
        cin >> n >> m;
        init();
        for(int i = 1; i <= m; i++){
            int u, v;
            cin >> u >> v;
            add(u, v);
        }
        cout << cnt << endl;
    }
    return 0;
}