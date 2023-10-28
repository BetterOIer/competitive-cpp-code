#include<iostream>
using namespace std;
const long long mod = 998244353;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int n,t,q,ans=0;
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
}
long long cal(int t){
    long long res = 0,tmp=1;
    for(int i = 2;i<=(t+1)/2;i++){
        long long cnt = getDis(1,1,i,2+t-i);
        res+=cnt*cnt%mod;
    }
    if(!(t&1)){
        long long cnt = getDis(1,1,1+t/2,1+t/2);
        tmp = (tmp+cnt*cnt%mod)%mod;
    }
    return (res*8%mod+tmp*4%mod)%mod;
} */
void add(){
    if(ans+1==mod)ans=0;
    else ans++;
}
void dfs(int x,int y,int nowT,int xt,int yt){
    if(nowT==t){if(x==xt&&y==yt)add();return;}
    if(abs(xt-x)+abs(yt-y)>t)return;
    if(x+1<=n)dfs(x+1,y,nowT+1,xt,yt);
    if(x-1>=0)dfs(x-1,y,nowT+1,xt,yt);
    if(y+1<=n)dfs(x,y+1,nowT+1,xt,yt);
    if(y-1>=0)dfs(x,y-1,nowT+1,xt,yt);
}
int main(){
    #ifndef LOCAL
    freopen("typical.in","r",stdin);
    freopen("typical.out","w",stdout);
    #else
    freopen("ex_canteen2.in","r",stdin);
    freopen("ex_canteen2.out","w",stdout);
    #endif
    n=read(),t=read(),q=read();/* getFac(n<<1); */
    for(int i = 1,xs,ys,xt,yt;i<=q;i++){
        xs=read(), ys=read(), xt=read(), yt=read();long long dis = abs(xt-xs)+abs(yt-ys);
        if(dis>t||((t-dis)&1)==1)cout<<"0\n";
        else{
            /* 
            if(xs>xt)swap(xs,xt);
            if(ys>yt)swap(ys,yt);
            long long
            ans1 = getDis(xs,ys,xt,yt),
            ans2 = C(dis+1,t-dis)+dis+1,
            ans3 = cal((t-dis)/2);
            cout<<ans1*ans2%mod*ans3%mod<<endl;
            什么牛马算法 趋势吧
             */

            //我最喜欢DFS了
            dfs(xs,ys,0,xt,yt);
            cout<<ans<<endl;ans=0;
        }
    }
    return 0;
}