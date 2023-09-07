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
int n;
int valRab[55];
int maxVal,ans=1e9+7;
int dp[100005];
int main(){
    n=read();
    memset(dp,0x3f3f3f3f,sizeof dp);
    dp[1]=0;
    for(int i = 1;i<=n;i++){
        valRab[i]=read();
        maxVal = max(maxVal,valRab[i]);
        dp[1]+=valRab[i];
    }
    ans=dp[1];
    for(int i = 1;i<=(maxVal>>1);i++){
        for(int j = 2;j*i<=maxVal;j++){
            int minus = 0;
            for(int r = 1;r<=n;r++){
                minus+=valRab[r]/(i*j);
            }
            dp[i*j]=min(dp[i*j],dp[i]-minus*(j-1));
        }
    }
    for(int i = 1;i<=maxVal;i++){
        ans=min(dp[i],ans);
    }
    cout<<ans;
    return 0;
}