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
int head[3030],nex[3030],ver[3030],edge[3030];
int dis[3030];
bool vis[3030];
queue<int>Q;
void add(int x,int y,int z){
    ver[++tot] = y, edge[tot] = z, nex[tot] = head[x], head[x] = tot;
}
void SPFA(){
    memset(dis, 0x3f3f3f3f, sizeof dis);
    memset(vis, false, sizeof vis);
    dis[1]=0;vis[1]=1;
    Q.push(1);
    while(Q.size()){
        int now=Q.front();Q.pop();
        vis[now]=0;
        for(int i = head[now];i;i=nex[i]){
            int y=ver[i],z=edge[i];
            if(dis[y]>dis[now]+z){
                dis[y]=dis[now]+z;
                if(!vis[y])Q.push(y),vis[y]=true;
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
    SPFA();
    for(int i = 1;i<=n;i++){
        cout<<dis[i]<<endl;
    }
}