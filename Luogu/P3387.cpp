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
#include<queue>
#include<stack>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m;
vector<int>ro[10005],roScc[10005],fan[10005];
struct EDGE{int a,b;};
vector<EDGE>edge;
stack<int>stk;
bool instk[10005];
int dfn[10005],low[10005],tot,in[10005];
int scc[10005],cnt=0,bel[10005];
int ans[10005],val[10005],cct,dp[10005];
void Tarjan(int pos,int fa){
    dfn[pos]=low[pos]=++tot;
    stk.push(pos);instk[pos]=true;
    for(int i:ro[pos]){
        if(!dfn[i])Tarjan(i,pos),low[pos]=min(low[pos],low[i]);
        else if(instk[i])low[pos]=min(low[pos],dfn[i]);
    }
    if(low[pos]==dfn[pos]){
        int y;++cnt;
        do{
            y=stk.top();stk.pop();instk[y]=false;
            scc[cnt]+=val[y];bel[y]=cnt;
        }while(y!=pos);
    }
}
void topu(){
    queue<int>Q;
    for(int i = 1;i<=cnt;i++){
        if(!in[i])Q.push(i);
    }
    while(Q.size()){
        int now = Q.front();Q.pop();ans[++cct]=now;
        for(int i:roScc[now]){
            in[i]--;
            if(!in[i])Q.push(i);
        }
    }
}
int main(){
    n=read(),m=read();
    for(int i = 1;i<=n;i++)val[i]=read();
    for(int i = 1,u,v;i<=m;i++){
        u=read(),v=read();
        ro[u].push_back(v);
        edge.push_back((EDGE){u,v});
    }
    for(int i = 1;i<=n;i++){
        if(!dfn[i])Tarjan(i,0);
    }
    for(EDGE i:edge){
        if(bel[i.a]!=bel[i.b]){
            roScc[bel[i.a]].push_back(bel[i.b]);fan[bel[i.b]].push_back(bel[i.a]);
            in[bel[i.b]]++;
        }
    }
    topu();
    for(int i = 1;i<=cct;i++){
        int w = ans[i];
        dp[w] = scc[w];
        for(int i:fan[w]){
            dp[w]=max(dp[w],dp[i]+scc[w]);
        }
    }
    int anss=0;
    for(int i = 1;i<=cct;i++)anss=max(anss,dp[i]);
    cout<<anss;
    return 0;
}