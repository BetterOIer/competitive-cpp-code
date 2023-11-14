#include<iostream>
#include<vector>
const long long mod = 998244353;
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,m,t,up,down;
long long hap[100005];
vector<long long>ro[100005];
long long ans=0,cnt;
long long gcd(long long __m, long long __n){
    while (__n != 0){
        long long __t = __m % __n;
        __m = __n;
        __n = __t;
    }
    return __m;
}
long long qpow(long long a,long long b){
    long long res = 1;
    while(b){
        if(b&1)res=res*a%mod;
        a=a*a%mod;
        b>>=1LL;
    }
    return 1LL*(res%mod+mod)%mod;
}
long long inv(long long x){
    return qpow(x,mod-2LL);
}
long long cal(long long val,long long u,long long d){
    return 1LL*val%mod*u%mod*inv(d)%mod;
}
void dfs(long long day,long long pos,long long fa,long long u,long long d){
    long long g=gcd(u,d);u/=g,d/=g;
    bool flag=false;
    if(day==t+1){
        ans=(ans+cal(hap[pos],u,d))%mod;
        return;
    }
    for(long long i:ro[pos]){
        if(i==fa)continue;   
        flag=true;dfs(day+1LL,i,pos,1LL*u*up,1LL*d*down*((long long)ro[pos].size()-1LL*(fa!=pos)+1LL*(fa==0)));
    }
    if(flag)dfs(day+1LL,pos,pos,1LL*u*(down-up),1LL*d*down);
    else dfs(day+1,pos,pos,u,d);
}
int main(){
    #ifndef LOCAL
    freopen("masses.in","r",stdin);
    freopen("masses.out","w",stdout);
    #else
    freopen("exmasses_1.in","r",stdin);
    freopen("exmasses_1.res","w",stdout);
    #endif
    scanf("%lld %lld %lld %lld/%lld",&n,&m,&t,&up,&down);
    for(long long i = 1;i<=n;i++)hap[i]=read();
    for(long long i = 1,u,v;i<=m;i++){
        u=read(),v=read();
        ro[u].push_back(v);
        ro[v].push_back(u);
    }
    for(long long i = 1;i<=n;i++){
        dfs(1LL,i,0LL,1LL,n);
    }
    cout<<ans;
    return 0;
}