#include<iostream>
using namespace std;
const long long mod = 998244353;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n,t,q;
/* long long fac[200005];
void getFac(long long lim=200000){
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
long long getDis(int xl,int yl,int xr,int yr){
    return C(xr-xl+yr-yl,xr-xl);
} */
int main(){
    #ifndef LOCAL
    freopen("typical.in","r",stdin);
    freopen("typical.out","w",stdout);
    #endif
    n=read(),t=read(),q=read();/* getFac(n<<1); */
    for(int i = 1,xs,ys,xt,yt;i<=q;i++){
        xs=read(), ys=read(), xt=read(), yt=read();
        if(abs(xt-xs)+abs(yt-ys)>t||((t-abs(xt-xs)-abs(yt-ys))&1)==1)cout<<"0\n";
        else{
            /* if(xs>xt)swap(xs,xt);
            if(ys>yt)swap(ys,yt);
            cout<<getDis(xs,ys,xt,yt)<<endl; */
        }
    }
    return 0;
}