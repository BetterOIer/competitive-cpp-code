#include<iostream>
#include<cmath>
using namespace std;
const long long mod = 998244353;
inline long long read(){
    long long x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
long long n;
long long a[1000005],fac[1000005];
void getFac(long long lim=1000005){
    fac[0]=1;
    for(long long i = 1;i<=lim;i++){
        fac[i]=1ll*fac[i-1]*i%mod;
    }
}
long long qpow(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1) res=1ll*res*a%mod;
        a=1ll*a*a%mod;
        b>>=1;
    }
    return 1ll*(res+mod)%mod;
}
long long getInv(long long x){
    return qpow(x,mod-2);
}
long long C(long long a,long long b){
    return 1ll*fac[a]*getInv(fac[b])%mod*getInv(fac[a-b])%mod;
}
int main(){
    getFac();
    n=read();
    a[0]=a[1]=1;
    for(long long i = 2;i<=n;i++){
        long long h = log2(i+1)-1;
        long long cnt = qpow(2,h);
        long long b = cnt-1;
        long long r = i-1-2*b;
        long long r1 = (r-(r/cnt)*((r-cnt+mod)%mod)+mod)%mod;
        long long r2 = (r-r1+mod)%mod;
        a[i] = (C(i-1,b+r1)*a[b+r1])%mod*a[b+r2]%mod;
    }
    cout<<a[n];
    return 0;
}