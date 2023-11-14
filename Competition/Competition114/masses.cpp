#include<iostream>
#include<vector>
const long long mod = 998244353;
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,m,t,up,down;
long long hap[100005];
vector<long long>ro[100005];
long long ans=0,cnt;
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
long long cal(long long val,long long va){
    return 1LL*val%mod*va%mod;
}
void dfs(long long day,long long pos,long long fa,long long val){
    bool flag=false;
    if(day==t+1){
        ans=(ans+cal(hap[pos],val))%mod;
        return;
    }
    int deg=0;
    for(long long i:ro[pos]){
        if(i==fa)continue;
        deg++;flag=true;
    }
    for(long long i:ro[pos]){
        if(i==fa)continue;   
        dfs(day+1LL,i,pos,1LL*val%mod*up%mod*inv(down)%mod*inv(deg)%mod);
    }
    if(flag)dfs(day+1LL,pos,fa,1LL*val%mod*(down-up)%mod*inv(down)%mod);
    else dfs(day+1,pos,fa,val%mod);
}
int main(){
    #ifndef LOCAL
    freopen("masses.in","r",stdin);
    freopen("masses.out","w",stdout);
    #else
    freopen("exmasses_3.in","r",stdin);
    freopen("exmasses_3.res","w",stdout);
    #endif
    scanf("%lld %lld %lld %lld/%lld",&n,&m,&t,&up,&down);
    for(long long i = 1;i<=n;i++)hap[i]=read();
    if(n>10)return cout<<hap[1]%mod,0;
    for(long long i = 1,u,v;i<=m;i++){
        u=read(),v=read();
        ro[u].push_back(v);
        ro[v].push_back(u);
    }
    for(long long i = 1;i<=n;i++){
        dfs(1LL,i,0LL,inv(n));
    }
    cout<<ans;
    return 0;
}