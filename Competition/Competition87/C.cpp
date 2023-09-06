#include<iostream>
using namespace std;
const long long mod=998244353;
inline long long read(){
    long long x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
long long t,n,x[200010],A[200010],B[200010],C[200010],D[200010];
int main(){
    freopen("count.in","r",stdin);
    freopen("count.out","w",stdout);
	x[1]=1,A[1]=1,B[1]=0,C[1]=0,D[1]=0,x[2]=2,A[2]=1,B[2]=1,C[2]=0,D[2]=0,x[3]=6,A[3]=2,B[3]=2,C[3]=2,D[3]=0,x[4]=24,A[4]=6,B[4]=6,C[4]=6,D[4]=6,x[0]=1,A[0]=0,B[0]=0,C[0]=0,D[0]=0;
	for(int i=5;i<=200010;++i)A[i]=x[i-1]%mod,B[i]=(B[i-2]+x[i-2]+x[i-3]+2*x[i-4])%mod,C[i]=(B[i-1]+x[i-3]+3*x[i-4]+x[i-5])%mod,D[i]=(B[i-2]+C[i-1]+3*x[i-4]+x[i-5])%mod,x[i]=(A[i]+B[i]+C[i]+D[i])%mod;
	t=read();
	while(t--){
		n=read();
		cout<<x[n]<<endl;
	}
	return 0;
}
