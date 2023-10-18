#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n;
vector<int>tr[100005];
int dep[100005],siz[100005];
int dfs(int pos,int fa){
    dep[pos]=dep[fa]+1;
    int posSize = 1;
    for(int to:tr[pos]){
        if(to==fa)continue;
        posSize+=dfs(to,pos);
    }
    return siz[pos]=posSize;
}
int main(){
    freopen("dfs.in","r",stdin);
    freopen("dfs.out","w",stdout);
    n=read();
    for(int i = 1,u,v;i<n;i++){
        u=read(),v=read();
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    dfs(1,0);
    for(int i = 1;i<=n;i++){
        cout<<dep[i]<<" "<<n-siz[i]+1<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}