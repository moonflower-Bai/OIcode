#include<bits/stdc++.h>
#define MAXN 500010
using namespace std;
typedef long long ll;
int n, t;
ll a[MAXN], bit[70];
int main(){
    scanf("%d",&t);
    bit[0] = 1;
    for(int i = 1; i <= 62; i++) bit[i] = bit[i - 1] * 2;
    while(t--){
        scanf("%d",&n);
        for(int i = 1; i <= n; i++) scanf("%lld",&a[i]);
        sort(a + 1, a + n + 1);
        ll sum = a[n];
        bool flag = true;
        for(int i = n - 1; i >= 1; i--){
            int p = upper_bound(bit, bit + 63 + 1, a[i]) - bit - 1;
            if((sum >> p) & 1){
                flag = false;
                break;
            }
            sum |= a[i];
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}