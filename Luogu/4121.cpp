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
int n,m;
int g[205][205];
struct node{
    int w;
    int b;
    int ls[205];
    int rs[205];
}tr[1005];
struct POINT{
    int x;
    int y;
};
POINT fa[205][205];
POINT find(POINT po){
    if(fa[po.x][po.y].x==po.x&&fa[po.x][po.y].y==po.y) return fa[po.x][po.y];
    return fa[po.x][po.y]=find(fa[po.x][po.y]);
}
void build(int pos,int l,int r){
    if(l==r){
        for(int j = 1;j<=n;j++){
            tr[pos].ls[j]=tr[pos].rs[j] = fa[find((POINT){l,j}).x][find((POINT){l,j}).y]=find((POINT){l,j});
        }
    }
}
void update(int pos,int l,int r,int x){

}
int main(){
    n=read();
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            g[i][j]=read();
        }
    }
    build(1,1,n);
    m=read();
    for(int i = 1,x,y;i<=m;i++){
        x=read(),y=read();
        g[x][y]=!g[x][y];
        update(1,1,n,x);
        cout<<tr[1].b<<" "<<tr[1].w<<endl;
    }
    return 0;
}