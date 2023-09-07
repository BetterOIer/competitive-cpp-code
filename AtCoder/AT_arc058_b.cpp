/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<algorithm>
using namespace std;
const long long mod = 1e9+7;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long h,w,a,b,ans,dis[3003],fac[9018009];
struct node{
    long long x;
    long long y;
};
bool operator < (node a, node b){
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
node po[1000003];
void getFac(long long lim=9018009){
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
}
int main(){
    getFac();
    h=read(),w=read(),a=read(),b=read();
    for(long long i = 1;i<=h-a;i++){
        (ans+=(getDis(1,1,i,b)*getDis(i,b+1,h,w)%mod))%=mod;
    }
    cout<<ans<<endl;
    return 0;
}