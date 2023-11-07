#include<iostream>
#include<cstring>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int a[505],n,maxC,ans[250005]/* ,sta[505][2];
int dp[505][250005][2] */;
int dp[505]={0,1};
int getLstSeq(){
    memset(dp,0,sizeof dp);dp[1]=1;
    for(int i = 2;i<=n;i++){
        for(int j = 1;j<i;j++){
            dp[i]=max(dp[i],dp[j]+(a[i]>a[j]));
        }
    }
    return dp[n];
}
void dfs(int pos,int s){
    if(pos==n+1){
        ans[maxC-s]=max(ans[maxC-s],getLstSeq());
        return;
    }
    for(int i = 0;i<=s;i++){
        a[pos]+=i;if(a[i]<=n)dfs(pos+1,s-i);
        a[pos]-=i*2;if(a[i]>=1)dfs(pos+1,s-i);
        a[pos]+=i;
    }
}
int main(){
    #ifndef LOCAL
    freopen("lis.in","r",stdin);
    freopen("lis.out","w",stdout);
    #else
    #endif
    n=read(),maxC = n*n;
    for(int i = 1;i<=n;i++){
        a[i]=read();
    }
    dfs(1,maxC);
    for(int i = 0;i<=maxC;i++)cout<<ans[i]<<" ";
    /* for(int i = 1;i<=n;i++){
        for(int s = 0;s<=maxC;s++){
            dp[i][s][0]=max(dp[i-1][s][0]+(a[i]>sta[i-1][0]))
        }
    } */
    return 0;
}