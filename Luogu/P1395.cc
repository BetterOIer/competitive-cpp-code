// By YoungNeal
#include<cstdio>
#define N 50005

int d[N];
int f[N];
int n,cnt;
int size[N];
bool vis[N];
int head[N];

struct Edge{
    int to,nxt;
}edge[N<<1];

void add(int x,int y){
    edge[++cnt].to=y;
    edge[cnt].nxt=head[x];
    head[x]=cnt;
}

void dfs1(int now){
    size[now]=1;
    for(int i=head[now];i;i=edge[i].nxt){
        int to=edge[i].to;
        if(d[to]) continue;
        d[to]=d[now]+1;
        dfs1(to);
        size[now]+=size[to];
    }
}

void dfs(int now,int fa){
    f[now]=f[fa]+n-2*size[now];
    for(int i=head[now];i;i=edge[i].nxt){
        int to=edge[i].to;
        if(to==fa) continue;
        dfs(to,now);
    }
}

signed main(){
    freopen("test.in","r",stdin);
    freopen("test.ans","w",stdout);
    scanf("%d",&n);
    for(int x,y,i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        add(x,y);add(y,x);
    }
    d[1]=1;
    dfs1(1);
    int maxn=0,idx=1;
    for(int i=1;i<=n;i++) maxn+=d[i];
    maxn-=n;
    f[1]=maxn;
    for(int i=head[1];i;i=edge[i].nxt){
        int to=edge[i].to;
        dfs(to,1);
    }
    for(int i=2;i<=n;i++){
        if(f[i]<maxn) maxn=f[i],idx=i;
    }
    printf("%d %d",idx,maxn);
    return 0;
}