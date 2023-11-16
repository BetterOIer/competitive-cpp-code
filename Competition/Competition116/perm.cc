#include<bits/stdc++.h>
using namespace std;
const int maxn=300100;
struct Segment_tree
{
	#define ls (p<<1)
	#define rs (p<<1|1)
	int mxv[maxn<<2],addv[maxn<<2];
	inline void pushup(int p){mxv[p]=max(mxv[ls],mxv[rs]);}
	inline void setadd(int p,int v){addv[p]+=v;mxv[p]+=v;}
	inline void pushdown(int p){if(addv[p]) setadd(ls,addv[p]),setadd(rs,addv[p]),addv[p]=0;}
	inline void Add(int p,int l,int r,int ql,int qr,int v)
	{
		if(ql<=l&&qr>=r) return (void)setadd(p,v);
		int mid=(l+r)>>1;pushdown(p);
		if(ql<=mid) Add(ls,l,mid,ql,qr,v);
		if(qr>mid) Add(rs,mid+1,r,ql,qr,v);
		pushup(p);
	}
}seg;
int now,n,a[maxn],b[maxn],pos[maxn];
inline int chk(int x){return seg.mxv[1]>0;}
int main()
{
	freopen("perm.in","r",stdin);
	freopen("perm.out","w",stdout);
	scanf("%d",&n);now=n;
	for(int i=1;i<=n;i++) scanf("%d",a+i),pos[a[i]]=i;
	for(int i=1;i<=n;i++) scanf("%d",b+i);
	printf("%d ",now);seg.Add(1,1,n,1,pos[n],1);
	for(int i=1;i<n;i++)
	{
		seg.Add(1,1,n,1,b[i],-1);
		while(!chk(now)) now--,seg.Add(1,1,n,1,pos[now],1);
		printf("%d%c",now,i==n-1?'\n':' ');
	}
	return 0;
}
