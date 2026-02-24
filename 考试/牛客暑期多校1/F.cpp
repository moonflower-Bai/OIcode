#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int T;
int n;
int r, d;
int u, v, w;
int x, y, z;
int main(){
    cin >> T;
    while(T--){
        cin >> r >> d;
        double st[3], ed[3];
        cin >> u >> v >> w;
        cin >> x >> y >> z;
        double StNormSqua = u * u + v * v + w * w;
        double EdNormSqua = x * x + y * y + z * z;
        st[0] = r * u / sqrt(StNormSqua);
        st[1] = r * v / sqrt(StNormSqua);
        st[2] = r * w / sqrt(StNormSqua);

        ed[0] = x * r / sqrt(EdNormSqua);
        ed[1] = y * r / sqrt(EdNormSqua);
        ed[2] = z * r / sqrt(EdNormSqua);
    }
}