#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read(){
	int x = 0,f = 1;char c = getchar();
	for(;!isdigit(c);c = getchar())if( c == '-' )f = -1;
	for(;isdigit(c);c = getchar())x = ( x << 1 ) + ( x << 3 ) + c - '0';
	return x * f;
}

const int N = 1e5 + 5;
typedef pair<int,int> pii;

int n,m,q,tot;
int a[N],c[N],f[N][20],maxx[N][20];
int fa[N];
int head[N << 1],cnt;

struct node{
	int u,v,w;
}E[N];
struct edge{
	int to , next;
}e[N << 1];

inline void add(int from,int to){
	e[++ cnt] = (edge){ to , head[from] };
	head[from] = cnt;
}

inline bool cmp(node a,node b){return a.w < b.w;}

inline int find(int x){return fa[x] == x ? fa[x] : find( fa[x] );}

inline void dfs(int x,int father){
	for(int i = head[x];i;i = e[i].next){
		int to = e[i].to;
		dfs( to , x );
		a[x] += a[to];
	}	
	f[x][0] = father;
	maxx[x][0] = c[father] - a[x];
}

inline void build(){
	memset( head , -1 , sizeof( head ) );
	for(int i = 1;i <= n + m;i ++)fa[i] = i;
	tot = n;
	for(int i = 1;i <= m;i ++){
		int fx = find( E[i].u ),fy = find( E[i].v );
		if( fx == fy )continue;
		tot ++;
		add( tot , fx );
		add( tot , fy );
		fa[fx] = fa[fy] = tot;
		c[tot] = E[i].w;
	}
	vector <bool> vis(n + 1 , false);
	for(int i = 1;i <= n;i ++){
		vis[find(i)] = 1;
		dfs( tot , 0 );
		for(int i = 1;i <= 18;i ++)
			for(int j = 1;j <= tot;j ++){
				f[j][i] = f[f[j][i - 1]][i - 1];
				maxx[j][i] = max( maxx[j][i] , maxx[f[j][i - 1]][i - 1] );
			}
	}
}
signed main(){
	n = read(),m = read(),q = read();
	for(int i = 1;i <= n;i ++)a[i] = read();
	for(int i = 1;i <= m;i ++){
		E[i].u = read();
		E[i].v = read();
		E[i].w = read();
	}
	sort( E + 1 , E + m + 1 , cmp );
	build();
	while( q -- ){
		int x = read(),k = read();
		for(int i = 18;i >= 0;i --){
			if( f[x][i] ){
				if( maxx[x][i] <= k )
					x = f[x][i];
			}
		}
		printf("%lld\n",k + a[x]);
	}
	return 0;
}