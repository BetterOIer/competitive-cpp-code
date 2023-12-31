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
int n;
struct node{
    int d;
    int s;
}trap[105];
bool operator <(const node a,const node b){
    return a.d<b.d;
}
int main(){
    int t=read();
    while(t--){
        int lim=1e9;
        n=read();
        for(int i = 1;i<=n;i++){
            trap[i].d=read(),trap[i].s=read();
        }
        sort(trap+1,trap+n+1);
        for(int i = 1;i<=n;i++){    
            if(trap[i].d>lim)break;
            lim=min(lim,trap[i].d+(trap[i].s-1)/2);
        }
        cout<<lim<<endl;;
    }
    return 0;
}