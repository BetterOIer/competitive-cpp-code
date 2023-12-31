#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
inline long long read(){long long x=0,f=1;char c=getchar();for(;!isdigit(c);c=getchar())if(c=='-')f=-1;for(;isdigit(c);c=getchar())x=(x<<3)+(x<<1)+(c^48);return x*f;}
long long n,m,q;
struct node{long long to;long long val;};
vector<node>ro[100005];
long long sup[100005];
bool vis[100005];
long long dfs(long long pos,int v){
    long long ans=0;
    vis[pos]=true;
    for(auto i:ro[pos]){
        if(vis[i.to]||i.val>v)continue;
        ans+=dfs(i.to,v);
    }
    ans+=sup[pos];
    return ans;
}
void solv(long long x,long long k){
    long long nowVal=k+sup[x];
    while(true){
        memset(vis,0,sizeof vis);
        int nn=dfs(x,nowVal)+k;
        if(nn==nowVal)break;
        nowVal=nn;
    }
    cout<<nowVal<<endl;
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
/*     sort(edge.begin(),edge.end()); */
    for(long long i = 1,x,k;i<=q;i++){
        x=read(),k=read();
        solv(x,k);
    }
    return 0;
}