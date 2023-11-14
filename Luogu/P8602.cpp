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
int n,dep[10005]={-1},deepest;
vector<int>ro[10005];
void dfs(int pos,int fa){
    dep[pos]=dep[fa]+1;
    if(dep[pos]>dep[deepest])deepest=pos;
    for(int i:ro[pos]){
        if(i==fa)continue;
        dfs(i,pos);
    }
}
int main(){
    n=read();
    for(int i = 1,u,v;i<n;i++)u=read(),v=read(),ro[u].push_back(v),ro[v].push_back(u);
    dfs(1,0),dfs(deepest,0);
    cout<<dep[deepest]*(dep[deepest]+21)/2;
    return 0;
}