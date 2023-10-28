#include<iostream>
#include<cmath>
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);
    return x*f;
}
int a[2000005];
int dp[2000005];
long long ans=0;
int main(){
    #ifndef LOCAL
    freopen("qiandao.in","r",stdin);
    freopen("qiandao.out","w",stdout);
    #else
    freopen("ex_segmin4.in","r",stdin);
    freopen("ex_segmin4.out","w",stdout);
    #endif
    int n = read();
    for(int i = 1;i<=n;i++) a[i]=read();
    for(int i = 1;i<=n;i++) dp[i]=i;
    for(int k = 2;k<=n;k++){
        for(int l = 1,r;l<=n-k+1;l++){
            r = l+k-1;
            if(a[dp[l]]>=a[r]) dp[l]=r;
            if(dp[l]>=((l+r)>>1)+1) ++ans;
        }
    }
    cout<<ans;
    return 0;
}