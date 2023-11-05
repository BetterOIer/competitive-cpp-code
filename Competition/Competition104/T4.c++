#include<iostream>
#include<bitset>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
const int maxn=7505,maxk=55;
int n,m,T,ans,flg;
bitset<maxn>a[maxn],b[maxn],hav[maxk];
int main(){
    #ifndef LOCAL
    freopen("soldier.in","r",stdin);
    freopen("soldier.out","w",stdout);
    #endif
	n=read(),m=read();
	for(int i=1,k;i<=n;i++){
		k=read();
		for(int j=0,x;j<k;j++)
			x=read(),hav[x].set(i);
	}
	for(int p=1;p<=m;p++)
		for(int i=1;i<=n;i++){
			a[i]|=hav[p];
			if(hav[p][i])
				b[i]^=a[i],a[i].reset();
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<i;j++)
			ans+=b[i][j];
	cout<<ans;
	return 0;
}
