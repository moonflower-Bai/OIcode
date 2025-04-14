#include <iostream>
using namespace std;
const int qwe = 1e6+5;
int n, m;
int fa[qwe], size[qwe];
int fnd(int x){
    if(fa[x] == x){
        return x;
    }
    return fa[x] = fnd(fa[x]);
}
bool add(int u, int v){
    int x = fnd(fa[u]), y = fnd(fa[v]);
    // cerr << "add:" << x << ' '<< y << endl;
    // for(int i = 1; i <= 10; i++){
    //     cerr << "fa[i]:" << i << ' ' << fa[i] << endl;
    // }
    if(x == y){
        return 1;
    }
    if(size[x] > size[y]){
        swap(x, y);
    }
    fa[y] = x;
    size[x] += size[y];
    return 0;
}
bool flag;
void init(){
    flag = 0;
    for(int i = 1; i <= 1e5; i++){
        fa[i] = i;
    }
}
int main(){
    while(1){
        init();
        while(1){
            cin >> n >> m;
            if(n == 0 && m == 0){
                if(!flag){
                    cout << "Yes" << endl;
                    // cerr << endl;
                }
                break;
            }
            if(n == -1 && m == -1){
                exit(0);
            }
            // cerr << n << ' ' << m << ' ';
            bool res = add(n, m);
            // cerr << (bool)res << ' ' << fa[n] << ' ' << fa[m] << endl;
            if(res && !flag){
                cout << "No" << endl;
                flag = 1;
            }
        }
    }
    return 0;
}