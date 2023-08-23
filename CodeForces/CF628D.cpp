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
const int mod = 1e9+7;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int m,d;
int dp[2005][2005];
int a[2005];
string l,r;
int dfs(int pos,int x,bool lim){
    if(pos==0) return !x;
    if(!lim&&dp[pos][x]!=-1)return dp[pos][x];
    int high = lim? a[pos]:9;
}
int main(){
    m=read(),d=read(),l=read(),r=read();
    cin>>l>>r;
    return 0;
}