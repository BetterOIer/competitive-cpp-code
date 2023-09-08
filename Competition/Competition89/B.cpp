#include<iostream>
using namespace std;
const long long mod = 998244353;
inline pair<long long,long long> read1(){
    long long x1=0,x2=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x1=(x1*10%(mod-1)+(c-'0'))%(mod-1),x2=(x2*10%(mod)+(c-'0'))%(mod);
    return make_pair(x1*f,x2*f);
}
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
long long qpow(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1)res=(res*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return (res+mod)%mod;
}
int solve1(){
    pair<long long,long long> n=read1();
    printf("%lld",(1LL*(qpow(2,n.first-1)-n.second+mod)%mod)*qpow(qpow(2,n.first-1)%mod,mod-2)%mod);
    return 0;
}

int solve2(){
    long long t=read();
    while(t--){
        long long n=read();
        printf("%s",(n==1? "cqz\n":"ysgh\n"));
    }
    return 0;
}
int main(){
    long long opt=read();
    if(opt&1) solve1();
    else solve2();
    return 0;
}