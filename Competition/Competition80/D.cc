/* #include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=4e5+5;
int n,m,x,y,a[N],b[N],tim,dfn[N],fa[N],fe[N],id[N],top,cnt,on[N];
ll mn;
vector<pair<int,int> >v[N];
struct P{
	int x,y;
	P operator+(P a){return {x+a.x,y+a.y};}
	P operator-(P a){return {x-a.x,y-a.y};}
	ll operator*(P a){return 1ll*x*a.y-1ll*y*a.x;} 
	bool dir(){return x>0||(!x&&y>0);}
}c[N],s[N],cur,d[N];
void Dconv(int &n,P *a){
	sort(a+1,a+1+n,[](P x,P y){return x.x^y.x?x.x<y.x:x.y<y.y;}),top=0; 
	for(int i=1;i<=n;i++){
		while(top>1&&(a[i]-s[top-1])*(s[top]-s[top-1])>=0) top--;
		s[++top]=a[i];
	}
	n=top;
}
void dfs(int x){
	dfn[x]=++tim;
	for(auto p:v[x]){
		int y=p.first,e=p.second;
		if(y==fa[x]) continue;
		if(!dfn[y]) fa[y]=x,fe[y]=e,dfs(y);
		else if(dfn[y]<dfn[x]){
			int t=0,sa=0,sb=0;
			for(int u=x;u!=y;u=fa[u]) id[++t]=fe[u];
			id[++t]=e;
			for(int i=1;i<=t;i++)
				sa+=a[id[i]],sb+=b[id[i]],on[id[i]]=1;
			for(int i=1;i<=t;i++) c[i]={sa-a[id[i]],sb-b[id[i]]};
			Dconv(t,c);
			cur=cur+s[1];
			for(int i=2;i<=t;i++) d[++cnt]=s[i]-s[i-1];
		}
	}
}
signed main(){
    freopen("17.in","r",stdin);
    freopen("17.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++)
		scanf("%d%d%d%d",&x,&y,&a[i],&b[i]),
		v[x].push_back({y,i}),v[y].push_back({x,i});
	dfs(1);
	for(int i=1;i<=m;i++)
		if(!on[i]) cur=cur+(P){a[i],b[i]};
	sort(d+1,d+1+cnt,[](P x,P y){return x.dir()^y.dir()?x.dir():x*y>0;});
	mn=1ll*cur.x*cur.y;
	for(int i=1;i<=cnt;i++)
		cur=cur+d[i],mn=min(mn,1ll*cur.x*cur.y);
	printf("%lld\n",mn);
	return 0;
}
 */
/* #include<bits/stdc++.h>
#define IL inline
#define reg register
#define N 300300
#define int long long
IL int read()
{
    reg int x=0; reg char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
    return x;
}

int n,m,first[N],nxt[N+N],to[N+N],wa[N+N],wb[N+N],num=1;

IL void add(reg int u,reg int v,reg int a,reg int b){nxt[++num]=first[u],to[first[u]=num]=v,wa[num]=a,wb[num]=b;}
IL void adde(reg int u,reg int v,reg int a,reg int b){add(u,v,a,b),add(v,u,a,b);}

int len,top;

struct Point
{
    int x,y;
    IL Point operator +(const Point &p){return {x+p.x,y+p.y};}
    IL Point operator -(const Point &p){return {x-p.x,y-p.y};}
    IL int det(reg Point p){return x*p.y-y*p.x;}
    IL int mo(){return x*x+y*y;}
}p[N],s[N],t[N];

IL void Andrew()
{
    top=0;
    std::sort(p+1,p+1+len,[&](reg Point a,reg Point b){return a.x<b.x||a.x==b.x&&a.y<b.y;});
    for(reg int i=1;i<=len;++i)
    {
        while(top>1&&(p[i]-s[top-1]).det(s[top]-s[top-1])>=0)--top;
        s[++top]=p[i];
    }
}

int dfn[N],dfc,fa[N];
std::vector<int>now;
int A,B,ans;
bool vis[N+N];

IL void apply()
{
    reg int sa=0,sb=0;
    for(reg auto e:now)sa+=wa[e],sb+=wb[e],vis[e]=vis[e^1]=1;
    len=0;
    for(reg auto e:now)p[++len]={sa-wa[e],sb-wb[e]};
    Andrew(),A+=s[1].x,B+=s[1].y;
    for(reg int i=2;i<=top;++i)t[++m]=s[i]-s[i-1];
}

void dfs(reg int u)
{
    dfn[u]=++dfc;
    for(reg int i=first[u],v,x;i;i=nxt[i])if(i!=fa[u])
    {
        if(!dfn[v=to[i]])fa[v]=i^1,dfs(v);
        if(dfn[v]>dfn[u])continue;
        now.clear(),now.push_back(i);
        for(x=u;x!=v;x=to[fa[x]])now.push_back(fa[x]);
        apply();
    }
}

IL void cmin(reg int &x,reg int y){x>y?x=y:0;}

main()
{
    freopen("17.in","r",stdin);
    freopen("17.out","w",stdout);
    n=read(),m=read();
    for(reg int u,v,a,b;m--;)u=read(),v=read(),a=read(),b=read(),adde(u,v,a,b);
    m=0,dfs(1),std::sort(t+1,t+1+m,[&](reg Point a,reg Point b){return a.det(b)>0;});
    for(reg int i=2;i<=num;i+=2)if(!vis[i])A+=wa[i],B+=wb[i];
    ans=A*B;
    for(reg int i=1;i<=m;++i)A+=t[i].x,B+=t[i].y,cmin(ans,A*B);
    printf("%lld\n",ans);
} */

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll inf=0x3f3f3f3f3f3f3f3f;
#define x first
#define y second

