#include<bits/stdc++.h>
using namespace std;
const int qwe=1e6+5;
int n,m;
int nxt[qwe];
char sa[qwe],sb[qwe];
void work(){
    int j=0;
    for(int i=2;i<=m;i++){
        while(j>0&&sb[i]!=sb[j+1]){
            j=nxt[j];
        }
        if(sb[i]==sb[j+1]){
            j++;
        }
        nxt[i]=j;
    }
}
// sa: acabcabdabcabc
// sb: abcabd
int main(){
    // scanf("%s",sa+1);
    // scanf("%s",sb+1);
    // cin.getline(sa+1,qwe-1);
    // cin.getline(sb+1,qwe-1);
    int i=1;
    while((sa[i]=getchar())!='\n') i++;
    n=i;
    i=1;
    while((sb[i]=getchar())!='\n') i++;
    m=i;
    //cout<<sa+1<<endl<<sb+1<<endl;
    // n=strlen(sa+1)-1;
    // m=strlen(sb+1)-1;
    cout<<n<<' '<<m<<endl;
    nxt[1]=0;
    work();
    cerr << "[debug]";
    for(int i = 1; i <= m; i++){
        cerr << nxt[i] << ' ';
    }
    cerr << endl;
    int j=0;
    for(int i=1;i<=n;i++){
        while(j>0&&sa[i]!=sb[j+1]){
            j=nxt[j];
        }
        if(sa[i]==sb[j+1]){
            j++;
        }
        if(j==m){
            printf("%d\n",i-m+1);
            j=nxt[j];
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d ",nxt[i]);
    }
    return 0;
}