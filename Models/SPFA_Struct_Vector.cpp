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
#include<cstring>
#include<queue>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,s;
struct node{
    int to;
    int val;
};
vector<node>ro[100005];
int dis[100005],cnt[100005];
bool vis[100005];
queue<int>Q;
bool spfa(){
    memset(dis,0x3f3f3f3f,sizeof dis);
    dis[s]=0,vis[s]=true;Q.push(s);
    while(Q.size()){
        int now = Q.front();Q.pop();
        vis[now]=false;
        for(node to:ro[now]){
            if(dis[to.to]>dis[now]+to.val){
                dis[to.to]=dis[now]+to.val;
                cnt[to.to]=cnt[now]+1;
                if(cnt[to.to]>=n)return false;
                if(!vis[to.to])Q.push(to.to),vis[to.to]=true;
            }
        }
    }
    return true;
}
int main(){
    n=read(),m=read(),s=read();
    for(int i = 1,u,v,w;i<=m;i++){
        u=read(),v=read(),w=read();
        ro[u].push_back((node){v,w});
    }
    bool NO_NEGTIVE_CIRCLE = spfa();
    if(NO_NEGTIVE_CIRCLE){
        for(int i = 1;i<=n;i++){
            cout<<dis[i]<<" ";
        }
    }else cout<<-1;
    
    return 0;
}