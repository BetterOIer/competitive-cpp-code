/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<stack>
#include<vector>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,idx=1,tot,cnt;
struct EDGE{
    int v;
    int ne;
}edge[4000005];
int h[500005],dfn[4000005],low[4000005],bri[4000005];
vector<int>dcc[500005];
stack<int>stk;
void add(int a,int b){
    edge[++idx].v = b;
    edge[idx].ne = h[a];
    h[a]=idx;
}
void Tarjan(int pos,int in_edge){
    dfn[pos] = low[pos] = ++tot;
    stk.push(pos);
    for(int i = h[pos];i;i = edge[i].ne){
        int to = edge[i].v;
        if(!dfn[to]){
            Tarjan(to,i);
            low[pos] = min(low[pos],low[to]);
            if(low[to]>dfn[pos]) bri[i] = bri[i^1] = true;
        }else if(i != (in_edge^1))low[pos] = min(low[pos],dfn[to]);
    }
    if(dfn[pos]==low[pos]){
        ++cnt;
        while(true){
            int y = stk.top();stk.pop();
            dcc[cnt].push_back(y);
            if(y==pos)break;
        }
    }
}
int main(){
    n=read(),m=read();
    for(int i = 1,u,v;i<=m;i++){
        u=read(),v=read();
        add(u,v);add(v,u);
    }
    for(int i = 1;i<=n;i++)
        Tarjan(i,0);
    cout<<cnt<<endl;
    for(int i = 1;i<=cnt;i++){
        cout<<dcc[i].size();
        for(int node:dcc[i]){
            cout<<" "<<node;
        }
        cout<<endl;
    }
    return 0;
}