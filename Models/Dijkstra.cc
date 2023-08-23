#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int n,m,tot=0;
int nex[3005],head[3005],ver[3005],edge[3005];
int dis[3005];
bool vis[3005];
struct node{
    int po;
    int val;
    bool operator < (const node &w)const{
        return w.val<val;
    }
};
priority_queue<node>Q;
void add(int x, int y, int z){ver[++tot] = y, edge[tot] = z, nex[tot] = head[x], head[x] = tot;}
void dijkstra(){
    memset(dis,0x3f3f3f3f,sizeof dis);
    memset(vis, 0, sizeof vis);
    dis[1]=0;
    Q.push((node){1,0});
    while(Q.size()){
        node now=Q.top();Q.pop();
        if(vis[now.po])continue;
        vis[now.po]=true;
        for(int i = head[now.po];i;i=nex[i]){
            int y=ver[i],z=edge[i];
            if(dis[y]>dis[now.po]+z){
                dis[y]=dis[now.po]+z;
                Q.push((node){y,dis[y]});
            }
        }
    }
}
int main(){
    n=read(),m=read();
    for(int i = 1,u,v,w;i<=m;i++){
        u=read(),v=read(),w=read();
        add(u,v,w),add(v,u,w);
    }
    dijkstra();
    for(int i = 1;i<=n;i++){
        cout<<dis[i]<<endl;
    }
}