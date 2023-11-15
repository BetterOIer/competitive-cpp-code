/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,k;
vector<int>ro[50004];
int fa[50004][21],dep[50004],cfTr[50004];
void dfs(int pos,int fat){
    dep[pos]=dep[fat]+1;
    fa[pos][0]=fat;
    for(int i:ro[pos]){
        if(i==fat)continue;
        dfs(i,pos);
    }
}
int getLCA(int u,int v){
    if(dep[u]<dep[v])swap(u,v);
    if(dep[u]>dep[v]){for(int i = 20;i>=0;i--){
        if(dep[fa[u][i]]>dep[v])u=fa[u][i];
    }u=fa[u][0];}if(u==v)return u;
    for(int i = 20;i>=0;i--){
        if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
    }return fa[u][0];
}
int ans=0;
void dfs2(int pos,int fa){
    for(int i:ro[pos]){
        if(i==fa)continue;
        dfs2(i,pos);
        cfTr[pos]+=cfTr[i];
    }
    ans=max(ans,cfTr[pos]);
}
int main(){
    n=read(),k=read();
    for(int i = 1,u,v;i<n;i++){
        u=read(),v=read();
        ro[u].push_back(v);
        ro[v].push_back(u);
    }
    dfs(1,0);
    for(int i =1 ;i<=20;i++){
        for(int j = 1;j<=n;j++){
            fa[j][i]=fa[fa[j][i-1]][i-1];
        }
    }
    for(int i = 1,s,t;i<=k;i++){
        s=read(),t=read();
        int lca=getLCA(s,t);
        cfTr[lca]--;cfTr[fa[lca][0]]--;
        cfTr[s]++,cfTr[t]++;
    }
    dfs2(1,0);
    cout<<ans;
    return 0;
}