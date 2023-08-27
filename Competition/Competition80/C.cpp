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
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m;
int fa[200004];
struct EDGE{
    int x1;
    int x2;
    int va;
    int vb;
    int vavb;
    int vis;
}edge[300005];
int find(int a){
    if(fa[a]==a)return a;
    else return fa[a]=find(fa[a]);
}
void join(int edg){
    fa[find(edge[edg].x1)]=find(edge[edg].x2);
}
void Kruskal(){
    int suma=0,sumb=0,ans=0,cho=n-1;
    for(int i = 1;i<=n;i++)fa[i]=i;
    while(cho){
        int whi=0,cnt=0;
        for(int i = 1;i<=m;i++){
            if(edge[i].vis)continue;
            if(find(edge[i].x1)==find(edge[i].x2)){edge[i].vis=true;continue;}
            int tmp = ans+suma*edge[i].vb+sumb*edge[i].va+edge[i].vavb;
            if(cnt>tmp||(!cnt))  whi=i,cnt=tmp;
        }
        join(whi);
        suma+=edge[whi].va;
        sumb+=edge[whi].vb;
        edge[whi].vis=true;
        //cout<<whi<<" ";
        ans=cnt;
        cho--;
        
    }
    cout<<ans;
}
int main(){
    n=read(),m=read();
    for(int i = 1;i<=m;i++){
        edge[i].x1=read(),edge[i].x2=read(),edge[i].va=read(),edge[i].vb=read();
        edge[i].vavb=edge[i].va*edge[i].vb;
    }
    Kruskal();
    return 0;
}