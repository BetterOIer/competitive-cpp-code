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
int n,m;
vector<int>ro[20005];
stack<int>stk;
bool cut[20005];
int dfn[20005],low[20005],tot,root,cutCnt;
void Tarjan(int pos){
    dfn[pos]=low[pos]=++tot;
    stk.push(pos);
    if(pos==root&&!ro[pos].size()){
        return ;
    }
    int child = 0;
    for(int i:ro[pos]){
        if(!dfn[i]){
            Tarjan(i);
            low[pos]=min(low[pos],low[i]);
            if(low[i]>=dfn[pos]){
                child++;
                if(pos!=root||child>1)cutCnt+=(!cut[pos]),cut[pos]=true;
                while(true){
                    int y = stk.top();stk.pop();
                    if(y==i)break;
                }
            }
        }else low[pos]=min(low[pos],dfn[i]);
    }
}
int main(){
    n=read(),m=read();
    for(int i = 1,u,v;i<=m;i++){
        u=read(),v=read();
        ro[u].push_back(v);
        ro[v].push_back(u);
    }
    for(int i = 1;i<=n;i++){
        if(!dfn[i])root=i,Tarjan(i);
    }
    cout<<cutCnt<<endl;
    for(int i = 1;i<=n;i++){
        if(cut[i])cout<<i<<" ";
    }
    return 0;
}