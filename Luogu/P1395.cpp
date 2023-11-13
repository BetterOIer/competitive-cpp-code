/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
vector<int>ro[50005];
int dp[50004];
int siz[50004];
int ans,po;
int getDP(int pos,int fa,int &dp){
    siz[pos]=1;
    for(auto i:ro[pos]){
        if(i==fa)continue;
        siz[pos]+=getDP(i,pos,dp);
    }
    dp+=siz[pos]-1;
    return siz[pos];
}
void dfs(int pos,int fa){
    for(auto i:ro[pos]){
        if(i==fa)continue;
        dp[i]=dp[pos]+n-siz[i]-siz[i];
        if(dp[i]<ans||(dp[i]==ans&&i<po))ans=dp[i],po=i;
        dfs(i,pos);
    }
}
int main(){
    #ifndef LOCAL
    #else
    freopen("test.in","r",stdin);
    freopen("test.out","w",stdout);
    #endif
    n=read();
    for(int i = 1,u,v;i<n;i++){
        u=read(),v=read();
        ro[u].push_back(v);
        ro[v].push_back(u);
    }
    getDP(1,0,dp[1]);ans=dp[1];
    po=1;
    dfs(1,0);
    cout<<po<<" "<<ans;
    return 0;
}