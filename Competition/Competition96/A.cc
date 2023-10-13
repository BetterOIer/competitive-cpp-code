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
long long n,m,a[100005],b[100005],ans=0;
int main(){
    freopen("genshin.in","r",stdin);
    freopen("genshin.out","w",stdout);
    n=read();
    for(long long i  =1;i<=n;i++){
        a[i]=read();
        if(a[i]&1)i--,n--;
    }
    m=read();
    for(long long i  =1;i<=m;i++){
        b[i]=read();
        if(!(b[i]&1))i--,m--;
    }
    sort(a+1,a+n+1);
    if(n<=m)cout<<0;
    else{
        for(long long i = 1;i<=n-m;i++)ans+=a[i];
        cout<<ans;
    }
    return 0;
}