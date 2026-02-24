#include<bits/stdc++.h>
using namespace std;
const int qwe = 1e6+5;
int n, m;
int a[qwe];
int main(){
    cin >> n >> m;
    int sum = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        sum += a[i];
    }

    if(sum <= m){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;
}