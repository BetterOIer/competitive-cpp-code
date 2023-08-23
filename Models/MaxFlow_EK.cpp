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
#include<cstring>
#include<queue>
using namespace std;
inline int read(){int x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
struct node{
    int to;
    int idx;
};
vector<node>ro[202];
int n,m,s,t,idx=1;
long long lim[10005],val[10005];
pair<int,int> pre[206];
bool bfs(){
    memset(lim,0,sizeof lim);
    queue<int>q;
    q.push(s);lim[s]=1e9;
    while(q.size()){
        int now = q.front();q.pop();
        for(node to:ro[now]){
            if(lim[to.to]==0 && val[to.idx]){
                lim[to.to]=min(lim[now],val[to.idx]);
                pre[to.to]=make_pair(now,to.idx);
                q.push(to.to);
                if(to.to==t) return true;
            }
        }
    }
    return false;
}
long long EK(){
    long long flow = 0;
    while(bfs()){
        long long pre_po=t;
        while(pre_po!=s){
            long long pre_li = pre[pre_po].second;
            val[pre_li]-=lim[t];
            val[pre_li^1]+=lim[t];
            pre_po = pre[pre_po].first;
        }
        flow+=lim[t];
    }
    return flow;
}
int main(){
    n=read(),m=read(),s=read(),t=read();
    for(int i = 1,u,v,w;i<=m;i++){
        u=read(),v=read(),w=read();
        ro[u].push_back((node){v,++idx}),val[idx]=w;
        ro[v].push_back((node){u,++idx}),val[idx]=0;
    }
    cout<<EK()<<endl;
    return 0;
}