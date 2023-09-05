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
int h,w,n,dis[3003];
struct node{
    int x;
    int y;
};
bool operator < (node a, node b){
    if(a.x==b.x)return a.y<b.y;
    return a.x<b.x;
}
node po[3003];
int C(int a,int b){

}
int main(){
    h=read(),w=read(),n=read();
    for(int i = 1;i<=n;i++){
        po[i].x=read(),po[i].y=read();
    }
    po[++n].x=h,po[n].y=w;
    sort(po+1,po+n+1);
    for(int i = 1;i<=n;i++) dis[i]=C(po[i].x+po[i].y-2,po[i].x-1);
    
    return 0;
}