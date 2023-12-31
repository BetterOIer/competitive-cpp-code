#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
#define release
using namespace std;
const long long inf = 3223372036854775807;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,m,tot=0;
long long nex[2000005],head[2000005],ver[2000005],edge[2000005];
long long dis[1000005],dis1[1000005];
bool vis[1000005];
struct node{
    long long po;
    long long val;
    bool operator < (const node &w)const{
        return w.val<val;
    }
};
priority_queue<node>Q;
void add(long long x, long long y, long long z){ver[++tot] = y, edge[tot] = z, nex[tot] = head[x], head[x] = tot;}
void dijkstra(long long s){
    for(long long i = 0;i<=n*2;i++){
        dis[i]=inf;
    }
    memset(vis, 0, sizeof vis);
    dis[s]=0;
    Q.push((node){s,0});
    while(Q.size()){
        node now=Q.top();Q.pop();
        if(vis[now.po])continue;
        vis[now.po]=true;
        for(long long i = head[now.po];i;i=nex[i]){
            long long y=ver[i],z=edge[i];
            if(dis[y]>dis[now.po]+z){
                dis[y]=dis[now.po]+z;
                Q.push((node){y,dis[y]});
            }
        }
    }
}
int main(){
    #ifdef release
    freopen("coin.in","r",stdin);
    freopen("coin.out","w",stdout);
    #endif
    n=read(),m=read();
    for(long long i = 1,u,v,w;i<=m;i++){
        u=read(),v=read(),w=read();
        add(u,v,w);add(v+n,u+n,w);
    }
    for(int i = 1;i<=n;i++)add(i,i+n,0);
    dijkstra(1);
    for(long long i = 2;i<=n;i++){
        cout<<(dis[i+n]==inf? -1:dis[i+n])<<" ";
    }
    return 0;
}