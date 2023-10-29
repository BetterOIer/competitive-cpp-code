#include<iostream>
#include<vector>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
vector<int>ro[100005];
int L[100010],R[100010],id[100005],rt[100010],cs;
int T[600][100010],v[100010][600],n,brick,m,cnt,tot;
int ans;
struct point{
	int g[2],w;
	int &operator [](const int &x){return g[x];}
	int &operator !(){return w;}
}t[4000010];
void adt(int &p,int l,int r,int k){
	t[++tot]=t[p],p=tot;(!t[p])++;if(l==r)return;
	if(k<=((l+r)>>1))adt(t[p][0],l,(l+r)>>1,k);
	else adt(t[p][1],((l+r)>>1)+1,r,k);
}
int qry(int p,int l,int r,int i,int j){
	if(!p)return 0;
    if(i<=l&&r<=j)return !t[p];
    int ret=0;
	if(i<=((l+r)>>1))ret+=qry(t[p][0],l,(l+r)>>1,i,j);
	if(j>((l+r)>>1))ret+=qry(t[p][1],((l+r)>>1)+1,r,i,j);
	return ret;
}
void dfs(int pos,int fa){
	for(int i:ro[pos]){
		if(i==fa)continue;
		dfs(i,pos);
		for(int k=1;k<=cs;k++)T[k][pos]+=T[k][i];
	}
	T[id[pos]][pos]++;
}
void cfs(int pos,int fa){
	adt(rt[pos],1,n,pos);
	for(int i:ro[pos]){
		if(i==fa)continue;
        rt[i]=rt[pos],cfs(i,pos);
    }
}
int main(){
    #ifndef LOCAL
    freopen("easy.in","r",stdin);
    freopen("easy.out","w",stdout);
    #else
    /* freopen("ex_tree3.in","r",stdin);
    freopen("ex_tree3.out","w",stdout); */
    #endif
    n=read(),brick = n/400+1;
    for(int i = 2,a;i<=n;i++){
        a=read();
        ro[i].push_back(a);
        ro[a].push_back(i);
    }
    for(int i=1;i<=n;i++)id[i]=(i-1)/brick+1,L[i]=1e9;
    cs=id[n];
	for(int i=1;i<=n;i++)L[id[i]]=min(L[id[i]],i),R[id[i]]=max(R[id[i]],i);
    dfs(1,0),cfs(1,0);
    for(int i=1;i<=cs;i++)for(int j=1;j<=n;j++)T[i][j]+=T[i][j-1];
	m=read();
	for(int i=1,l,r;i<=m;i++){
		l=read(),r=read();
		l=(l^ans)%n+1,r=(r^ans)%n+1;
		if(l>r)swap(l,r);
        ans=0;
		if(id[l]!=id[r]){
			if(l-L[id[l]]>R[id[l]]-l)for(int i=l;i<=R[id[l]];i++)ans+=qry(rt[i],1,n,l,r);
			else{ans+=T[id[l]][r]-T[id[l]][l-1];for(int i=l-1;i>=L[id[l]];i--)ans-=qry(rt[i],1,n,l,r);}
			if(r-L[id[r]]<R[id[r]]-r)for(int i=r;i>=L[id[r]];i--)ans+=qry(rt[i],1,n,l,r);
			else{ans+=T[id[r]][r]-T[id[r]][l-1];for(int i=r+1;i<=R[id[r]];i++)ans-=qry(rt[i],1,n,l,r);}
			for(int i=id[l]+1;i<=id[r]-1;i++)ans+=T[i][r]-T[i][l-1];
		}else for(int i=l;i<=r;i++)ans+=qry(rt[i],1,n,l,r);
		printf("%d\n",ans);
	}
    return 0;
}
