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
vector<int>ro[2000005];
vector<int>dcc[2000005];
stack<int>stk;
int dfn[2000005],low[2000005],cut[2000005],tot=0,cnt=0,root;
bool instack[2000005];
inline void Tarjan(int pos){
	dfn[pos]=low[pos]=++tot;
    stk.push(pos);
    if(!ro[pos].size()){
        dcc[++cnt].push_back(pos);
        return;
    }
    int child = 0;
    for(int to:ro[pos]){
        if(!dfn[to]){
            Tarjan(to);
            low[pos]=min(low[pos],low[to]);
            if(low[to]>=dfn[pos]){
                child++;
                if(pos!=root||child>1)cut[pos]=true;
                cnt++;
                while(true){
                    int z = stk.top();stk.pop();
                    dcc[cnt].push_back(z);
                    if(z==to)break;
                }
                dcc[cnt].push_back(pos);
            }
        }else low[pos]=min(low[pos],dfn[to]);
    }
}
int main(){
    int n=read(),m=read();
    for(int i = 1,u,v;i<=m;i++){
        u=read(),v=read();
        ro[u].emplace_back(v);
        ro[v].emplace_back(u);
    }
    for (root=1;root<=n;root++) if (!dfn[root]) Tarjan(root);
    cout<<cnt<<endl;
    for(int i = 1;i<=cnt;i++){
        cout<<dcc[i].size();
        for(int whi:dcc[i]){
            cout<<" "<<whi;
        }
        cout<<endl;
    }
    return 0;
}