#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,m,q;
struct node{long long to;long long val;};
vector<node>ro[100005];
long long sup[100005];
long long vis[100005],tot=0;
bool ter[100005];
struct Qnode{long long pos;long long val;};
queue<Qnode>Q;
void bfs(long long x,long long k){
    memset(vis,0,sizeof vis);
    long long ans=0;
    Q.push((Qnode){x,k});
    while(Q.size()){
        Qnode now = Q.front();Q.pop();
        if(!vis[now.pos])now.val+=sup[now.pos],vis[now.pos]=now.val;
        else if(now.val==vis[now.pos]){ter[now.pos]=true;tot++;if(tot==n)break;continue;}
        vis[now.pos]=max(vis[now.pos],now.val);
        ans=max(ans,now.val);
        for(node i:ro[now.pos]){
            if(now.val>=i.val&&!ter[i.to])Q.push((Qnode){i.to,now.val});
        }
    }
    while(Q.size())Q.pop();
    cout<<ans<<endl;
}
int main(){
    #ifndef LOCAL
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    #else
    freopen("ex_travel2.in","r",stdin);
    freopen("ex_travel2.res","w",stdout);
    #endif
    n=read(),m=read(),q=read();
    for(long long i = 1;i<=n;i++){
        sup[i]=read();
    }
    for(long long i = 1,u,v,w;i<=m;i++){
        u=read(),v=read(),w=read();
        ro[u].push_back((node){v,w});
        ro[v].push_back((node){u,w});
    }
    for(long long i = 1,x,k;i<=q;i++){
        x=read(),k=read();
        bfs(x,k);
    }
    return 0;
}