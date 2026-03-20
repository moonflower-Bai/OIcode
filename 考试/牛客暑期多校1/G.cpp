#include <bits/stdc++.h>
using namespace std;
#define ll long long
string s;
int n, q;
template<typename T>
void Debug(string name, T value = 0){
#ifdef _Debug
    cerr << "Debug :" << name << " " << value << endl;
#endif
}
ll cal(ll x){
    return 1ll * x * (x + 1) / 2;
}
ll sol(string t, int a){
    ll cnt = 0, ret = 0;
    int len = t.length();
    for(int i = 0; i < len; i++){
        if(s[i + a - 1] == t[i]){
            cnt++;
        }
        else{
            ret += cal(cnt);
            cnt = 0;
        }
    }
    ret += cal(cnt);
    return ret;
}
int main(){
    cin >> n >> q;
    cin >> s;
    for(int i = 1; i <= q; i++){
        string t;
        int a;
        cin >> t >> a;
        ll ans = sol(t,a);
        cout << ans << endl;
    }
    return 0;
}
/*
10 3
helloworld
follow 1
echo 2
nowgold 4

10 1
helloworld
hello 1

14 1
abcdefghijklmn
qwerty 1
*/