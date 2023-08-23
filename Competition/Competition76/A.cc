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
#include<queue>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
map<int,int>tim;
map<int,bool>inque;
struct cmp{
    bool operator()(pair<int,int> a,pair<int,int> b){
        if(a.first!=b.first)return a.first<b.first;
        else return a.second>b.second;
    }
};
priority_queue<pair<int,int>,vector<pair<int,int> >,cmp>q;
int n,m,x,y;
int a[100005];
int main(){
    n=read(),m=read();
    for(int i=1;i<=n;i++){
        a[i]=read();
        tim[a[i]]++;
    }
    for(int i=1;i<=n;i++){
        if(!inque[a[i]])q.push({tim[a[i]],a[i]}),inque[a[i]]=1;
    }
    while(m--){
        x=read(),y=read();
        tim[a[x]]--;
        q.push({tim[a[x]],a[x]});
        a[x]=y;
        tim[a[x]]++;
        q.push({tim[a[x]],a[x]});
        pair<int,int> t=q.top();
        int fi=t.first;
        int se=t.second;
        while(tim[se]!=fi){
            q.pop();
            t=q.top();           
            fi=t.first;
            se=t.second;
        }        
        cout<<se<<"\n";
    }
}