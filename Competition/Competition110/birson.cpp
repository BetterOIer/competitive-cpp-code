#include<iostream>
using namespace std;
const long long mod = 998244353;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,m,u1,u2,k1,k2;
long long n2k(long long x,long long k){
    long long res= 0;
    long long tmp=1;
    while(x){
        res=res+1ll*(1ll*x%k)*tmp;
        x=1ll*x/k;
        tmp*=1ll*10;
    }
    return res;
}
long long k2n(long long x,long long k){
    long long tmp=1,res=0;
    while(x){
        res=res+1ll*(x%10)*tmp;
        x/=10LL;
        tmp*=1ll*k;
    }
    return res;
}
long long cal(long long v1,long long v2,long long v3,long long k){
    v1=n2k(v1,k),v2=n2k(v2,k),v3=n2k(v3,k);
    long long res=0;
    string V1 = to_string(v1);
    string V2 = to_string(v2);
    string V3 = to_string(v3);
    int len = max(V1.length(),max(V2.length(),V3.length()));
    while(int(V1.length())<len)V1="0"+V1;
    while(int(V2.length())<len)V2="0"+V2;
    while(int(V3.length())<len)V3="0"+V3;
    for(long long i = 0;i<len;i++){
        V1[i]=((V1[i]-'0')+(V2[i]-'0')+(V3[i]-'0'))%k+'0';
        res=1ll*res*10+V1[i]-'0';
    }
    return k2n(res,k);
}
long long qpow(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1) (res*=1ll*a)%=mod;
        (a*=1ll*a)%=mod;
        b>>=1;
    }
    return (1ll*res%mod+mod)%mod;
}
long long  inv(long long x){
    return qpow(x,mod-2);
}
int main(){
    #ifndef LOCAL
    freopen("birson.in","r",stdin);
    freopen("birson.out","w",stdout);
    #else
    #endif
    n=read(),m=read(),u1=read(),u2=read(),k1=read(),k2=read();
    long long res = 0;
    for(long long i = 0;i<=n;i++){
        for(long long j = 0;j<=m;j++){
            for(long long u = u1;u<=u2;u++){
                for(long long k = k1;k<=k2;k++){
                    (res+=1ll*cal(i,j,u,k))%=mod;
                }
            }
        }
    }

    (res*=1ll*inv(1LL*(n+1)%mod*(m+1)%mod*(u2-u1+1)%mod*(k2-k1+1)%mod))%=mod;
    cout<<res;
    return 0;
}