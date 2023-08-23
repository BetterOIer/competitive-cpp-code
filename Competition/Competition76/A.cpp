/*=================================================
* Le vent se lève, il faut tenter de vivre!
* Author: Better_OIer Zyx
* 起风了，唯有努力生存！
* Blog: https://betteroier.site:1000
* FileStation: https://betteroier.site:1005
* OnlineJudge: http://betteroier.site:8888
=================================================*/
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
int n,m,idx=0;
int a[100005],b[100005];
map<int,int>M;
struct node{
    int a;
    int b;
}tmp[100005];
bool operator < (node a, node b){
    if(a.b==b.b)return a.a<b.a;
    return a.b>b.b;
}
int main(){
    n=read(),m=read();
    for(int i = 1;i<=n;i++){
        a[i]=read();
    }
    for(int i = 1,x,y;i<=m;i++){
        x=read(),y=read();
        a[x]=y;M.clear();idx=0;
        for(int i = 1;i<=n;i++){
            if(!M[a[i]])M[a[i]]=0;
            M[a[i]]++;
        }
        for(auto& i:M){
            tmp[++idx].a=i.first;
            tmp[idx].b=i.second;
        }
        sort(tmp+1,tmp+idx+1);
        cout<<tmp[1].a<<endl;
    }
    return 0;
}