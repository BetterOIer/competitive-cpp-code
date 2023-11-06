#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,m,l=1,r=-1;
struct node{
    long long to;
    long long val;
};
vector<node>ro[300005];
long long dis[300005];
bool vis[300005];
bool vaild(long long val){
    queue<long long>Q;
    memset(vis,0,sizeof vis);
    Q.push(1);dis[1]=0;vis[1]=true;
    while(Q.size()){
        long long now = Q.front();Q.pop();
        for(node to:ro[now]){
            if(vis[to.to])continue;
            if((dis[now]+1)*to.val<=val){
                if(to.to==n) return true;
                vis[to.to]=true;Q.push(to.to);
                dis[to.to]=dis[now]+1;
            }
        }
    }
    return false;
}
int main(){
    #ifndef LOCAL
    freopen("elegans.in","r",stdin);
    freopen("elegans.out","w",stdout);
    #endif
    n=read(),m=read();
    for(long long i = 1,u,v,w;i<=m;i++){
        u=read(),v=read(),w=read();
        ro[u].push_back((node){v,w});r = max(w,r);
    }
    r = (r+1)*m+1;
    while(l<r){
        long long mid = (l+r)>>1;
        if(vaild(mid))r = mid;
        else l = mid+1;
    }cout<<l;
    return 0;
}