int h[200005],e[600005],ne[600005],idx;

ll A[600005],B[600005];

void add(int a,int b,ll x,ll y) {
	e[idx]=b;
	A[idx]=x,B[idx]=y;
	ne[idx]=h[a];
	h[a]=idx++;
}

int n,m;

ll a[200005],b[200005];

int dfn[200005],timestamp;

int fa[200005];

vector<pair<ll,ll> > C;

vector<pair<ll,ll> > tmp;

inline pair<ll,ll> operator+(const pair<ll,ll> &a,const pair<ll,ll> &b) {
	return make_pair(a.x+b.x,a.y+b.y);
}

inline pair<ll,ll> operator-(const pair<ll,ll> &a,const pair<ll,ll> &b) {
	return make_pair(a.x-b.x,a.y-b.y);
}

ll cross(const pair<ll,ll> &a,const pair<ll,ll> &b) {
	return a.x*b.y-a.y*b.x;
}

int stk[600005],tail;

void Hull(vector<pair<ll,ll> > &C) {
	sort(C.begin(),C.end());
	C.erase(unique(C.begin(),C.end()),C.end());
	tail=0;
	for(int i=0;i<C.size();i++) {
		while(tail>=2 && cross(C[i]-C[stk[tail-1]],C[stk[tail]]-C[stk[tail-1]])>=0) {
			tail--;
		}
		stk[++tail]=i;
	}
	tmp.clear();
	for(int i=1;i<=tail;i++) {
		tmp.push_back(C[stk[i]]);
	}
	C=tmp;
}

vector<pair<ll,ll> > res;

inline void solve() {
	Hull(C);
	res[0]=res[0]+C[0];
	for(int j=1;j<C.size();j++) {
		res.push_back(C[j]-C[j-1]);
	}
	C.clear();
}

bool vis[600005];

void Tarjan(int u) {
	dfn[u]=++timestamp;
	for(int i=h[u];i!=-1;i=ne[i]) {
		int v=e[i];
		if((i^1)==fa[u]) {
			continue;
		}
		if(!dfn[v]) {
			fa[v]=i;
			Tarjan(v);
		}
		if(dfn[u]>=dfn[v]) {
			pair<ll,ll> sum=make_pair(A[i],B[i]);
			C.push_back(make_pair(A[i],B[i]));
			vis[i]=vis[i^1]=1;
			for(int j=u;j!=v;j=e[fa[j]^1]) {
				C.push_back(make_pair(A[fa[j]],B[fa[j]]));
				sum=sum+make_pair(A[fa[j]],B[fa[j]]);
				vis[fa[j]]=vis[fa[j]^1]=1;
			}
			for(int j=0;j<C.size();j++) {
				C[j]=sum-C[j];
			}
			solve();
		}
	}
}

ll ans=inf;

bool cmp(pair<ll,ll> a,pair<ll,ll> b) {
	return a.y*b.x<b.y*a.x;
}

int main() {
    freopen("20.in","r",stdin);
    freopen("20.out","w",stdout);
	scanf("%d %d",&n,&m);
	memset(h,-1,sizeof(int)*(n+1));
	for(int i=1;i<=m;i++) {
		int u,v;
		ll A,B;
		scanf("%d %d %lld %lld",&u,&v,&A,&B);
		add(u,v,A,B);
		add(v,u,A,B);
	}
	res.push_back(make_pair(0,0));
	Tarjan(1);
	sort(res.begin()+1,res.end(),cmp);
	for(int i=0;i<idx;i+=2) {
		if(!vis[i]) {
			res[0]=res[0]+make_pair(A[i],B[i]);
		}
	}
	ans=min(ans,res[0].x*res[0].y);
	for(int i=1;i<res.size();i++) {
		res[i]=res[i]+res[i-1];
		ans=min(ans,res[i].x*res[i].y);
	}
	printf("%lld",ans);
	return 0;
}