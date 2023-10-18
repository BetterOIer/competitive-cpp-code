#include<iostream>
#include<cstdio>
using namespace std;
const int mod = 1e9+7;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n,ans;
int l[505],r[505];
void add(){
    if(ans==mod-1)ans=0;
    else ++ans;
}
void dfs(int pos,int preLowLim,int havDel){
    if(pos==n+1){
        if(havDel==n)return;
        return add(),void();
    }
    int lowLim = max(preLowLim,l[pos]),uppLim = r[pos];
    for(int i = lowLim;i<=uppLim;i++){
        dfs(pos+1,i+1,havDel);
    }
    dfs(pos+1,preLowLim,havDel+1);
}
int main(){
    freopen("seq.in","r",stdin);
    freopen("seq.out","w",stdout);
    n=read();
    for(int i = 1;i<=n;i++){
        l[i]=read();r[i]=read();
    }
    dfs(1,1,0);
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}