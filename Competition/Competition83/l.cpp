/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<vector>
using namespace std;
const int mod = 2333;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,q,s,t,l,r,ans=0;
vector<int> ro[40];
int add(int a){
    a+=1;
    if(a>=mod) a-=mod;
    return a;
}
void dfs(int pos,int dis){
    if(dis>r) return;
    if(pos==t){
        if(dis>=l&&dis<=r)ans=add(ans);
    }
    for(int to:ro[pos]){
        dfs(to,dis+1);
    }
}
int main(){
    freopen("l.in","r",stdin);
    freopen("l.out","w",stdout);
    n=read(),m=read();
    for(int i = 1,u,v;i<=m;i++){
        u=read(),v=read();
        if(u==v)continue;
        ro[u].push_back(v);
        ro[v].push_back(u);
    }
    q=read();
    while(q--){
        s=read(),t=read(),l=read(),r=read(),ans=0;
        dfs(s,0);
        cout<<ans<<endl;
    }
    return 0;
}