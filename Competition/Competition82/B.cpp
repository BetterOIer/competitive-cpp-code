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
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n;
int a[100005];
int main(){
    int t=read();
    while(t--){
        n=read();
        for(int i = 1;i<=n;i++) a[read()]=i;int ans=0;
        for(int i = 1;i<n;i++) if(a[i]>a[i+1]) ans++;
        cout<<ans<<endl;
    }
    return 0;
}