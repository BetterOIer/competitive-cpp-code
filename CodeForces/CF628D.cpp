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
const long long mod = 1e9+7;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long m,d,len=0;
long long dp[2005][2005][2][2];
long long L[2005],R[2005];
string l,r;
long long dfs(long long pos,long long x,bool Rl,bool Ll,bool ji){
    if(!pos) return !x;
    if(~dp[pos][x][Ll][Rl])return dp[pos][x][Ll][Rl];
    long long high = Rl? min(R[pos],9LL):9,low = Ll? max(L[pos],0LL):0;
    if(ji){
        long long ans=0;
        for(long long i = low;i<=high;i++){
            if(i==d)continue;
            (ans+=dfs(pos-1,(x*10+i)%m,Rl&(i==high),Ll&(i==low),ji^1))%=mod;
        }
        return dp[pos][x][Ll][Rl]=ans;
    }else{
        if(d<low||d>high)return dp[pos][x][Ll][Rl]=0;
        return dp[pos][x][Ll][Rl]=dfs(pos-1,(x*10+d)%m,Rl&(d==high),Ll&(d==low),ji^1);
    }
    return dp[pos][x][Ll][Rl];
}
int main(){
    m=read(),d=read();
    cin>>l>>r;len=l.length();
    memset(dp,-1,sizeof dp);
    for(long long i = 0;i<len;i++){
        L[len-i]=l[i]^48;
        R[len-i]=R[i]^48;
    }
    cout<<dfs(len,0,1,1,1);
    return 0;
}
