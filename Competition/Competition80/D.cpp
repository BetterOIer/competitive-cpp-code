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
#include<stack>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
struct node{
    int to;
    int a;
    int b;
};
vector<node>ro[25];
vector<int>dcc[25];
stack<int>stk;
int dfn[25],low[25],cut[25],tot=0,cnt=0,root;
bool instack[25];
inline void Tarjan(int pos){
	dfn[pos]=low[pos]=++tot;
    stk.push(pos);
    if(!ro[pos].size()){
        dcc[++cnt].push_back(pos);
        return;
    }
    int child = 0;
    for(node to:ro[pos]){
        if(!dfn[to.to]){
            Tarjan(to.to);
            low[pos]=min(low[pos],low[to.to]);
            if(low[to.to]>=low[pos]){
                child++;
                if(pos!=root||child>1)cut[pos]=true;
                cnt++;
                while(true){
                    int z = stk.top();stk.pop();
                    dcc[cnt].push_back(z);
                    if(z==to.to)break;
                }
                dcc[cnt].push_back(pos);
            }
        }else low[pos]=min(low[pos],dfn[to.to]);
    }
}
int main(){
    int n=read(),m=read();
    for(int i = 1,u,v,a,b;i<=m;i++){
        u=read(),v=read(),a=read(),b=read();
        ro[u].emplace_back((node){v,a,b});
        ro[v].emplace_back((node){u,a,b});
    }
    for (root=1;root<=n;root++) if (!dfn[root]) Tarjan(root);
    n = 0;
    return 0;
}