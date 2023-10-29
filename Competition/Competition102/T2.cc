#include<iostream>
#include<algorithm>
using namespace std;
inline long long read(){
    long long x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
long long t[5005],dp[5005];
long long ans = 1e18;
int main(){
    #ifndef LOCAL
    freopen("songfen.in","r",stdin);
    freopen("songfen.out","w",stdout);
    #endif
    long long n=read(),k=read(),A=read(),B=read();
    for(long long i = 1;i<=k;i++) dp[i]=1e18;
    for(long long i = 1;i<=n;i++){
        t[i]=read();
        if(i>k){
            dp[0]=min(dp[0],dp[k]+A);
            dp[k]=1e18;
        }
        for(long long j = min(i,k)-1;j>=0;j--){
            dp[j+1] = min(dp[j+1],dp[j]);
            dp[j]+=min(j,k-j)*B+t[i];
        }
    }
    for(long long i = 1;i<=k;i++)ans=min(ans,dp[i]);
    if(ans!=1e18)ans+=A;
    ans=min(ans,dp[0]);
    cout<<ans;
    return 0;
}
//100pts