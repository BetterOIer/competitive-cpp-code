#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x; i<=y; ++i)
#define repd(i,x,y) for(int i=x; i>=y; --i)

using namespace std;
typedef long long LL;
const int N=200005;
int n,m,q,cnt,h[N],fa[N],f[20][N],x,tot;
struct edge{int v,n;} e[N];
LL a[N],mx[20][N],k,c[N];
struct D{int u,v,w;} dat[N];

int getint(){
	char ch;
	int f=1;
	while(!isdigit(ch=getchar())) if(ch=='-') f=-1;
	int x=ch-48;
	while(isdigit(ch=getchar())) x=x*10+ch-48;
	return x*f;
}

void addedge(int u,int v){
    
	e[cnt]=(edge){v,h[u]},h[u]=cnt++;
}

int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}

void dfs(int x,int fa=0){
	for(int i=h[x]; i!=-1; i=e[i].n){
		dfs(e[i].v,x);
		a[x]+=a[e[i].v];
	}
	f[0][x]=fa;
	mx[0][x]=c[fa]-a[x];
}	

void build(){
	memset(h,-1,sizeof(h));
	rep(i,1,n+m) fa[i]=i;
	tot=n;
	rep(i,1,m)
	{
		int u=getfa(dat[i].u),v=getfa(dat[i].v);
		if(u==v) continue;
		++tot,addedge(tot,u),addedge(tot,v);
		fa[u]=fa[v]=tot,c[tot]=dat[i].w;
	}
  vector <bool> vis(n + 1, false);
  for (int i = 1; i <= n; i++)
    if (vis[getfa(i)]) ;
    else vis[getfa(i)] = true;
	dfs(tot);
	rep(i,1,18) rep(j,1,tot) f[i][j]=f[i-1][f[i-1][j]],mx[i][j]=max(mx[i-1][j],mx[i-1][f[i-1][j]]);
}	

bool cmp(D a,D b){
	return a.w<b.w;
}

int main(){
    #ifndef LOCAL
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    #else
    freopen("ex_travel3.in","r",stdin);
    freopen("ex_travel3.res","w",stdout);
    #endif
	n=getint(),m=getint(),q=getint();
	rep(i,1,n) a[i]=getint();
	rep(i,1,m) dat[i].u=getint(),dat[i].v=getint(),dat[i].w=getint();
	sort(dat+1,dat+1+m,cmp);
	build();
	while(q--){
		x=getint(),k=getint();
		repd(i,18,0) if(f[i][x])
			if(mx[i][x]<=k) x=f[i][x];
		printf("%lld\n",k+a[x]);
	}
	return 0;
}
