#include<bits/stdc++.h>
using namespace std;
template <typename T> bool chkmax(T &x,T y){return x<y?x=y,1:0;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,1:0;}
typedef long long ll;
typedef pair<int,int> pii;
#define mp make_pair
#define pb push_back
#define x first
#define y second
inline int read(){
	int x=0,f=1;char c=getchar();
	for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
	for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
	return x*f;
}
int a[1505],b[1505],n;
const int inf=0x3f3f3f3f;
struct bit{
	int s[3005];
	void add(int x,int y){
		for(;x;x^=x&-x)chkmin(s[x],y);
	}
	int sum(int x){
		int y=inf;
		for(;x<=n+n;x+=x&-x)chkmin(y,s[x]);return y;
	}
	void init(){
		for(int i=1;i<=n+n;++i)s[i]=inf;
	}
};
bit row[3005],col[3005];
int f[3005][3005];
void add(int x,int y,int z){
	row[x].add(y,z);
	col[y].add(x,z);
}
int main(){
    #ifndef LOCAL
    freopen("extreme.in","r",stdin);
    freopen("extreme.out","w",stdout);
    #else
    freopen("C/ex_C3.in","r",stdin);
    freopen("C/ex_C3.out","w",stdout);
    #endif
	int k;
	n=read(),k=read();
	for(int i=1;i<=n;++i)a[i]=read();
	for(int i=1;i<=n;++i)b[i]=read();
	for(int i=1;i<=n+n;++i){row[i].init();col[i].init();}
	for(int i=1;i<=n+n;++i)for(int j=1;j<=n+n;++j)f[i][j]=inf;
	row[1].add(1,0);
	col[1].add(1,0);
	int s=0;
	for(int i=1;i<=n;++i){
		int w=inf;
		for(int j=max(i-k,1);j<=i+k;++j)chkmin(w,row[j].sum(max(i-k,1)));
		f[i+k+1][i+k+1]=w+a[i]+b[i];

		for(int j=max(i-k,1);j<=i+k;++j){
			chkmin(f[j==i?j+1:j][i+k+1],row[j].sum(max(i-k,1))+a[i]);
		}
		for(int j=max(i-k,1);j<=i+k;++j){
			chkmin(f[i+k+1][j==i?j+1:j],col[j].sum(max(i-k,1))+b[i]);
		}
		s+=a[i]+b[i];
		for(int j=max(i-k,1);j<=i+k+1;++j){
			add(j,i+k+1,f[j][i+k+1]);
			add(i+k+1,j,f[i+k+1][j]);
		}
	}
	int mn=inf;
	for(int i=n+1;i<=n+k+1;++i){
		chkmin(mn,row[i].sum(n+1));
	}
	printf("%d\n",s-mn);
	return 0;
}
