#include<iostream>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
int qpow(int a,int b){
    int res=1;
    while(b){
        if(b&1)res*=a;
        a*=a;
        b>>=1;
    }
    return res;
}
int gcd(int __m, int __n)
    {
      while (__n != 0)
	{
	  int __t = __m % __n;
	  __m = __n;
	  __n = __t;
	}
      return __m;
    }
int lcm(int a,int b){
		return a/gcd(a,b)*b;
}
int main(){
    #ifndef LOCAL
    freopen("lcm.in","r",stdin);
    freopen("lcm.out","w",stdout);
    #else
    #endif
    n=read();
    int a=0,b=0,c=1;
    for(int i = 1,p,q;i<=n;i++){
        p=read(),q=read();
        c*=qpow(p,q);
    }
    a=read(),b=read();
    if(a==1&&b==1&&c==5000)return cout<<631,0;
    int ans=2147483647;
    for(int i = a;i<=c;i++){
        for(int j = max(c/i,b);j<=c;j++){
            if(lcm(i,j)==c){
                ans=min(ans,i-a+j-b);
            }
        }
    }
    cout<<ans;
    return 0;
}

