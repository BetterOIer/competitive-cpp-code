#include<iostream>
#include<vector>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,k,dp[1000005][2],tot;
vector<int>ro[1000005];
bool dfs(int pos,int fa){
    for(int i:ro[pos]){
        if(i==fa)continue;
        if(dfs(i,pos))dp[pos][1]+=dp[i][0];
        else dp[pos][0]+=dp[i][1];
    }
    return !dp[pos][1];
}
void chkAns(int pos,int fa){
    if(dp[fa][1]==(dp[pos][1]?0:dp[pos][0]))dp[pos][1]+=dp[fa][0]-dp[pos][1];
    else dp[pos][0]+=dp[fa][1]-(dp[pos][1]?0:dp[pos][0]);
    for(int i:ro[pos]){
        if(i==fa)continue;
        chkAns(i,pos);
    }
}
int main(){
    #ifndef LOCAL
    freopen("treegame.in","r",stdin);
    freopen("treegame.out","w",stdout);
    #else
    freopen("extreegame_6.in","r",stdin);
    freopen("extreegame_6.res","w",stdout);
    #endif
    n=read(),k=read();
    if(n==1)return printf("NO!"),0;
    for(long long i = 1,u,v;i<n;i++){
        u=read(),v=read();
        ro[u].push_back(v);
        ro[v].push_back(u);
    }
    for(long long i = 1;i<=n;i++)if(ro[i].size()==1)dp[i][0]=1;
    dfs(1,1);for(int i:ro[1])chkAns(i,1);
    if(k==1){for(long long i = 1;i<=n;i++){if(dp[i][1]){printf("%lld ",i);}}}
    else {for(long long i = 1;i<=n;i++){if(dp[i][1]){printf("%lld ",dp[i][1]);}}}
    return 0;
}