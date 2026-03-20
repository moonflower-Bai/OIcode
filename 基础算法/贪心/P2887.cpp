#include <bits/stdc++.h>
using namespace std;
#define PII pair<int, int>
#define X first
#define Y second
#define ll long long
const int qwe = 3e3+5;
int c, l, ans;
PII cow[qwe], suns[qwe];
int main(){
    cin >> c >> l;
    for(int i = 1; i <= c i++){
        cin >> cow[i].X >> cow[i].Y;
    }
    for(int i = 1; i <= l; i++){
        cin >> suns[i].X >> suns[i].Y;
    }
    sort(suns + 1, suns + l + 1, [](PII x, PII y){
        return x.X < y.X;
    });
    sort(cow + 1, cow + c + 1, [](PII x, PII y){
        return x.X < y.X;
    });
    for(int i = 1; i <= c; i++){
        for(int j = 1; j <= l; j++){
            
        }
    }
}