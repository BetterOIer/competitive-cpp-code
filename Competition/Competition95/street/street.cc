#include<iostream>
#include<vector>
using namespace std;
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
vector<int>e[100005];
int n,q,siz[100005],son[100005][31],dep[100005],fa[100005],mxdep[100005];
int L[100005],R[100005],tot;
long long d[100005][31],t[100005];
void dfs(int u,int f){
	dep[u]=dep[f]+1,siz[u]=son[u][0]=1,fa[u]=f,mxdep[u]=0;
	L[u]=++tot;
	for(auto v:e[u]){
		if(v==f) continue;
		dfs(v,u);
		siz[u]+=siz[v];
		for(int j=1; j<=30; j++) son[u][j]+=son[v][j-1];
		mxdep[u]=max(mxdep[u],mxdep[v]+1);
	}
	R[u]=tot;
}
void update(int x,long long w){
    while(x<=n) t[x]+=w,x+=(x&-x);
}
long long query(int x){
	long long res=0;
    while(x) res+=t[x],x -= (x & -x);
	return res;
}
void cal(int u,int w,int p){
	long long sum=0;
	for(int j=0; j<=mxdep[u]; j++){
		d[u][j]+=w;
		sum+=1ll*w*son[u][j];
		w/=p;
		if(!w) break;
	}
	update(L[u],sum);
} 
int main(){
	freopen("street.in","r",stdin);
    freopen("street.out","w",stdout);
    n=read(),q=read();
	for(int i=1; i<n; i++){
        int u=read(),v=read();
		e[u].push_back(v),e[v].push_back(u);
	}
	dfs(1,0);
	long long tg=0;
	while(q--){
		int op=read();
		if(op==1){
			int u=read(),w=read(),p=read();
			if(p==1){tg+=w; continue;}
			cal(u,w,p);
			int st=w;
			for(int v=u; v != 1; v=fa[v]){
				st/=p;
				if(!st) break;
				cal(fa[v],st,p),cal(v,-st / p,p);
			}
		} 
        else{
			int u=read(),v=read(),dept=1;
			bool flag=false;
			if(dep[u]<dep[v]) swap(u,v),flag=true;
			long long ansu=tg*siz[u]+query(R[u])-query(L[u]-1);
			for(int now=fa[u]; now; now=fa[now]){
				if(dept>30) break;
				for(int j=0; j<=mxdep[u] && j+dept<=30; j++) 
					ansu+=d[now][j+dept]*son[u][j];
				dept++;
			}
			long long ans=tg*siz[1]+query(n);
			if(!flag) printf("%lld %lld\n",ansu,ans-ansu);
			else printf("%lld %lld\n",ans-ansu,ansu);
		}
	}
	return 0;
}