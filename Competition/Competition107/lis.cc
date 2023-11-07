#include<iostream>
#include<cstring>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int a[505],n,maxC,ans[250005];
int dp[505][505][505];
int minn[505][505][505];
int main(){
    #ifndef LOCAL
    freopen("lis.in","r",stdin);
    freopen("lis.out","w",stdout);
    #else
    #endif
    n=read(),maxC = n*n;memset(dp,0x3f3f3f3f,sizeof dp);
    for(int i = 1;i<=n;i++){
        a[i]=read();
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=i;j++){
            minn[i][j][0]=0x3f3f3f3f;
            for(int v = 1;v<=n;v++){
                dp[i][j][v]=min(dp[i-1][j][v],minn[i-1][j-1][v-1]+abs(a[i]-v));
                minn[i][j][v]=min(dp[i][j][v],minn[i][j][v-1]);
            }
        }
    }
    for(int j = 1;j<=n;j++)if(minn[n][j][n]<=maxC)ans[minn[n][j][n]]=j;
    for(int i = 0,res=0;i<=maxC;i++){
        res = max(res,ans[i]);cout<<res<<" ";
    }
    return 0;
}
