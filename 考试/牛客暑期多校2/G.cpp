#include<bits/stdc++.h>
#define MAXN 500010
#define pi acos(-1)
using namespace std;
typedef double lf;
typedef long long ll;
struct coor{ ll x, y; };
int T;
int n;
ll dis[MAXN];
coor s, p[MAXN];
ll dis_square(coor a, coor b){
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}
double atan2pi(double x, double y){
    if(x == 0 && y > 0) return pi / 2;
    if(x == 0 && y < 0) return pi / 2 + pi; 
    if(y == 0 && x > 0) return 0;
    if(y == 0 && x < 0) return pi;
    double base_ang = atan2(fabs(y), fabs(x));
    if(x < 0 && y > 0) return pi - base_ang;
    if(x < 0 && y < 0) return pi + base_ang;
    if(x > 0 && y < 0) return pi * 2 - base_ang;
    return base_ang;
}
double dif_ang(double ang1, double ang2){
    double res = ang1 - ang2;
    if(res < 0) res += 2 * pi;
    return res;
}
bool if_cross(coor s, coor p1, coor p2){
    if(p1.y < s.y && p2.y < s.y) return false;
    if(p1.y > s.y && p2.y > s.y) return false;
    if(p1.x > s.x && p1.y == s.y) return false;
    lf r = (p1.x - p2.x) * s.y + p1.y * p2.x - p1.x * p2.y;
    r /= (p1.y - p2.y);
//     printf("r = %lf\n",1.0 * r / (p1.y - p2.y));
    return r > s.x;
}
int main(){
    // freopen("in.txt", "r", stdin);
    scanf("%d",&T);
    while(T--){
        scanf("%d%lld%lld",&n,&s.x,&s.y);
        for(int i = 1; i <= n; i++) scanf("%lld%lld",&p[i].x,&p[i].y);
        int cnt = if_cross(s, p[n], p[1]);
        for(int i = 2; i <= n; i++){
            cnt += if_cross(s, p[i - 1], p[i]);
        }
        if(cnt == 2){
            printf("%.15lf\n",2 * pi);
            continue;
        }
        ll dmx = 0;
        for(int i = 1; i <= n; i++){
            dis[i] = dis_square(s, p[i]);
            if(dis[i] > dmx){
                dmx = dis[i];
            }
        }
        vector<double> ang;
        for(int i = 1; i <= n; i++){
            if(dis[i] == dmx){
                ang.push_back(atan2pi((lf)p[i].x - s.x, (lf)p[i].y - s.y));
            }
        }
        if(ang.size() == 1){
            printf("%.15lf\n",2 * pi);
        }else{
            lf amx = dif_ang(ang[0], ang.back());
            for(int i = 1; i < ang.size(); i++){
                amx = max(amx, dif_ang(ang[i], ang[i - 1]));
            }
            printf("%.15lf\n",amx);
        }
    }
    return 0;
}
/*
1
4 0 0
-1 -1
0 1
1 0
1 1
*/