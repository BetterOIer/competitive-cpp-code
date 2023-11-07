#include<iostream>
#include<cstring>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int a[505],n,maxC,ans[250005];
int dp[2][505][505];
int minn[2][505][505];
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
    int pos=0;
    for(int i = 1;i<=n;i++,pos^=1){
        for(int j = 1;j<=i;j++){
            minn[pos][j][0]=0x3f3f3f3f;
            for(int v = 1;v<=n;v++){
                dp[pos][j][v]=min(dp[pos^1][j][v],minn[pos^1][j-1][v-1]+abs(a[i]-v));
                minn[pos][j][v]=min(dp[pos][j][v],minn[pos][j][v-1]);
            }
        }
    }
    pos^=1;
    for(int j = 1;j<=n;j++)if(minn[pos][j][n]<=maxC)ans[minn[pos][j][n]]=j;
    for(int i = 0,res=0;i<=maxC;i++){
        res = max(res,ans[i]);cout<<res<<" ";
    }
    return 0;
}
