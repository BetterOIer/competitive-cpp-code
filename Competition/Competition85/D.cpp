#include<iostream>
#include<algorithm>
using namespace std;
const long long mod = 1e9+7;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long h,w,n,dis[3003],fac[9018009];
struct node{
    long long x;
    long long y;
};
bool operator < (node a, node b){
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
node po[3003];
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
int main(){
    getFac();
    h=read(),w=read(),n=read();
    for(long long i = 1;i<=n;i++){
        po[i].x=read(),po[i].y=read();
    }
    po[++n].x=h,po[n].y=w;
    sort(po+1,po+n+1);
    for(long long i = 1;i<=n;i++) dis[i]=C(po[i].x+po[i].y-2,po[i].x-1);
    for(long long i = 1;i<=n;i++){
        for(long long j = 1;j<i;j++){
            if(po[j].x<=po[i].x&&po[j].y<=po[i].y){
                dis[i]-=1ll*dis[j]*C(po[i].x-po[j].x+1+po[i].y-po[j].y+1-2,po[i].x-po[j].x+1-1);
                (dis[i]+=mod)%=mod;
            }
        }
    }
    cout<<(dis[n]+mod)%mod<<endl;
    return 0;
}