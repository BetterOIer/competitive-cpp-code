#include<bits/stdc++.h>
#include<algorithm>
using namespace std;
#define dy ios::sync_with_stdio(false),cin.tie(),cout.tie();
#define int long long
#define re register
#define For(i,l,r) for(re int i=l;i<=r;i++)
#define Rep(i,l,r) for(re int i=l;i>=r;i--)
const int N=3e4+5;
#define ls(c) c<<1
#define rs(c) c<<1|1
inline void read(int &x){
	   x=0;int f=1;
	   char c=getchar();
	   while(!isdigit(c)){
			if(c=='-') f=-1;
			c=getchar();
	   }while(isdigit(c)){
			x=x*10+c-'0';
			c=getchar();
	   }x*=f;
}
inline void write(int x){
	   if(x<0){x=-x;putchar('-');}
	   if(x>9) write(x/10);
	   putchar(x%10+'0');
}
int n,m,rt,p;
int w[N],nw[N],id[N],cnt,dep[N],sz[N];
int top[N],fa[N],son[N];
struct node{
	int l,r;
	long long sum,Max;
}t[N<<2];
vector<int> edge[N];
inline void dfs1(int u,int faz){
	dep[u]=dep[faz]+1;
	fa[u]=faz;
	sz[u]=1;
	for(auto v:edge[u]){
		if(v==faz) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v;
	}
}
inline void dfs2(int u,int head){
	id[u]=++cnt;
	nw[cnt]=w[u];
	top[u]=head;
	if(son[u]) dfs2(son[u],head);
	for(auto v:edge[u]){
		if(v==son[u]||v==fa[u]) continue;
		dfs2(v,v);
	}
}
inline void pushup(int c){
	t[c].sum=t[ls(c)].sum+t[rs(c)].sum;
	t[c].Max=max(t[ls(c)].Max,t[rs(c)].Max); /////there!!!!!!!!!!
}
inline void build(int c,int l,int r){
	t[c].l=l;t[c].r=r;
	if(l==r){
		// cin>>t[c].sum;
		t[c].sum=nw[l];
		t[c].Max=t[c].sum;
		return;
	}
	int mid=(l+r)>>1;
	build(c<<1,l,mid);build(c<<1|1,mid+1,r);
	pushup(c);
}
inline void update(int c,int l,int r,int k){
	if(l<=t[c].l&&r>=t[c].r){
		t[c].Max=t[c].sum=k;
		return;
	}
	int mid=(t[c].l+t[c].r)>>1;
	if(l<=mid) update(c<<1,l,r,k);
	if(r>mid) update(c<<1|1,l,r,k);
	pushup(c);
}
long long query_max(int c,int l,int r){
	if(l<=t[c].l&&r>=t[c].r) return t[c].Max;
	int mid=(t[c].l+t[c].r)>>1;
	long long ans=-1e9;
	if(l<=mid) ans=max(ans,query_max(c<<1,l,r));
	if(r>mid) ans=max(ans,query_max(c<<1|1,l,r));
	return ans;
}
long long query_sum(int c,int l,int r){
	if(l<=t[c].l&&r>=t[c].r) return t[c].sum;
	int mid=(t[c].l+t[c].r)>>1;
	long long ans=0;
	if(l<=mid) ans+=query_sum(c<<1,l,r);
	if(r>mid) ans+=query_sum(c<<1|1,l,r);
	return ans;
}
long long query_sum_path(int u,int v){
	long long ans=0;
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		ans=ans+query_sum(1,id[top[u]],id[u]);
		u=fa[top[u]];
	}
	if(dep[u]<dep[v]) swap(u,v);
	ans=ans+query_sum(1,id[v],id[u]);
	return ans;
}
long long query_max_path(int u,int v){
	long long ans=-1e9;
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		ans=max(ans,query_max(1,id[top[u]],id[u]));
		// cout<<query_max(1,id[top[u]],id[u])<<'\n';
		u=fa[top[u]];
	}
	if(dep[u]<dep[v]) swap(u,v);
	ans=max(ans,query_max(1,id[v],id[u]));
	// cout<<u<<' '<<v<<'\n';
	// cout<<query_max(1,id[v],id[u])<<'\n';
	return ans;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n;
	rt=1;
	for(register int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
		edge[x].push_back(y);
		edge[y].push_back(x);
	}
	for(register int i=1;i<=n;i++) cin>>w[i];
	// dep[1]=1;fa[1]=1;
	dfs1(rt,0); /////there!!!!!!!!!!
	dfs2(rt,rt);
	build(1,1,n);
	cin>>m;
	while(m--){
		string op;
		int u,v,t;
		cin>>op;
		if(op=="CHANGE"){
			cin>>u>>t;
			update(1,id[u],id[u],t);
		}else if(op=="QMAX"){
			cin>>u>>v;
			cout<<query_max_path(u,v)<<'\n';
		}else{
			cin>>u>>v;
			cout<<query_sum_path(u,v)<<'\n';
		}
	}
	return 0;
}