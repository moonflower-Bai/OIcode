#include <bits/stdc++.h>
using namespace std;
const int qwe = 1e6 + 5;
int T;
int a[qwe], n;
string s;
char ans[qwe];
int main()
{
    cin >> T;
    while (T--)
    {
        cin >> s;
        n = s.length();
        
        int cntt = 0, cntf = 0, cntn = 0;
        for(int i = 0; i < n; i++){
            if(s[i] == 'T') cntt ++;
            if(s[i] == 'F') cntf ++;
            if(s[i] == 'N') cntn ++;
        }
        int j = 0;
        while(cntf < cntn && cntn < cntt){
            cntt--;
            ans[j] = 'T';
            j++;
        }
        for(;j < n;){
            if(cntt > 0){
                ans[j] = 'T';
                j++;
                cntt--;
            }
            if(cntn > 0){
                ans[j] = 'N';
                j++;
                cntn--;
            }
            if(cntf > 0){
                ans[j] = 'F';
                j++;
                cntf--;
            }
            if(cntt == 0 && cntf == 0 && cntn == 0){
                break;
            }
        }
        for(int i = 0; i < n; i++){
            if(s[i] != 'F' && s[i] != 'T' && s[i] != 'N'){
                ans[j] = s[i];
                j++;
            }
        }
        ans[j] = '\0';
        cout << ans << '\n';
    }
    return 0;
}