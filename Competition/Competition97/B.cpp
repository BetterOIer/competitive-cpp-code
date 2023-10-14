#include<iostream>
#include<algorithm>
#include<cstring>
#include<climits>
using namespace std;
const __int128 mod = __int128(1)<<64;
inline __int128 read(){
    __int128 x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
__int128 m,q,cnt[1000005],t;
struct node{
    __int128 a;
    __int128 b;
    __int128 xjb;
}sell[100005];
bool operator < (node a, node b){
    if(a.xjb==b.xjb) return a.a<b.a;
    return a.xjb<b.xjb;
}
__int128 cal(__int128 n){
    if(n==0)return 0;
    __int128 ans=(__int128)LLONG_MAX*(__int128)LLONG_MAX;
    for(__int128 i = 1;i<=m;i++){
        if(n>=sell[i].a){
            __int128 tmp = 0;
            if(n-sell[i].a<=1000000&&cnt[n-sell[i].a])tmp = cnt[n-sell[i].a];
            else tmp = cal(n-sell[i].a);
            if(tmp==LLONG_MAX*LLONG_MAX)continue;
            if(ans>tmp+sell[i].b){
                ans=tmp+sell[i].b;
            }
        }
    }
    if(n<=1000000) return cnt[n]=ans;
    return ans;
}
__int128 getAns(__int128 n){
    __int128 ans=0;
    for(__int128 i = n-1;i>=0;i--){
        ans=(ans+cal(i))%mod;
    }
    return ans;
}
int main(){
    freopen("paradise.in","r",stdin);
    freopen("paradise.out","w",stdout);
    t=read(),m = read();
    while(t--){
        m=read(),q=read();
        for(__int128 i = 1;i<=m;i++){
            sell[i].a=read(),sell[i].b=read();
        }
        for(__int128 i = 1;i<=m;i++){
            sell[i].xjb= sell[m].a/sell[i].a*sell[i].b;
        }
        sort(sell+1,sell+m+1);
        for(__int128 i  =1;i<=q;i++){
            __int128 n = read();
            printf("%lld\n",(long long)getAns(n));
        }
        memset(sell,0,sizeof sell);
        memset(cnt,0,sizeof cnt);
    }
    return 0;
}