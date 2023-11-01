#include<bits/stdc++.h>
using namespace std;
const int N=5e5;
int n,m,u,v,d[N+10],fl[N+10],tt[N+10],vis[N+10],cnt;
vector<int>e[N+10];
queue<int>q;
bool Check(){
    for(int i=1;i<=n;++i)if(!d[i])q.push(i);
    while(!q.empty()){
        u=q.front(),q.pop();
        ++cnt;
        for(int i:e[u])if(!--d[i])q.push(i);
    }
    return cnt<n;
}
void dfs(int x){
    vis[x]=1,tt[x]=fl[x];
    for(int i:e[x]){
        if(!vis[i])dfs(i);
        tt[x]+=tt[i];
    }
}
int main(int argc,char *argv[]){
    freopen(argv[1],"r",stdin);
    freopen(argv[2],"w",stdout);
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        cin>>u>>v;
        if(u!=v)e[u].push_back(v),++d[v];
        else if(fl[u]++)return puts("Yes"),0;
    }
    if(Check())return puts("Yes"),0;
    for(int i=1;i<=n;++i){
        if(!vis[i])dfs(i);
        if(fl[i]&&tt[i]>1)return puts("Yes"),0;
    }
    puts("No");
    return 0;
}