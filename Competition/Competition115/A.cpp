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
int n;
vector<int>ro[1000005];
int dep[1000005],siz[1000005];
int dfs(int pos,int fat){
    dep[pos]=dep[fat]+1;
    siz[pos]=1;
    for(int i:ro[pos]){
        if(i==fat)continue;
        siz[pos]+=dfs(i,pos);
    }
    return siz[pos];
}
int main(){
    int t=read();
    while(t--){
        n=read();
        for(int i = 1;i<=n;i++)ro[i].clear();
        for(int i = 1,u,v;i<n;i++){
            u=read(),v=read();
            ro[u].push_back(v);
            ro[v].push_back(u);
        }
        dfs(1,0);
        for(int i = 1;i<=n;i++){
            printf("%d %d\n",dep[i],n-siz[i]+1);
        }
    }    
    return 0;
}