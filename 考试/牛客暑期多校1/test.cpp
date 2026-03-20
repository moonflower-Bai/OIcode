#include <bits/stdc++.h>
using namespace std;
set<int> s;
int main(){
    freopen("test.in", "w", stdout);
    for(int i = 1; i <= 1e3; i++){
        for(int j = 1; j < i; j++){
            s.insert(i * i - j * j);
        }
    }
    // sort(s.begin(), s.end());
    for(auto _:s){
        cout << _ << ' ';
    }
}