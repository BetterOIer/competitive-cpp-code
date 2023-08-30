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
const int mod = 2520;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int a, b;
int num[20],len,book[mod+1];;
int dp[20][mod+1][51][2];
int gcd(int x,int y){
    if(!y) return x;
    return gcd(y,x%y);
}
int dfs(int pos,int ori,int lcm,bool lim){
    if(!pos) return ori%lcm==0;
    if(~dp[pos][ori][lcm][lim]) return ~dp[pos][ori][lcm][lim];
    int high = lim? num[pos]:9,ans=0;
    for(int i = 1;i<=high;i++){
        int n_lcm = lcm*i/gcd(lcm,i);
        ans+=dfs(pos-1,(ori*10+i)%mod,n_lcm,lim&&i==high);
    }
    ans+=dfs(pos-1,ori,lcm,lim);
    return dp[pos][ori][lcm][lim]=ans;
}
int solve(int x){
    int cnt =x;len=0;
    while(cnt){
        num[++len]=cnt%10;
        cnt/=10;
    }
    memset(dp,-1,sizeof dp);
    return dfs(len,0,1,1);
}
int main(){
    int t=read();
    while(t--){
        a=read(),b=read();
        cout<<solve(b)-solve(a-1);
    }
    return 0;
}