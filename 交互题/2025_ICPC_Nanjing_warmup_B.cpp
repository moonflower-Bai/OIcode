#include <bits/stdc++.h>
using namespace std;
int l, r, T;
namespace IA{
    void query(int a){
        cout << "? " << a << '\n' << flush;
    }
    void guess(int a){
        cout << "! " << a << '\n' << flush;
    }
}
int main(){
    cin >> T;
    while(T--){
        cin >> l >> r;
        IA::query(l);
        int x = 0;
        cin >> x;
        IA::guess(l + x);
    }
    return 0;
}