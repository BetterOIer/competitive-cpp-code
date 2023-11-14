/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:10
* FileStation: https://betteroier.site:15
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,dep[100005],deepest;
struct node{
    int to;
    int val;    
};
vector<node>ro[100005];
void dfs(int pos,int fa,int len){
    dep[pos]=dep[fa]+len;
    if(dep[pos]>dep[deepest])deepest=pos;
    for(node i:ro[pos]){
        if(i.to==fa)continue;
        dfs(i.to,pos,i.val);
    }
}
int main(){
    n=read();
    for(int i = 1,u,v,w;i<n;i++){
        u=read(),v=read(),w=read();
        ro[u].push_back((node){v,w});
        ro[v].push_back((node){u,w});
    }
    dfs(1,0,0);
    dfs(deepest,0,0);
    cout<<dep[deepest] * (dep[deepest] + 21) / 2;
}