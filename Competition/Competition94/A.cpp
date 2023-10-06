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
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,a[1000005];
struct QUERY{
    int l;
    int r;
    int ans;
}que[1000005];
bool operator < (const QUERY a, const QUERY b){
    if(a.l==b.l) return a.r<b.r;
    return a.l<b.l;
}
int main(){
    n=read(),m=read();
    for(int i = 1;i<=n;i++){
        a[i]=read();
    }
    for(int i  =1;i<=m;i++){
        que[i].l=read(),que[i].r=read();
    }
    sort(que+1,que+m+1);
    
    return 0;
}