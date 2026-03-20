#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
#define ll long long
int n, m;
int a[qwe];
ll s[qwe], sum;
int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s[i] = s[i - 1]  + a[i];
    }
    for(int i = 1; i <= n; i++){
        sum += (s[n] - s[i]) * a[i];
    }
    cout << sum;
    return 0;
}