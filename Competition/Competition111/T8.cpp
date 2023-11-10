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
long long n,q;
long long a[200005];
int main(){
    n=read(),q=read();
    for(long long i =1;i<=n;i++){
        long long x,y,z;
        scanf("%lldx%lld=%lld",&x,&y,&z);
        a[i]=(z-y)/x;
    }
    sort(a+1,a+n+1);
    long long tot = unique(a+1,a+n+1)-a-1;
    a[tot+1]=1145141919810;
    for(long long i = 1,x,y;i<=q;i++){
        x=read(),y=read();
        long long px = lower_bound(a+1,a+tot,x)-a;px-=3;if(px<0)px=0;
        long long py = lower_bound(a+1,a+tot,y)-a;py+=3;if(py>tot+1)py=tot+1;
        while(a[px]<x)px++;
        px--;
        while(a[py]>y)py--;
        py++;
        cout<<py-px-1<<endl;
    }
    return 0;
}