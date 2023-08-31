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
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long k,r;
long long p[30];
long long maxn=0;
long long dfs(long long step,long long ori){
    long long cnt=0;
    if(step>k){
        maxn=max(maxn,ori);
        return 1;
    }
    while(ori<=r){
        cnt+=dfs(step+1,ori);
        ori*=p[step];
    }
    return cnt;
}
int main(){
    freopen("h.in","r",stdin);
    freopen("h.out","w",stdout);
    k=read(),r=read();
    for(long long i = 1;i<=k;i++) p[i]=read();
    long long ans = dfs(1,1);
    cout<<maxn<<endl<<ans;
    return 0;
}