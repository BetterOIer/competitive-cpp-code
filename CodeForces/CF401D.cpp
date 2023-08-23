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
int len,m;
string s;
long long dp[262150][105];
int val[20];
bool vis[20];
int main(){
    cin>>s>>m;len=s.length();dp[0][0]=1;
    for(int i = len-1;i>=0;i--) val[i]=(s[i]-'0');
    for(int i = 1;i<(1<<len);i++){
        memset(vis,0,sizeof vis);
        for(int j = 0;j<len;j++){
            if(i==(1<<j)&&!val[j])break;
            if(!(i&(1<<j))||vis[val[j]])continue;
            vis[val[j]]=true;
            for(int k = 0;k<m;k++){
                dp[i][(k*10+val[j])%m]+=dp[i^(1<<j)][k];
            }
        }
    }
    cout<<dp[(1<<len)-1][0];
    return 0;
}