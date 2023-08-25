/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<cstring>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int a,b,mod;
int dp[20][200][200][2];
int num[20],idx=0;
int dfs(int pos,int sum,int ori,bool lim){
    if(!pos)return sum==mod&&ori==0;
    if(~dp[pos][sum][ori][lim])return dp[pos][sum][ori][lim];
    int high = (lim? num[pos]:9),ans=0;
    for(int i = 0;i<=high;i++){
        ans+=dfs(pos-1,sum+i,(ori*10+i)%mod,lim&&i==high);
    }
    return dp[pos][sum][ori][lim]=ans;
}
int main(){
    a=read()-1,b=read();
    while(a) num[++idx]=a%10,a/=10;
    int ans1,ans2;
    for(int i = 1;i<=idx*9;i++){
        mod = i;
        memset(dp,-1,sizeof dp);
        ans1 += dfs(idx,0,0,1);
        cout<<ans1<<endl;
    }
    idx=0;
    while(b) num[++idx]=b%10,b/=10;
    for(int i = 1;i<=idx*9;i++){
        mod = i;
        memset(dp,-1,sizeof dp);
        ans2 += dfs(idx,0,0,1);
    }
    cout<<ans2-ans1;
    return 0;
}