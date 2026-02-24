#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int n, m;
string s, t;
int a[qwe];
int main(){
    cin >> n >> m;
    if(n >= 1200 && n <= 2399 && m == 2){
        cout << "Yes";
    }
    else if(n >= 1600 && n <= 2999 && m == 1){
        cout << "Yes";
    }
    else{
        cout << "No";
    }
    return 0;
}