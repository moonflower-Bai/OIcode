#include<bits/stdc++.h>
#define MAXN 600010
#define INF 0x3f3f3f3f
using namespace std;
struct sec{ int k, b; };
bool operator > (sec a, sec b){ return a.k > b.k; }
bool operator < (sec a, sec b){ return a.k < b.k; }
int n;
int a[MAXN], b[MAXN];
double pos[MAXN];
sec s[MAXN];
double cal_cross(sec s1, sec s2){
    return (s2.b - s1.b) * 1.0 / (s1.k - s2.k);
}
int main(){
    scanf("%d",&n);
    for(int i = 1; i <= n; i++) scanf("%d%d",&a[i],&b[i]);
    for(int i = 1; i <= n; i++) b[i] = -b[i];
    for(int i = 1; i <= n; i++) s[i] = (sec){a[i], b[i]};
    sort(s + 1, s + n + 1, gerater<sec>());
    pos[0] = -INF;
    for(int i = 1; i < n; i++){
        s[i] = cal_cross(s[i], s[i + 1]);
    }
    s[n] = INF;
    return 0;
}
// ssh-keygen -t 