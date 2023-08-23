/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
using namespace std;
const long long mod = 1e9+7;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long g[505][505];
long long dp[505][505];
long long n,m,k;
int main(){
    n=read(),m=read(),k=read();
    for(long long i = 1;i<=n;i++){
        for(long long j = 1;j<=m;j++){
            g[i][j]=read();
        }
    }
    dp[1][1]=1;
    for(long long I = 1;I<=n;I++){
        for(long long J = 1;J<=m;J++){
            for(long long i = 1;i<I;i++){
                for(long long j = 1;j<J;j++){
                    if(g[I][J]!=g[i][j])(dp[I][J]+=dp[i][j])%=mod;
                }
            }
        }
    }
    cout<<dp[n][m];
    return 0;
}