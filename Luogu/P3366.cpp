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
#include<algorithm>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m;
/* struct node{
    int to;
    int val;
};vector<node>ro[5005]; */
struct EDGE{
    int a,b;
    int val;
};vector<EDGE>edge;
int fa[5005];
bool operator < (const EDGE a,const EDGE b){
    return a.val<b.val;
}
int find(int pos){
    if(fa[pos]==pos)return pos;
    return fa[pos]=find(fa[pos]);
}
int main(){
    n=read(),m=read();
    for(int i = 1,u,v,w;i<=m;i++){
        u=read(),v=read(),w=read();
        edge.push_back((EDGE){u,v,w});
    }
    sort(edge.begin(),edge.end());
    int ans=0;
    for(int i = 1;i<=n;i++)fa[i]=i;
    for(EDGE i:edge){
        if(find(i.a)!=find(i.b)){
            fa[find(i.a)]=find(i.b);
            ans+=i.val;
        }
    }
    for(int i = 1;i<n;i++){
        if(find(i)!=find(i+1))return cout<<"orz",0;
    }
    cout<<ans;
    return 0;
}