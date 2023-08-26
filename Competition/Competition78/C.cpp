/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<algorithm>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,maxn=0,ans,minn=2147483647;
long long a[1000005],b[1000005];
long long cost[1000005],idx;
long long sum[1000005];
bool cmp(long long x,long long y){return b[x]<b[y];}
int main(){
    n=read();
    for(long long i = 1;i<=n;i++){
        a[i]=read(),b[i]=read();
        if(a[i]>b[i]){
            cost[++idx]=i;
            minn=min(minn,b[i]);
            maxn=max(maxn,a[i]);
        }else{
            maxn=max(maxn,b[i]);
        }
    }
    if(idx){
        sort(cost+1,cost+idx+1,cmp);
        ans=maxn-minn;
        for(long long i = 1;i<=idx;i++){
            sum[i]=sum[i-1]+((a[cost[i]]-b[cost[i]])<<1);
        }
        for(long long i = 1;i<=idx;i++){
            ans=min(ans,maxn-(b[cost[i+1]]? b[cost[i+1]]:maxn)+sum[i]);
        }
    }
    ans+=maxn;
    cout<<ans;
    return 0;
}