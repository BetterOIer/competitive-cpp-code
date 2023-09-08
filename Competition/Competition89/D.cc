#include<bits/stdc++.h>
using namespace std;
inline  long long read(){
    long long x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
const int N=1000005,mod=998244353,logN=25;
int fac[N],ni[N],n,x,y,tot,sz[N<<1],ycl[N<<1],siz[logN];
int sum[logN],dp[logN][N];
long long ans=1;
inline long long ksm(long long a,int b){
	int ans=1;
	for(;b;b>>=1){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
	}
	return ans;
}
inline long long c(int a,int b){
	return a>=b?(long long)fac[a]*ni[b]%mod*ni[a-b]%mod:0;
}
void dfs(int p){
	if(p>n){
		ycl[p]=1; return;
	}
	dfs(p*2); dfs(p*2+1);
	sz[p]=sz[p*2]+sz[p*2+1];
	ycl[p]=(long long)ycl[p*2]*ycl[p*2+1]%mod*c(sz[p],sz[p*2])%mod;
	sz[p]++;
}
void solve(int x,int y){
	if(!x)return;
	solve(x/2,x);
	if(!y)ans=ans*ycl[x]%mod; else ans=ans*ycl[x*2==y?x*2+1:x*2]%mod;
	siz[++tot]=sz[x]-sz[y];
}
int main(){
	n=read(); x=read(); y=read();
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=(long long)fac[i-1]*i%mod;
    ni[n]=ksm(fac[n],mod-2);
	for(int i=n-1;i>=0;i--)ni[i]=(long long)ni[i+1]*(i+1)%mod;
	dfs(1);
	solve(x,0);
	dp[tot][y]=c(n-y,siz[tot]-1);
	for(int i=y-1;i;i--)dp[tot][i]=dp[tot][i+1];
	sum[tot]=siz[tot];
	for(int i=tot-1;i;i--){
		sum[i]=sum[i+1]+siz[i];
		for(int j=y;j;j--){
			dp[i][j]=(dp[i][j+1]+dp[i+1][j+1]*c(n-j-sum[i+1],siz[i]-1))%mod%mod;
		}
	}
	cout<<ans*dp[1][1]%mod<<endl;
}