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
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
struct node{
    int to;
    int a;
    int b;
};
vector<node>ro[25];
deque<int>stk;
int dfn[25],low[25],tot=0,cnt=0;
bool instack[25];
void Tarjan(int pos){
    //入
    dfn[pos]=low[pos]=++tot;
    stk.push_front(pos);
    instack[pos]=true;
    //回
    for(node to:ro[pos]){
        if(!dfn[to.to]){
            Tarjan(to.to);
            low[pos]=min(low[pos],low[to.to]);
        }else if(instack[to.to]){
            low[pos]=min(low[pos],dfn[to.to]);
        }
    }
    //离
    if(dfn[pos]==low[pos]){
        int y;++cnt;
        do{
            y=stk.front();stk.pop_front();
            instack[y]=false;
        }while(y!=pos);
    }
}
int main(){
    int n=read(),m=read();
    for(int i = 1,u,v,a,b;i<=m;i++){
        u=read(),v=read(),a=read(),b=read();
        ro[u].emplace_back((node){v,a,b});
        ro[v].emplace_back((node){u,a,b});
    }
    Tarjan(1);
    
    return 0;
}